import picoweb
import utime
import camera
import gc
import network

SSID = "********"         # Enter your WiFi name
PASSWORD = "********"     # Enter your WiFi password

def camera_init():
    camera.deinit()
    utime.sleep_ms(100)
    
    try:
        success = camera.init(0, 
            d0=4, d1=5, d2=18, d3=19, d4=36, d5=39, d6=34, d7=35,
            format=camera.RGB565,       
            framesize=camera.FRAME_QVGA,
            xclk_freq=camera.XCLK_10MHz,
            href=23, vsync=25, reset=-1, pwdn=-1,
            sioc=27, siod=26, xclk=21, pclk=22,
            fb_location=camera.PSRAM)   
        
        if success:
            camera.brightness(1)
            camera.quality(10)
            camera.mirror(1)
            camera.flip(1)
            print("Camera Init Success")
            return True
    except Exception as e:
        print("Camera Error:", e)
    return False

def wifi_connect():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    if not wlan.isconnected():
        wlan.connect(SSID, PASSWORD)
        while not wlan.isconnected():
            utime.sleep(0.5)
    print('IP:', wlan.ifconfig()[0])

index_web = """
<html>
  <body>
    <h1>Video Streaming Demonstration</h1>
    <canvas id="cv" width="320" height="240" style="transform:rotate(180deg); background:#000;"></canvas>
    <script>
      const cv = document.getElementById('cv');
      const ctx = cv.getContext('2d');
      const w = 320, h = 240;
      const size = w * h * 2;

      async function stream() {
        const res = await fetch('/video');
        const reader = res.body.getReader();
        let buf = new Uint8Array(0);

        while (true) {
          const {done, value} = await reader.read();
          if (done) break;

          let tmp = new Uint8Array(buf.length + value.length);
          tmp.set(buf); tmp.set(value, buf.length);
          buf = tmp;

          while (buf.length >= size) {
            const frame = buf.slice(0, size);
            buf = buf.slice(size);
            const img = ctx.createImageData(w, h);
            for (let i=0; i<size; i+=2) {
              const p = (frame[i]<<8) | frame[i+1];
              const idx = (i>>1)<<2;
              img.data[idx]   = ((p>>11) & 0x1F) << 3; // R
              img.data[idx+1] = ((p>>5) & 0x3F) << 2;  // G
              img.data[idx+2] = (p & 0x1F) << 3;       // B
              img.data[idx+3] = 255;
            }
            ctx.putImageData(img, 0, 0);
          }
        }
      }
      stream();
    </script>
  </body>
</html>
"""

def video(req, resp):
    yield from resp.awrite("HTTP/1.1 200 OK\r\nContent-Type: application/octet-stream\r\n\r\n")
    while True:
        buf = camera.capture()
        if buf:
            try:
                yield from resp.awrite(buf)
                del buf
                gc.collect() 
            except:
                break

ROUTES = [("/", lambda r, s: (yield from s.awrite("HTTP/1.1 200 OK\r\n\r\n"+index_web))), ("/video", video)]
wifi_connect()
if camera_init():
    picoweb.WebApp(__name__, ROUTES).run(debug=False, port=80, host="0.0.0.0")