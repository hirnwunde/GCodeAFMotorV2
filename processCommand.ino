/**
* Read the input buffer and find any recognized commands. One G or M command per line.
*/
void processCommand() {
  int cmd = parsenumber('G',-1);
  switch(cmd) {
  case 0: // move linear
  case 1: // move linear
    feedrate(parsenumber('F',fr));
    line( parsenumber('X',(mode_abs?px:0)) + (mode_abs?0:px),
          parsenumber('Y',(mode_abs?py:0)) + (mode_abs?0:py) );
    break;
  case 4: pause(parsenumber('P',0)*1000); break; // dwell
  case 28: homecycle(); break; // move home (X/Y 0)
  case 90: mode_abs=1; break; // absolute mode
  case 91: mode_abs=0; break; // relative mode
  case 92: // set logical position
    position( parsenumber('X',0),
              parsenumber('Y',0) );
    break;
  default: break;
  }

  cmd = parsenumber('M',-1);
  switch(cmd) {
  case 18: // disable motors
    release();
    break;
  case 100: help(); break;
  case 114: where(); break;
  default: break;
  }
}


