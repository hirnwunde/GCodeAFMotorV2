/**
* Uses bresenham's line algorithm to move both motors
* @input newx the destination x position
* @input newy the destination y position
**/
void line(float newx,float newy) {
  
  if (!has_origin) { 
    Serial.println("No origin defined. Please perform a homing.");
    return;
  }
  
  if (digitalRead(LimitSwitchHomeX)) {
    Serial.println("Hardware Limit Switch X Home Reached!");
    return;
  }
  if (digitalRead(LimitSwitchHomeY)) {
    Serial.println("Hardware Limit Switch Y Home Reached!");
    return;
  }
  if (digitalRead(LimitSwitchEndX)) {
    Serial.println("Hardware Limit Switch X End Reached!");
    return;
  }
  if (digitalRead(LimitSwitchEndY)) {
    Serial.println("Hardware Limit Switch Y End Reached!");
    return;
  }
  int dirx, diry;    
  long dx=newx-(px * StepsPerUnit);
  long dy=newy-(py * StepsPerUnit);
  
  if (dx > 0) { dirx = 1; } else { dirx = -1; }
  if (dy > 0) { diry = 1; } else { diry = -1; } // because the motors are mounted in opposite directions
  
  dx=abs(dx);
  dy=abs(dy);

  long i;
  long over=0;

  if (VERBOSE == 1) { Serial.println(F("Start >")); }

  if(dx>dy) {
    for(i=0;i<dx;++i) {
      onestep(1,dirx);
      over+=dy;
      if(over>=dx) {
        over-=dx;
        onestep(2,diry);
      }
      pause(step_delay);
    }
  } else {
    for(i=0;i<dy;++i) {
      onestep(2,diry);
      over+=dx;
      if(over>=dy) {
        over-=dy;
        onestep(1,dirx);
      }
      pause(step_delay);
    }
  }

  if (VERBOSE == 1) { Serial.println(F("< Done.")); }
  if (hwCNC == 1) { Serial.println("LNMVEND"); }
  px = act_pos_x;
  py = act_pos_y;
  if (SendPosAfterMove == 1 && SendPosWhileMove == 0) { sendPos(); }
}
