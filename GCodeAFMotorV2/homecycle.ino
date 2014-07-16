void homecycle() {
	
        // get states of limit switches
  	int home_x_state = digitalRead(LimitSwitchHomeX);
	int home_y_state = digitalRead(LimitSwitchHomeY);
	int end_x_state = digitalRead(LimitSwitchEndX);
	int end_y_state = digitalRead(LimitSwitchEndY);

        boolean xhome = false; // set to true if X has reached home position
        boolean yhome = false; // set to true if Y has reached home position
	
	//check if X & Y not on home or end limit switches
	if (home_x_state == 1 || home_y_state == 1 ||
            end_x_state == 1 || end_y_state == 1) {
	
		Serial.println("Either X or Y are not in a moveable position!");
		release();
		delay(250);
		Serial.println("Motors are released. Now please move X and/or Y from its limit switch.");
		return;
	}
	
        while(home_x_state == 0) { 
	  mX->onestep(BACKWARD,INTERLEAVE); // move a step
          Serial.print(".");
          home_x_state = digitalRead(LimitSwitchHomeX); // query status of limit switch
          if (home_x_state == 1) {
            xhome = true;
            Serial.println("reached Home X");
          }
        }

        while(home_y_state == 0) { 
	  mY->onestep(BACKWARD,INTERLEAVE); // move a step
          Serial.print(".");
          home_y_state = digitalRead(LimitSwitchHomeY); // query status of limit switch
          if (home_y_state == 1) {
            yhome = true;
            Serial.println("reached Home Y");
          }
        }
        
	if ( xhome == true && yhome == true) {
	  position(0,0);
          has_origin = true;
	  Serial.println("Set X/Y to 0/0 ...");
	}

}

