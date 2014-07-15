/**
* Look for character /code/ in the buffer and read the float that immediately follows it.
* @return the value found. If nothing is found, /val/ is returned.
* @input code the character to look for.
* @input val the return value if /code/ is not found.
**/
float parsenumber(char code,float val) {
  char *ptr=buffer;
  while(ptr && *ptr && ptr<buffer+sofar) {
    if(*ptr==code) {
      return atof(ptr+1);
    }
    ptr=strchr(ptr,' ')+1;
  }
  return val;
}
