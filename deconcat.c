#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* deconcatCmd (char* commande){ //fonction qui permet à partir d'un tableau de caractères, de le déconcaténer en plusieurs tableaux de caractère eux meme dans un tableau.
    char *token, **res; //res est un pointeur sur pointeur sur char qui va devenir tableau
    int nbmots=0, j;
    int nbCara = strlen(commande); //nombre de caractère de la commande
    printf("%d \n", nbCara);       //J'ai bien le nombre de caractères de ma commande.
    //printf("%s", commande );    //J'arrive à avoir la commande et à l'afficher ce qui est deja bien
    res = (char**) malloc (nbCara * sizeof(char)); // J'alloue a mon pointeur sur pointeur la taille necessaire

    
    token = strtok(commande, " "); // initialisation de strtok
    
    while (token != NULL){ // tant qu'il reste des mots
        res[nbmots]=token;
        token = strtok(NULL, " "); //première lettre du mot suivant
        nbmots++;
    }
    
    
    for (j=0; j<nbmots; j++){
        printf("%s ", res[j]);
    }

}

int main(){     //pour le débuggage
    printf("Hello \n");
    char test[] = "yes No je mange des pates aux saumons du crous";
    deconcatCmd(test);
    return 0;
}