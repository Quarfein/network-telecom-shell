#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* fonction qui permet à partir d'un tableau de caractères, 
de le déconcaténer en plusieurs tableaux de caractère eux memes dans un tableau.
commandeTotal est la commande tapé par l'utilisateur complète (avec les arguements)
arguement est un pointeur sur pointeur, chaque pointeur étant un arguemnt, le permier est la commande et il se finit par un NULL */

void deconcatCmd(char *commandeTotal, char ***arguments)
{                       
    char *token;
    int nbmots = 0, j;
    int nbCara = strlen(commandeTotal); //nombre de caractère de la commandeTotal
    *arguments = (char **) malloc (nbCara * sizeof(char *)); //de même pour arguments

    token = strtok(commandeTotal, " "); // initialisation de strtok

    while (token != NULL)
    { // tant qu'il reste des mots
        (*arguments)[nbmots] = token;
        token = strtok(NULL, " "); // adresse de la première lettre du mot suivant
        nbmots++;
    }
    (*arguments)[nbmots] = NULL; // on met un NULL à la fin pour être sur que ça marche
}