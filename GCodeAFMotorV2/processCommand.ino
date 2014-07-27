/**
* Read the input buffer and find any recognized commands. One G or M command per line.
*/

void processCommand() {
  int cmd = parsenumber('G',-1);
  switch(cmd) {
  case 0: // move linear
  case 1: // move linear
    feedrate(parsenumber('F',fr));
    line(parsenumber('X',px) * StepsPerUnit, parsenumber('Y',py) * StepsPerUnit);
    break;

  case 4: 
    pause(parsenumber('P',0)*1000); 
    break; // dwell

  case 28: 
    homecycle(); 
    break; // move to and set home (X/Y 0)

  case 92: // set logical position
    position( parsenumber('X',0),
    parsenumber('Y',0) );
    break;

  case 999: // overwrite homing - for testing purpose only!!!
    act_pos_x = 0.0;
    act_pos_y = 0.0;
    has_origin = true;
    Serial.println("WARNING! Machine has NO real origin!! Set X/Y to 0/0 ...");
    break;

  default: 
    break;
  }

  cmd = parsenumber('M',-1);
  switch(cmd) {

  case 18: // release motors
    release();
    break;
  
  case 100: 
    help(); 
    break;
  
  case 114: 
    where(); 
    break;
  
  default: 
    break;
  }
}



