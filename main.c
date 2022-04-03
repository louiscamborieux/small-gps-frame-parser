#include <stdio.h>
#include <string.h>

int checkframe(char* s);
void main () {

  char* stest = "$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E";
  printf("%d",checkframe(stest));
  
}

int checkframe(char* s){
  if (strncmp(s,"$GPGGA,",7) !=0) {
    return -1;
  }
  int i=0;
  while (strchr(s,',')!=NULL && i!=14){
    i++;
    s =strchr(s,',')+1;
  }
  if (i !=14) {
    return i;}
  else {
    return 0;
  }
}