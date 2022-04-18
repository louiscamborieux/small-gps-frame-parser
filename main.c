#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "frameparser.h"



void main () {

  char* stest = "$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E";

  char champs[3][MAX_FIELD_SIZE];

  extract_fields(stest,champs);
  printf("%s\n",champs[0]);
  printf("%s\n",champs[1]);
  printf("%s\n",champs[2]);

  
  char temps[6];
  format_time(champs[0],temps);
  printf("%s\n",temps);

  /*
  char  degre[3];
  char minute[3];
  char  secondes[6];
  int i = 0;
  while (i <2 && champs[1][i] =='0'){
    i++;
  }
  if (i <2){
    strncat(degre,champs[1]+i,2-i);
    printf(degre);}
    
  strncat(minute,champs[1]+2,2);
  printf("\n%s\n",minute);
  gcvt(strtof(champs[1]+4,NULL)*60,6,secondes);
  printf(secondes);*/
  
 char longitude[15];
 char latitude[15];


 convert_coord(champs[1],latitude,0);
 convert_coord(champs[2],longitude,1);
 
 printf("%s\n%s",latitude,longitude);



  
  
}

