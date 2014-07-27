/**
 * Read the input buffer and find any recognized commands. One G or M command per line.
 */
void processCommand() {
  int cmd = parsenumber('G',-1);
  switch(cmd) {
  case 0: // move linear
  case 1: // move linear
    feedrate(parsenumber('F',fr));
    int StepsToMoveX, StepsToMoveY;
    StepsToMoveX = parsenumber('X', px) * StepsPerUnit;
    StepsToMoveY = parsenumber('Y', py) * StepsPerUnit;
    line( StepsToMoveX, StepsToMoveY );
    break;
  case 4: 
    pause(parsenumber('P',0)*1000); 
    break; // dwell
  case 28: 
    homecycle(); 
    break; // move to and set home (X/Y 0)
  case 90: 
    mode_abs=1; 
    break; // absolute mode
  case 91: 
    mode_abs=0; 
    break; // relative mode
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
  
  if (hwCNC == 1) {
    cmd = parsenumber('V',-1);
    switch(cmd) {

    case 1: pcinterface("CONFIG"); break;
    case 2: pcinterface("POSITION"); break;

    case 121: Serial.println("V121 - X+"); break;
    case 122: Serial.println("V122 - X-"); break;
    case 123: Serial.println("V123 - Y+"); break;
    case 124: Serial.println("V124 - Y-"); break;
    case 125: Serial.println("V125 - X+++"); break;
    case 126: Serial.println("V126 - X---"); break;
    case 127: Serial.println("V127 - Y+++"); break;
    case 128: Serial.println("V128 - Y---"); break;

    default:
      break;
    }
  }
}



