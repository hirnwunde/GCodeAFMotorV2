void homecycle() {
	
	LimitSwitchHomeX = digitalRead(2);
	LimitSwitchHomeY = digitalRead(4);
	LimitSwitchEndX = digitalRead(7);
	LimitSwitchEndY = digitalRead(8);
        boolean xhome = false; // set to true if X has reached home position
        boolean yhome = false; // set to true if Y has reached home position
	
	//check if X & Y not on home or end limit switches
	if (LimitSwitchHomeX == 1 || LimitSwitchHomeY == 1 ||
	       LimitSwitchEndX == 1 || LimitSwitchEndY == 1) {
	
		Serial.println("Either X or Y are not in a moveable position!");
		release();
		delay(250);
		Serial.println("Motors are released. Now please move X and/or Y from its limit switch.");
		return;
	}
	
        while(LimitSwitchHomeX == 0) { 
	  mX->onestep(BACKWARD,INTERLEAVE);
          Serial.print(".");
          if (LimitSwitchHomeX == 1) {
            xhome = true;
            Serial.println("reached Home X");
          }
        }

        while(LimitSwitchHomeY == 0) { 
	  mY->onestep(BACKWARD,INTERLEAVE);
          Serial.print(".");
          if (LimitSwitchHomeY == 1) {
            yhome = true;
            Serial.println("reached Home Y");
          }
        }
        

}

