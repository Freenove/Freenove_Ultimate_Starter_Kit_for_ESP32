/*
 ******************************************************************************
 * Sketch  Tetris
 * Author  Zhentao Lin @ Freenove (http://www.freenove.com)
 * Date    2020/7/11
 ******************************************************************************
 * Brief
 *   This sketch is used to play Tetris game 
 ******************************************************************************
 * Copyright
 *   Copyright © Freenove (http://www.freenove.com)
 * License
 *   Creative Commons Attribution ShareAlike 3.0 
 *   (http://creativecommons.org/licenses/by-sa/3.0/legalcode)
 ******************************************************************************
 */
static final int w = 10; // 4
static final int h = 25; // 60
static final int framesInSecond = 30;
static float gameInitSpeed = 10;
static float gameSpeed = 10;
static final int BlockScale = 15;
static final int sizeWidth = w*BlockScale+100;
static final int sizeHeight = h*BlockScale;

boolean isPaused = false;
boolean keyAllow = true;
float updatingThreshold = 0;
Game game;
SerialDevice serialDevice = new SerialDevice(this);

float recalculateUpdatingThreshold(float threshold) {
  return threshold + 1;
}
void settings() {
  size(sizeWidth, sizeHeight);
}
void setup() {
  game = new Game(w, h);
  generateRandomBlock(game);
  frameRate(framesInSecond);
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
  int digitalValue;
  digitalValue = serialDevice.requestDigital();
  if(digitalValue!=-1){
    dealData(digitalValue);
  }
  Tetris_run();
}

void Tetris_run()
{
  //keypadDetect();
  background(102); 
  Game newGame = game;
  
  updatingThreshold = recalculateUpdatingThreshold(updatingThreshold);
  if (updatingThreshold > gameSpeed) {
    if (isGameOver(newGame)) {
    } else if (isPaused) {
    } else {
      newGame = updateGameState(game);
    }
    updatingThreshold = 0;
  }
  drawGameState(newGame);
  if (!isGameOver(newGame)&& (isPaused)) {  //pause
    textSize(40);
    fill(0);
    text("Pause", BlockScale*2, 150);
    keyAllow = false;
  } else if (isGameOver(newGame)&& (isPaused)) {    //restart game
    game = new Game(w, h);
    generateRandomBlock(game);
    isPaused = false;
    keyAllow = false;
  } else if (isGameOver(newGame)) {    //game over
    textSize(40);
    fill(0);
    text("Game \nOver", BlockScale*2, 150);
    keyAllow = false;
  } else {        //playing
    keyAllow = true;
  }
  
  //level,score information
  pushMatrix();
  translate(w*BlockScale, 0);
  fill(255);
  textSize(20);
  text("Level\n"+game.level, 10, BlockScale*7);
  text("Scores\n"+game.score, 10, BlockScale*11);
  textSize(12);
  text("Freenove.com", 10, sizeHeight-30);
  drawNextBlock(game.nextBlock, BlockScale*2, BlockScale*1);
  popMatrix();
}
void keyPressed() {
  if (key == CODED) {
    if (keyAllow) {
      switch (keyCode) {
      case LEFT:  
        moveBlock(game, MoveLeft);  
        break;
      case RIGHT: 
        moveBlock(game, MoveRight); 
        break;
      case DOWN:  
        makeBlockFall(game);        
        break;
      case UP:    
        rotateBlock(game);          
        break;
      }
    }
  } else if (key == ' ') { // SPACE
    isPaused =! isPaused;
  }
}

void dealData(int digital){
    if(digital == 1) {//左
      moveBlock(game, MoveLeft); 
      delay(250);
    }
    if(digital == 2) {//右
      moveBlock(game, MoveRight); 
      delay(250);
    }
    if(digital == 3) {//下
      makeBlockFall(game); 
    }
    if(digital == 4) {//上
      rotateBlock(game);  
      delay(200);
    }
}