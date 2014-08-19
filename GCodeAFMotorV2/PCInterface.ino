void pcinterface(String WhatToDo) {

  if (WhatToDo == "CONFIG") {
    Serial.print("V:");
    Serial.print(VERSION);
    Serial.print(";MAXFEED:");
    Serial.print(MAX_FEEDRATE);
    Serial.print(";MINFEED:");
    Serial.print(MIN_FEEDRATE);
    Serial.print(";DimX:");
    Serial.print(DimensionX);
    Serial.print(";DimY:");
    Serial.print(DimensionY);
    Serial.print(";SpU:");
    Serial.print(StepsPerUnit);
    Serial.println();
  }
  
  if (WhatToDo == "POSITION") {
   sendPos();
  }
  
  if (WhatToDo == "XPLUS") {
      //Move10StepsXPlus
      Serial.println(WhatToDo);
  }
  if (WhatToDo == "XMINUS") {
      //Move10StepsXMinus
      Serial.println(WhatToDo);
  }
  if (WhatToDo == "YPLUS") {
      //Move10StepsYPlus
      Serial.println(WhatToDo);
  }
  if (WhatToDo == "YMINUS") {
      //Move10StepsYMinus
      Serial.println(WhatToDo);
  }
  if (WhatToDo == "XPLUSPLUS") {
      //Move10StepsXPlusFast
      Serial.println(WhatToDo);
  }
  if (WhatToDo == "XMINUSMINUS") {
      //Move10StepsXMinusFast
      Serial.println(WhatToDo);
  }
  if (WhatToDo == "YPLUSPLUS") {
      //Move10StepsYPlusFast
      Serial.println(WhatToDo);
  }
  if (WhatToDo == "YMINUSMINUS") {
      //Move10StepsYMinusFast
      Serial.println(WhatToDo);
  }
  
}
