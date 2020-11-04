
// MISC FUNCTIONS //

int getNumberLength(int num) {
  int len = 1;
  while(num /= 10)
    len++;
  return len;
}

void printEachDigit(int num) {
  if (num >= 10)
    printEachDigit(num / 10);

  int digit = num % 10;
  arduboy.println(digit);
}

void drawEachDigit(int num, int x, int y) {
  if (num >= 10)
    drawEachDigit(num / 10, x-5, y);

  int digit = num % 10;
  sprites.drawExternalMask(x, y, numbers_img, numbers_mask, digit, digit);
}

void resetLED() {
  arduboy.setRGBled(0, 0, 0);
}

bool dirPressed() {
  if (arduboy.pressed(LEFT_BUTTON) || arduboy.pressed(RIGHT_BUTTON) ||
      arduboy.pressed(UP_BUTTON)   || arduboy.pressed(DOWN_BUTTON)) {
    return true;
  }
  return false;
}

void limitXAtWorldBounds(float &x, float &dx, int w) {
  float world_right = WORLD_WIDTH*TILE_SIZE;
  if (x <= 0.0) {
    x = 0.0;
    dx = 0.0;
  } else if (x+w >= world_right) {
    x = world_right-w;
    dx = 0.0;
  }
}

void limitYAtWorldBounds(float &y, float &dy, int h) {
  float world_bottom = WORLD_HEIGHT*TILE_SIZE;
  if (y <= 0.0) {
    y = 0.0;
    dy = 0.0;
  } else if (y+h >= world_bottom) {
    y = world_bottom-h;
    dy = 0.0;
  }
}

float minf(float a, float b) {
  return (a < b) ? a : b;
}

float maxf(float a, float b) {
  return (a > b) ? a : b;
}

float lerp(float s, float e, float p) {
  return (s + p*(e - s));
}

void gameloop() {
  switch (gamestate) {
    case TITLE:
    titlescreen();
    
    break;

    case GAME:
    gameplay();
    break;

    case WIN:
    winscreen();
     
    break;

    case LOSE:
    losescreen();
    break;

    case HIGHSCORE:
    highscorescreen();
    if (arduboy.justPressed(A_BUTTON)) {
      //reset();
      gamestate = TITLE;
    }
    break;
  }
}

void gameplay() {
  arduboy.clear();
  sound.tones(theme);
  if (score == 185) {
    sound.noTone();
    arduboy.clear();
    gamestate = WIN;
    }
  ///instant lose for dev
  if (arduboy.pressed(A_BUTTON)) {
    sound.noTone();
    arduboy.clear();
    gamestate = WIN;
  }
  while(sound.playing()) {
  // RGB LED CONTROL
  resetLED();

  // UPDATE CAMERA
  getCameraOffset();
  cameraFollow(dino_x, dino_y);
  limitCamera();

  updateDino();
  updateBuildings();

  // Draw
  
    arduboy.fillScreen();
    drawWorldMap();
    drawBuildings();
    drawDino();
    drawScore();
  arduboy.display();
  }
  
    
  
}

void titlescreen() {
  reset();
  arduboy.clear();
  sound.tones(theme);
  while(sound.playing()) {
  arduboy.setCursor(0, 0);
  arduboy.print("Arduzilla\n Press B to start!");
  arduboy.display();
  if (arduboy.pressed(B_BUTTON)) {
    sound.noTone();
      gamestate++;
    }
  }
}
void losescreen() {
  arduboy.clear();
  sound.tones(lose);
  while(sound.playing()) {
  arduboy.setCursor(0, 0);
  arduboy.print("You lose");
  arduboy.display();
  }
}
void winscreen() {
  arduboy.clear();
  sound.tones(win);
  while(sound.playing()) {
  arduboy.setCursor(0, 0);
  arduboy.print("Winner!!\n Hold A to return to title screen");
  arduboy.display();
  if (arduboy.justPressed(A_BUTTON)) {
      sound.noTone();
      gamestate = TITLE;
    }
  }
}
void reset() {
  setHomesHP();
  setLargeBuildingsHP();
  setSmallBuildingsHP();
dino_x            = 24;
dino_y            = 24;
dino_dx           = 0.0;
dino_dy           = 0.0;
dino_dir          = 0;
dino_walk_frame   = 0;
dino_attack_frame = 0;
dino_frame        = 0;

dino_attacking    = false;

cam_x     = 0.0;
cam_y     = 0.0;
cam_x_off = 0;
cam_y_off = 0;

fire_frame = 0;

score = 0;

}
void highscorescreen() {
  arduboy.clear();
  arduboy.setCursor(0, 0);
  arduboy.print("High:");
  arduboy.display();
}
