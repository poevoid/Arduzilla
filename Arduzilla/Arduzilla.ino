#include <Arduboy2.h>
#include <ArduboyTones.h>
Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);
Sprites sprites; 

#include "arrays.h"
#include "vars.h"



//////////////////////////// MAIN LOOP START ///////////////////////////////

void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.setFrameRate(30);
  sound.volumeMode(VOLUME_ALWAYS_NORMAL);
  setHomesHP();
  setLargeBuildingsHP();
  setSmallBuildingsHP();
}

void loop() {
  // Update
  if(!arduboy.nextFrame()) {
    return;
  }
  arduboy.pollButtons();
  arduboy.clear();
  gameloop();
}
