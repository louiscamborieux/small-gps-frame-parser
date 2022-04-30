# Mini-Projet_C
##  Membre du groupe

 - AFRITE Yanis
 - BESSIER Jason
 - CALMET Alexandre
 - CAMBORIEUX Louis
 - HALIMI Isaiah

## Situation d’Apprentissage et D’Evaluation du Projet 1 : Analyse de trames GPS

Au cours de ce mini projet nous allons développer une application en C qui permet à partir d'une trame GPS de type GPGGA d'extraire différentes informations. Ces informations permettront de savoir la latitude ,la longitude, l'heure... Ces données seront ensuite affichées selon le format imposé, format XX"YY"ZZ.ZZ" pour la longitude et latitude et format XXhYYmZZs pour l'heure. Remarque, la trame devra contenir au moins 15 champs.


##  Présentation

Ce projet sera divisé en 3 programmes :

 - affichage.c : c'est le main, il permet d'afficher les coordonnées ainsi que l'heure dans les formats imposés.
 - frameparser.c : permet de vérifier la trame (si elle est du bon format), d'extraire les informations qui nous intéressent et de convertir ces données.
 - frameparser.h
 
*Contrainte imposée : la trame GPS doit contenir au moins 15 champs.*

##  Description
*Note : Description plus détaillée des différents programmes*

