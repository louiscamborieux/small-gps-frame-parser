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
*  Nom du fichier : frameparser.h                                             *
*                                                                             *
******************************************************************************/
#ifndef frameparser
#define frameparser
#define MAX_FIELD_SIZE 20

//Verifie la validité de la trame GPS renvoie 0 si elle est ok, -1 si elle ne commence pas par $GPGGA et le nombre actuel de champs trouvés si il en manque
int checkframe(char* s);

//Extrait les champs de la trâme GPS et renvoie le résultat brut dans un tableau à deux dimensions fields
int extract_fields (char* s, char fields[3][MAX_FIELD_SIZE]);

//Formate la chaine de 6 caractères du temps  et la renvoie dans la chaîne dynamique r pour préparer l'affichage
int format_time(char s[6], char* r);

//A partir d'une chaine de caractere s, détermine la latitude ou la longitude et la renvoie dans la chaîne r
//Le paramètre offset permet de choisir si l'on souhaite obtenir la latitude ou la longitude
int convert_coord(char s[11],char r[13], int offset);
#endif
