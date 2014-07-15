/**
* Set the feedrate (speed motors will move)
* @input nfr the new speed in steps/second
*/
void feedrate(float nfr) {
  if(fr==nfr) return; // same as last time? quit now.

  if(nfr>MAX_FEEDRATE || nfr<MIN_FEEDRATE) { // don't allow crazy feed rates
    Serial.print(F("New feedrate must be greater than "));
    Serial.print(MIN_FEEDRATE);
    Serial.print(F("steps/s and less than "));
    Serial.print(MAX_FEEDRATE);
    Serial.println(F("steps/s."));
    return;
  }
  step_delay = 1000000.0/nfr;
  fr=nfr;
}
