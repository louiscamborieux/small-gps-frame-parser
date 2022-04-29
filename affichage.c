/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 1                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :   Analyse de trames GPS                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Afrite Yanis                                                 *
*                                                                             *
*  Nom-prénom2 : Calmet Alexandre                                             *
*                                                                             *
*  Nom-prénom3 : Bessier Jason                                                *
*                                                                             *
*  Nom-prénom4 : Camborieux Louis                                             *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : affichage.c                                               *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "frameparser.h"

int affichercoord (char* s, char coord );
int afficherheure(char* s);

int main () {
    char* stest = "$GPGGA,064036.289,4836.5355,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E";
    
    printf("-----------------------------------Affichage-----------------------------------\n");
    printf("\nTrame : %s\n",stest);
    printf("\nVerification...\n");
    switch (checkframe (stest)) {
            case -1:  printf("Trame au format inccorect\n");
                return -1;
                break; 
            case 0: printf("Trame OK\n");
                break;
            default: printf("Il manque %d champs dans cette trame\n",15-checkframe(stest));
                return checkframe(stest);
                break;
    }
    
    printf("\n    Informations extraites    \n");
    printf("\n-----------------------------\n| ");
    affichercoord(stest, '0');
    printf(" |\n| ");
    affichercoord(stest, '1');
    printf(" |\n|---------------------------|\n| ");
    afficherheure(stest);
    printf("         |\n-----------------------------\n");
    return 0;


    
}

int affichercoord (char* s, char coord ) {
        char champs[3][MAX_FIELD_SIZE];
        int codechamps;
        char chaine[15] ;

        switch (checkframe (s)) {
            case -1:
                return -1;
                break; 
            case 0: 
                break;
            default: 
                return checkframe(s);
                break;
        }

        extract_fields(s, champs);
        switch (coord) {
            case '0' : convert_coord(champs[1],chaine,0);
                        printf("Lattitude : %s",chaine);
                        break;
            case '1' : convert_coord(champs[2],chaine,1);
                        printf("Longitude : %s",chaine);
                        break;
            case 'a' : convert_coord(champs[1],chaine,0);
                        printf("Lattitude : %s",chaine);
                       convert_coord(champs[2],chaine,1);
                        printf("Longitude : %s",chaine);
                        break;
            default : printf("Parametre 2 incorrect, (0 : lattitude , 1 : longitude, a : afficher les deux");
                        break;
                        return -2;

        }

        return 0;

    }

int afficherheure (char* s) {
        char champs[3][MAX_FIELD_SIZE];
        int codechamps;
        char chaine[6] ;

        switch (checkframe (s)) {
            case -1:  
                return -1;
                break; 
            case 0: 
                break;
            default: 
                return checkframe(s);
                break;
        }

        extract_fields(s, champs);

        format_time(champs[0],chaine);
        printf("Heure : %s",chaine);
        }
