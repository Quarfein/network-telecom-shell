#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void deconcatCmd(char *commandeTotal, char **commande, char ***arguments)
{                       //fonction qui permet à partir d'un tableau de caractères, 
                        //de le déconcaténer en plusieurs tableaux de caractère eux memes dans un tableau.
                        //commandeTotal est la commande tapé par l'utilisateur complète (avec les arguements)
                        //commande est uniquement le premier mot de commandeTotal
                        //et arguement est un pointeur sur pointeur, chaque pointeur étant un arguemnt
    char *token;
    int nbmots = 0, j;
    int nbCara = strlen(commandeTotal); //nombre de caractère de la commandeTotal
    //printf("%d \n", nbCara);       //J'ai bien le nombre de caractères de ma commandeTotal.
    //printf("%s\n", commandeTotal );    //J'arrive à avoir la commandeTotal et à l'afficher ce qui est deja bien
    *commande = (char *) malloc (30 * sizeof(char *)); // J'alloue a mon pointeur sur pointeur la taille necessaire
    // (en général une commande sans argument je fait jamais plus de 30 caractères, à améliorer)
    *arguments = (char **) malloc (nbCara * sizeof(char *)); //de même pour arguments

    token = strtok(commandeTotal, " "); // initialisation de strtok
    //printf("Token = %s",token);
    *commande = token; // le premier token est la commande
    token = strtok(NULL, " ");
    while (token != NULL)
    { // tant qu'il reste des mots
        (*arguments)[nbmots] = token;
        token = strtok(NULL, " "); //première lettre du mot suivant
        nbmots++;
    }
    /* printf ("Fonction :nbmot = %d \n", nbmots);
    printf("Fonction : Commande = %s\n", *commande);
    puts ("Fonction : ");
    for (j=0; j<nbmots; j++){     // Juste pour afficher le contenu de res, pour le déboggage
        printf("%s ", (*arguments)[j]);
    }  */
}
/* 
int main(){     //pour le débuggage
    printf("Hello \n");
    char *commande, **arguments, test[] = "yes No je mange des pates aux saumons du crous";
    deconcatCmd(test, &commande, &arguments );
    printf("\n Code : %s \n", commande);
    int j, nbmots = 9;
    for (j=0; j<nbmots; j++){     // Juste pour afficher le contenu de res, pour le déboggage 
        printf("%s ", arguments[j]);
    } 

    return 0;
}  */