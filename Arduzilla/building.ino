
// BUILDING FUNCTIONS //
void setHomesHP() {
  for (int i=0; i<HOME_COUNT; ++i) {
    homes_hp[i] = 3;
  }
}
void setLargeBuildingsHP() {
  for(int i=0; i<LARGE_BUILDING_COUNT; ++i) {
    large_buildings_hp[i] = 7;
  }
}
void setSmallBuildingsHP() {
  for(int i=0; i<SMALL_BUILDING_COUNT; i++) {
    small_buildings_hp[i] = 4;
  }
}
bool HomeAttacked(int x, int y) {
  int offset = 2;
  Rect home_rect {x+(int)cam_x-offset, y+(int)cam_y-offset, 5+(offset*2), 5+(offset*2)};
  Point fire_point;
  fire_point.y = (int)dino_y+(int)cam_y+6;
  
  switch(dino_dir) {
    case 0:
      // check collision point right of dinosaur
      fire_point.x = (int)dino_x+(int)cam_x+32;
      
      if (arduboy.collide(fire_point, home_rect)) {
        return true;
      }
      break;
      
    case 2:
      // check collision point left of dionsaur
      fire_point.x = (int)dino_x+(int)cam_x-4;
      
      if (arduboy.collide(fire_point, home_rect)) {
        return true;
      }
      break;
  }
  return false;
} 

bool largeBuildingAttacked(int x, int y) {
  int offset = 2;
  Rect Lbuilding_rect {x+(int)cam_x-offset, y+(int)cam_y-offset, 13+(offset*2), 14+(offset*2)};
  Point fire_point;
  fire_point.y = (int)dino_y+(int)cam_y+6;
  
  switch(dino_dir) {
    case 0:
      // check collision point right of dinosaur
      fire_point.x = (int)dino_x+(int)cam_x+32;
      
      if (arduboy.collide(fire_point, Lbuilding_rect)) {
        return true;
      }
      break;
      
    case 2:
      // check collision point left of dionsaur
      fire_point.x = (int)dino_x+(int)cam_x-4;
      
      if (arduboy.collide(fire_point, Lbuilding_rect)) {
        return true;
      }
      break;
  }
  return false;
} 

bool smallBuildingAttacked(int x, int y) {
  int offset = 2;
  Rect building_rect {x+(int)cam_x-offset, y+(int)cam_y-offset, 8+(offset*2), 8+(offset*2)};
  Point fire_point;
  fire_point.y = (int)dino_y+(int)cam_y+6;
  
  switch(dino_dir) {
    case 0:
      // check collision point right of dinosaur
      fire_point.x = (int)dino_x+(int)cam_x+32;
      
      if (arduboy.collide(fire_point, building_rect)) {
        return true;
      }
      break;
      
    case 2:
      // check collision point left of dionsaur
      fire_point.x = (int)dino_x+(int)cam_x-4;
      
      if (arduboy.collide(fire_point, building_rect)) {
        return true;
      }
      break;
  }
  return false;
}
void damageHome(int index) {
  if (homes_hp[index] > 0) {
    if (arduboy.everyXFrames(30)) {
      homes_hp[index]--;
      if (homes_hp[index] == 0) {
        destroyBuilding(5);
      }
    }
  }
}
void damageLargeBuilding(int index) {
  if (large_buildings_hp[index] > 0) {
    if (arduboy.everyXFrames(30)) {
      large_buildings_hp[index]--;
      if (large_buildings_hp[index] == 0) {
        destroyBuilding(15);
      }
    }
  }
}
void damageSmallBuilding(int index) {
  if (small_buildings_hp[index] > 0) {
    if (arduboy.everyXFrames(30)) {
      small_buildings_hp[index]--;
      if (small_buildings_hp[index] == 0) {
        destroyBuilding(10);
      }
    }
  }
}

void destroyBuilding(int points) {
  arduboy.setRGBled(120, 0, 0);
  gainPoints(points);
}

void updateBuildings() {
  //UPDATE HOMES
  for(int i=0; i<HOME_COUNT; ++i) {
    int x = homes_pos[i][0];
    int y = homes_pos[i][1];

    if (dino_attacking) {
      if (HomeAttacked((int)(x*TILE_SIZE), (int)(y*TILE_SIZE))) {
        damageHome(i);
      }
    }
    
  }
  // UPDATE SMALL BUILDINGS
  for(int i=0; i<SMALL_BUILDING_COUNT; i++) {
    int x = small_buildings_pos[i][0];
    int y = small_buildings_pos[i][1];

    if (dino_attacking) {
      if (smallBuildingAttacked((int)(x*TILE_SIZE), (int)(y*TILE_SIZE))) {
        damageSmallBuilding(i);
      }
    }
    
  }
  //UPDATE LARGE BUILDINGS
  for(int i=0; i<LARGE_BUILDING_COUNT; ++i) {
    int x = large_buildings_pos[i][0];
    int y = large_buildings_pos[i][1];

    if (dino_attacking) {
      if (largeBuildingAttacked((int)(x*TILE_SIZE), (int)(y*TILE_SIZE))) {
        damageLargeBuilding(i);
      }
    }
    
  }
}

void drawBuildings() {
  for(int i=0; i<HOME_COUNT; ++i) {
    int x = homes_pos[i][0];
    int y = homes_pos[i][1];
    //arduboy.println(small_buildings_pos[0][0]);
    //arduboy.println(small_buildings_pos[0][1]);
    if (homes_hp[i] > 0) {
      arduboy.drawBitmap((x*TILE_SIZE) + cam_x, (y*TILE_SIZE) + cam_y, home_img, 5, 5, BLACK);
    } else {
      arduboy.drawBitmap((x*TILE_SIZE) + cam_x, (y*TILE_SIZE) + cam_y, home_wreck_img, 5, 5, BLACK);
    }
  }
  for(int i=0; i<SMALL_BUILDING_COUNT; i++) {
    int x = small_buildings_pos[i][0];
    int y = small_buildings_pos[i][1];
    //arduboy.println(small_buildings_pos[0][0]);
    //arduboy.println(small_buildings_pos[0][1]);
    if (small_buildings_hp[i] > 0) {
      arduboy.drawBitmap((x*TILE_SIZE) + cam_x, (y*TILE_SIZE) + cam_y, building_small_img, 8, 8, BLACK);
    } else {
      arduboy.drawBitmap((x*TILE_SIZE) + cam_x, (y*TILE_SIZE) + cam_y, building_small_wreck_img, 8, 8, BLACK);
    }
  }
  for(int i=0; i<LARGE_BUILDING_COUNT; i++) {
    int x = large_buildings_pos[i][0];
    int y = large_buildings_pos[i][1];
    if (large_buildings_hp[i] > 0) {
      arduboy.drawBitmap((x*TILE_SIZE) + cam_x, (y*TILE_SIZE) + cam_y, building_large_img, 13, 14, BLACK);
    } else {
      arduboy.drawBitmap((x*TILE_SIZE) + cam_x, (y*TILE_SIZE) + cam_y, building_large_wreck_img, 13, 14, BLACK);
    }
  }
}
