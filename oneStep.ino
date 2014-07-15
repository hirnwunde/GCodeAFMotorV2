/**
* Supports movement with both styles of Motor Shield
* @input newx the destination x position
* @input newy the destination y position
**/
void onestep(int motor,int direction) {
  if(motor==1) {
#ifdef VERBOSE
    Serial.print('X');
#endif
      mX->onestep(direction>0?FORWARD:BACKWARD,INTERLEAVE);
  } else {
#ifdef VERBOSE
    Serial.print('Y');
#endif
      mY->onestep(direction>0?FORWARD:BACKWARD,INTERLEAVE);
  }
}
