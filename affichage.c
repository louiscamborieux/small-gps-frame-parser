#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "frameparser.h"

int affichercoord (char* s, char coord );
int afficherheure(char* s);

int main () {
    
    //Ouverture du fichier in.txt à partir du quel sont entrées les trames
    FILE *fic;
    fic = fopen("in.txt", "r");
    if (fic == NULL)
    {
        printf("Fichier in.txt inexistant, veuillez renseigner vos trames dans un fichier nommé \"in.txt\"");
        return -3;
    }
    fclose(fic);
        
    char * ligne = NULL;
    size_t taille = 0;
    char entree ;
    int page = 0;

    //Affichage des lignes du fichier avec un système de pagination
    while ( atoi(&entree) ==0 || atoi(&entree) >5) {
    fic = fopen("in.txt", "r");
    int pi =0;
    while (pi < page*5 && !feof(fic)) {
        getline(&ligne,&taille,fic);
        pi++;
    }
    getline(&ligne,&taille,fic); 
    printf("---------------------------------Page %d----------------------------------\n",page+1) ;
    int i = 0;  
    //Affichage page en cours
    while (!feof(fic) && i <(4)) {
        printf("%d) ",i+1);
        printf(ligne);
        getline(&ligne,&taille,fic);  
        i++;
    }
    printf("%d) %s",i+1,ligne);
    if (i ==0) {
        printf("Fichier vide");
        return -4;
    }
    //Menu sous la forme de saisie au clavier
    printf("\nChoisir une trame à analyser | 1-%d : Choix de la trame, s : Page suivante, p : Page précedente\n",i+1);
    entree = getchar();
    while ((getchar()) != '\n');
    
    switch (entree) {
        case 'p':
            if (page !=0) {
                page-=1;
            }
                break;
        case 's':
            if  (!feof(fic)) {
                page++;
            }
                break;
        default :
            break;
    }
    fclose(fic);
    
    }
    //Récuperation de la ligne sélectionnée
    fic = fopen("in.txt", "r");
    int i = 0;
    while (i < page*5+atoi(&entree) && !feof(fic)) {
        getline(&ligne,&taille,fic);
        i++;
    }
    
    printf("------------------------------------Analyse-----------------------------------\n");
    printf("\nTrame : %s\n",ligne);
    printf("\nVérification...\n");
    switch (checkframe (ligne)) {
            case -1:  printf("Trame au format incorrect.\n");
                return -1;
                break; 
            case 0: printf("Trame OK\n");
                break;
            default: printf("Il manque %d champ(s) dans cette trame.\n",14-checkframe(ligne));
                return checkframe(ligne);
                break;
    }
    
    printf("\n Informations extraites\n");
    printf("\n------------------------------\n| ");
    affichercoord(ligne, '0');
    printf(" |\n| ");
    affichercoord(ligne, '1');
    printf(" |\n------------------------------\n| ");
    afficherheure(ligne);
    printf("    |\n------------------------------\n");
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
                        printf("Lattitude : %*s",15,chaine);
                        break;
            case '1' : convert_coord(champs[2],chaine,1);
                        printf("Longitude : %*s",15,chaine);
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
        printf("Heure     : %*s",11,chaine);
        }
