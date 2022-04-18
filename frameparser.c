#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "frameparser.h"

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

void extract_fields (char* s, char fields[3][MAX_FIELD_SIZE]){
    //Extraction de l'heure
    s = strchr(s,',')+1;
    strncpy(fields[0],s,6);
    //Extraction de latitude
    s = strchr(s,',')+1;
    *fields [1] = '\0'; strncat(fields[1],s,9);
    s = strchr(s,',')+1;
    strncat(fields[1],s,1);
    //Extraction de la longitude
    s = strchr(s,',')+1;
    *fields[2] = '\0'; strncat(fields[2],s,10);
    s = strchr(s,',')+1;
    strncat(fields[2],s,1);
}

void format_time(char s[6], char* r) {
  strncat(r,s,2);
  strcat(r,"h");
  strncat(r,s+2,2);
  strcat(r,"m");
  strncat(r,s+4,2);
  strcat(r,"s");
}

void convert_coord(char s[12],char r[15], int offset) {
  int i = 0;
  char  seconde[6];
  r[0] = '\0';
  while (i <(2+offset) && s[i] =='0'){
    i++;
  }
  if (i <2+offset){
    strncat(r,s+i,2+offset-i);
    }
  else {
    strcat(r,"0");
  }
  strcat(r,"°");
  strncat(r,s+2,2);
  strcat(r,"'");
  sprintf(seconde,"%g",strtof(s+4,NULL)*60);
  strcat(r,seconde);
  strcat(r,"\"");
  strcat(r,s+9+offset);
  
}


