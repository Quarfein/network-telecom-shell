#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* deconcatCmd (char* commande){ //fonction qui permet à partir d'un tableau de caractères, de le déconcaténer en plusieurs tableaux de caractère eux meme dans un tableau.
    char *res, *res2;
    int i=0;
    int nbCara = strlen(commande); //nombre de caractère de la commande
    printf("%d \n", nbCara);       //J'ai bien le nombre de caractères de ma commande.
    //printf("%s", commande );    //J'arrive à avoir la commande et à l'afficher ce qui est deja bien
    res2 = (char*) malloc (nbCara * sizeof(char));

    res = strtok(commande, " ");
    //printf("%s", res);

    while (res != NULL){
        printf("%s", res);

    }

    //for (i=0; i<nbCara; i++){
    //    if (commande[i])
    //}

}

int main(){     //pour le débuggage
    printf("Hello \n");
    char test[] = "yes No";
    deconcatCmd(test);
    return 0;
}