/**
* Uses bresenham's line algorithm to move both motors
* @input newx the destination x position
* @input newy the destination y position
**/
void line(float newx,float newy) {
  
  long dx=newx-px;
  long dy=newy-py;
  
  int dirx=dx>0?1:-1;
  /*
  if (dx > 0) {
    int dirx = 1;
  } else {
    int dirx = -1;
  }
  */
  
  int diry=dy>0?-1:1; // because the motors are mounted in opposite directions
  /*
  if (dy > 0) {
    int diry = -1;
  } else {
	int diry = 1;
  }
  */
  
  dx=abs(dx);
  dy=abs(dy);

  long i;
  long over=0;

#ifdef VERBOSE
  Serial.println(F("Start >"));
#endif

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

#ifdef VERBOSE
  Serial.println(F("< Done."));
#endif

  px=newx;
  py=newy;
}
