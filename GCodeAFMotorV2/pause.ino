/**
* delay for the appropriate number of microseconds
* @input ms how many milliseconds to wait
*/
void pause(long ms) {
  delay(ms/1000);
  delayMicroseconds(ms%1000); // delayMicroseconds doesn't work for values > ~16k.
}
