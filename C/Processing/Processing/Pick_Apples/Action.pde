int x = 500;
int y = 500;
float apple_x = 150;
float apple_y = 300;
float bomb_x = 500;
float bomb_y = 300;
PFont font;
int score = 0;
int score_before=0;
long time_start; 
long time_end;
int show_times=0;
int game_time = 60;
PImage tree;
PImage apple;
PImage hand;
PImage bomb;
 
void gameUiInit(){
  tree = loadImage("tree.jpg");
  apple = loadImage("apple.jpg");
  hand = loadImage("hand.jpg");
  bomb = loadImage("bomb.jpg");
  font = loadFont("SitkaDisplay-48.vlw");
  time_start = millis();
}
void move(){
  if(keyPressed) {
    if(key==CODED){
      if(keyCode == LEFT && x != 0) {
        x -= 10;
      }
      if(keyCode == RIGHT && x != 600) {
        x += 10;
      }
      if(keyCode == UP && y != 0) {
        y -= 10;
      }
      if(keyCode == DOWN && y != 600) {
        y += 10;
      }
    }
    else { 
      if(key == ' ') {
        game_time = 60;
        score = 0;
      
      }
      if (key == '\n' || key == '\r')
      {
        link("http://www.freenove.com");
      } 
    }
  }
}

void apple() {
  apple_x = random(50,550);
  apple_y = random(50,400);
}

void bomb() {
  bomb_x = random(50,550);
  bomb_y = random(50,400);
}

void font() {
  textFont(font);
  fill(0);
  text("Score:",60,40);
  text(score,170,40);
  text("Time:",460,40);
  text(game_time,550,40);
}

void over() {    
  time_end = millis();
  if((time_end-time_start>1000)&&(game_time > 0)){
    time_start = time_end;
    game_time --;
  }
  if(game_time <= 0) {
    fill(20,40,240);
    noStroke();
    rect(100,400,450,85);
    textFont(font);
    fill(0);
    String s = "your score is";
    text(s,240,440);
    text(score,450,440);
    //stop();
  }  
}

void RunGame(){
    frameRate(20);
    background(tree);
    if(score>score_before){
      fill(0,255,0);
      text("+20",300,40);
      show_times++;
      if(show_times>=10){
        score_before=score;
        show_times=0;
      }
    }
    if(score_before>score){
      fill(255,0,255);
      text("-20",300,40);
      show_times++;
      if(show_times>=10){
        score_before=score;
        show_times=0;
      }
    } 
    if(score_before==score){
      fill(255,255,255);
      text("    ",300,40);
    }
    move();
    if(game_time>0){
      image(hand,x,y);
      image(apple,apple_x,apple_y);
      image(bomb,bomb_x,bomb_y);
      fill(0);
      text("www.freenove.com", width / 2, height - 20);
    }
    over();
    font();
    if(sqrt((apple_x - x)*(apple_x - x)+(apple_y - y)*(apple_y - y)) < 25) {
      apple();
      bomb();
      score += 20;
    }
    if(sqrt((bomb_x - x)*(bomb_x - x)+(bomb_y - y)*(bomb_y - y)) < 25) {
      apple();
      bomb();
      score -= 20;
    }
}