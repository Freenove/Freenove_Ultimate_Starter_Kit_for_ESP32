/*
 ******************************************************************************
 * Sketch  Pong Game
 * Author  Zhentao Lin @ Freenove (http://www.freenove.com)
 * Date    2020/7/11
 ******************************************************************************
 * Brief
 *   This sketch is used to play pong game through communicate to an Arduino 
 *   board or other micro controller.
 *   It will automatically detect and connect to a device (serial port) which 
 *   use the same trans format.
 ******************************************************************************
 * Copyright
 *   Copyright © Freenove (http://www.freenove.com)
 * License
 *   Creative Commons Attribution ShareAlike 3.0 
 *   (http://creativecommons.org/licenses/by-sa/3.0/legalcode)
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
int winScore = 3;
float acceleration = 0.5;
float deviate = 1;
/* Private variables ---------------------------------------------------------*/
SerialDevice serialDevice = new SerialDevice(this);

Ball ball;
Paddle lPaddle, rPaddle;
int gameState = GameState.WELCOME;
int lScore, rScore;

void setup() {
  size(1280, 720, P3D);
  background(102);
  textAlign(CENTER, CENTER);
  textSize(64);
  text("Starting...", width / 2, (height - 40) / 2);
  textSize(16);
  text("www.freenove.com", width / 2, height - 20);
  frameRate(1000 / 40);

  ball = new Ball(16);
  lPaddle = new Paddle(new Size(16, 160), 20);
  rPaddle = new Paddle(new Size(16, 160), width - 20);
}

void draw() {
  if (!serialDevice.active())
  {
    if (!serialDevice.start())
    {
      delay(1000);
      return;
    }
  }

  int[] analogs = new int[2];
  analogs = serialDevice.requestAnalogs(2);
  if (analogs != null)
  {
    lPaddle.position.y = analogs[0] * height /1023;
    rPaddle.position.y = analogs[1] * height /1023;
  }

  background(102);
  if (gameState == GameState.WELCOME)
  {
    showGUI();
    lPaddle.display();
    rPaddle.display();
    showInfo("Pong Game");
  } 
  else if (gameState == GameState.PLAYING)
  {  
    ball.updata();
    calculateGame();
    showGUI();
    ball.display();
    lPaddle.display();
    rPaddle.display();
  } 
  else if (gameState == GameState.PLAYER1WIN)
  {
    showGUI();
    lPaddle.display();
    rPaddle.display();
    showInfo("Player 1 win!");
  } 
  else if (gameState == GameState.PLAYER2WIN)
  {
    showGUI();
    lPaddle.display();
    rPaddle.display();
    showInfo("Player 2 win!");
  }
}

void showInfo(String info)
{
  rectMode(CENTER);
  stroke(0, 0, 0);
  fill(0, 0, 0, 50);
  rect(width / 2, height / 2, width / 2, height / 3);
  fill(255, 255, 255);
  textSize(24);
  textAlign(CENTER, CENTER);
  text(info, width / 2, height / 2 - 24);
  text("Press Space to start", width / 2, height / 2 + 24);
}

void calculateGame()
{
  if (ball.position.x - ball.radius < lPaddle.position.x + lPaddle.size.width / 2)
  {
    if (ball.position.y < lPaddle.position.y - lPaddle.size.height / 2 - ball.radius||
      ball.position.y > lPaddle.position.y + lPaddle.size.height / 2 + ball.radius)
    {
      rScore++;
      ball.reset();
    } 
    else
    {
      ball.speed.getSpeed();
      ball.speed.speed += acceleration;
      ball.speed.getXYSpeed((ball.position.y - lPaddle.position.y) / (lPaddle.size.height / 2) * deviate);
    }
  }

  if (ball.position.x + ball.radius > rPaddle.position.x - rPaddle.size.width / 2)
  {
    if (ball.position.y < rPaddle.position.y - rPaddle.size.height / 2 - ball.radius||
      ball.position.y > rPaddle.position.y + rPaddle.size.height / 2 + ball.radius)
    {
      lScore++;
      ball.reset();
    } 
    else
    {
      ball.speed.getSpeed();
      ball.speed.speed += acceleration;
      ball.speed.getXYSpeed((ball.position.y - rPaddle.position.y) / (rPaddle.size.height / 2) * deviate);
      ball.speed.x = - ball.speed.x;
    }
  }

  if (lScore == winScore)
    gameState = GameState.PLAYER1WIN;
  if (rScore == winScore)
    gameState = GameState.PLAYER2WIN;
}

void showGUI()
{
  fill(255, 255, 255);
  textSize(16);
  textAlign(CENTER, CENTER);
  text("Press Enter to visit www.freenove.com", width / 4, height - 20);
  text("Press Space to restart game", width * 3 / 4, height - 20);
  text("Player 1: " + lScore, width / 4, 20);
  text("Player 2: " + rScore, width * 3 / 4, 20);

  rectMode(CENTER);
  noStroke();
  fill(144, 144, 144);
  rect(width / 2, height / 2, 4, height);
}

void keyPressed() {
  if (key == '\n' || key == '\r')
  {
    link("http://www.freenove.com");
  } 
  else if (key == ' ')
  {
    lScore = 0;
    rScore = 0;
    ball.reset();
    gameState = GameState.PLAYING;
  }
}