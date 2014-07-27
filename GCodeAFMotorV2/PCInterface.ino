void pcinterface(String WhatToDo) {

  if (WhatToDo == "CONFIG") {
    Serial.print(VERSION);
    Serial.print(";");
    Serial.print(MAX_FEEDRATE);
    Serial.print(";");
    Serial.print(MIN_FEEDRATE);
    Serial.print(";");
    Serial.print(DimensionX);
    Serial.print(";");
    Serial.print(DimensionY);
    Serial.print(";");
    Serial.print(StepsPerUnit);
    Serial.println();
    
  }
  
  if (WhatToDo == "POSITION") {
   sendPos();
  }
  
}
