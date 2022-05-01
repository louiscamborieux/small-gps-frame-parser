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

Le sous-programmes affiche.c contient 3 fonctions :

- La fonction affichercoord prend en paramètres d'entrées une chaîne dynamique s de caractères et coord de type caractère, retourne un entier. Cette fonction permet d'afficher les coordonnées (latitude et longitude). On peut choisir soit d'afficher uniquement la longitude ou la latitude soit les deux.
- La fonction afficherheure prend en paramètre d'entrée une chaîne dynamique s et retourne un entier. 
- La fonction main retourne un entier. Elle affiche toutes les informations sous le bon format.

Le sous-programmes affiche.c contient 4 fonctions :

- La fonction checkframe prend en paramètres d'entrées une chaîne dynamique s de caractères et retourne un entier. Elle verifie si la trame GPS est valide, ainsi la fonction renvoie 0 si elle est ok, -1 si elle ne commence pas par $GPGGA et le nombre actuel de champs trouvés si il en manque

- La fonction extract_fields prend en paramètres d'entrées une chaîne dynamique s de caractères et un tableau de caractères à deux dimensions nommé fields, retourne un entier. Elle extrait les champs de la trâme GPS et renvoie le résultat brut dans un tableau à deux dimensions.

- La fonction format_time prend en paramètres d'entrées une chaine s de 6 caractères et une chaîne dynamique r de caractères, retourne un entier. Cette fonction formate la chaine de 6 caractères du temps et la renvoie dans la chaîne dynamique r pour préparer l'affichage.

- La fonction format_time prend en paramètres d'entrées une chaine s de 11 caractères, une chaine r de 13 caractères et un entier offset, retourne un entier. Cette fonction permet à partir d'une chaine de caractere s à déterminer la latitude ou la longitude et la renvoie dans la chaîne r. Le paramètre offset permet de choisir si l'on souhaite obtenir la latitude ou la longitude.

