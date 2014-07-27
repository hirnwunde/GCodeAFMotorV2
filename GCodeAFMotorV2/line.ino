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
  
  long dx=newx-px;
  long dy=newy-py;
  
  int dirx=dx>0?1:-1;
  int diry=dy>0?-1:1; // because the motors are mounted in opposite directions
  
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

  px=newx;
  py=newy;
}
