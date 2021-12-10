#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char** deconcatCmd (char* commande);


int main()
{

    /* char test[] = "yes No je mange des pates aux saumons du crous";
    char** cmds;
    cmds = deconcatCmd(test);
    int j, nbmots = 7;
    for (j=0; j<nbmots; j++){     // Juste pour afficher le contenu de res, pour le déboggage 
        printf("%s ", cmds[j]);
    } */

    int flag = 1;
    char input[100];
    char working_dir[100];
    char temp;

    while (flag == 1) //tant que l'utilisateur n'a pas dit qu'il voulait quitter on reste dans le programme
    {
        getcwd(working_dir, sizeof(working_dir));
        printf("%s$ ", working_dir);
        scanf("%[^\n]", input);     //je lis jusqu'à ce que j'appuie sur Entrée
        scanf("%c", &temp);     //je stoque le Entrée quelque part pour qu'il évite de faire des carabistouilles ailleur (sans cette line c'est un peu n'importe quoi)
        // printf("%s\n", input); //this has been used for debug
        // i hate life because switch case can't be used with strings
        if (strcmp(input, "exit") == 0)     // l'utilisateur veut quitter donc fin du programme
        {
            flag = 0;
        }
    }

    return 0;

    // this whole thing really is a base. The most difficult things will be how do we make all of these commands?
    //note pour le l'amélioration : 
}