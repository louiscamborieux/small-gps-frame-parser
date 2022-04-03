#include <stdio.h>
#include <string.h>
#include "frameparser.h"



void main () {

  char* stest = "$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E";

  char champs[3][MAX_FIELD_SIZE];

  extract_fields(stest,champs);
 
  
  printf("%s\n",champs[0]);
  printf("%s\n",champs[1]);
  printf("%s\n",champs[2]);
  



  
}

