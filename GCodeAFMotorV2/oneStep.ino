/**
* @input newx the destination x position
* @input newy the destination y position
*
* 2014-07-16/10:50 - hirnwunde
*  - convert short notation of if statements to long version
*  - preparations for unit measuring system 
**/
void onestep(int motor,int direction) {
    
  // maybe redundant but better save then sorry
  if (!has_origin) { 
    Serial.println("No origin defined. Please perform a homing.");
    return;
  }
  
  if (act_pos_x >= (DimensionX - (1.0 / StepsPerUnit))) {
    Serial.println("X-Axis on software-end! No movement beyond defined workspace.");
    return;
  }

  if (act_pos_y >= (DimensionY - (1.0 / StepsPerUnit))) {
    Serial.println("Y-Axis on software-end! No movement beyond defined workspace.");
    return;
  }
  
  if(motor==1) {

    if (VERBOSE == 1) { Serial.print('X'); }

    if (direction == 1){
      mX->onestep(FORWARD,INTERLEAVE);
      act_pos_x += (1.0 / StepsPerUnit);
    } else {
      mX->onestep(BACKWARD,INTERLEAVE);
      act_pos_x -= (1.0 / StepsPerUnit);
    }

  } else {

    if (VERBOSE == 1) { Serial.print('Y'); }

    if (direction == 1){
      mY->onestep(FORWARD,INTERLEAVE);
      act_pos_y += (1.0 / StepsPerUnit);
    } else {
      mY->onestep(BACKWARD,INTERLEAVE);
      act_pos_y -= (1.0 / StepsPerUnit);
    }
  }
  
  if (SendPosWhileMove == 1) { 
    Serial.print("POS_TRK-X");
    Serial.print(act_pos_x);
    Serial.print(",Y");
    Serial.println(act_pos_y); 
  }
}
