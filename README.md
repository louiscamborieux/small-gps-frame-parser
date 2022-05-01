# Mini-Projet_C

lien du dépôt git : https://gitlab.info.iut-tlse3.fr/bsj3657a/mini-projet_c

##  Membre du groupe

 - AFRITE Yanis
 - BESSIER Jason
 - CALMET Alexandre
 - CAMBORIEUX Louis
 - HALIMI Isaiah

## Situation d’Apprentissage et D’Evaluation du Projet 1 : Analyse de trames GPS

Au cours de ce mini projet nous allons développer une application en C qui permet à partir d'une trame GPS de type GPGGA d'extraire différentes informations. Ces informations permettront de savoir la latitude ,la longitude, l'heure... Ces données seront ensuite affichées selon le format imposé, format XX"YY"ZZ.ZZ" pour la longitude et latitude et format XXhYYmZZs pour l'heure. Remarque, la trame devra contenir au moins 15 champs.


##  Présentation

Ce projet sera divisé en 3 sous programmes :

 - affichage.c : c'est le main, il permet d'afficher les coordonnées ainsi que l'heure dans les formats imposés.
 - frameparser.c : permet de vérifier la trame (si elle est du bon format), d'extraire les informations qui nous intéressent et de convertir ces données.
 - frameparser.h : contient les entêtes des fonctions de frameparser.c.
 
*Contrainte imposée : la trame GPS doit contenir au moins 15 champs.*

##  Description

###Le sous-programmes affiche.c contient 3 fonctions :

- La fonction affichercoord qui prend en paramètres d'entrées un pointeur de type caractère nommé s et un autre caractère nommé coordonnées. Retourne un entier.
- La fonction afficherheure qui prend en paramètre d'entrée un pointeur de type caractère nommé s et retourne un entier.
- La fonction main qui retourne un entier.




