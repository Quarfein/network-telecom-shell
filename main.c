#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void deconcatCmd(char *commandeTotal, char ***arguments);
void execution(char **argv);

int main()
{
    int flag = 1;
    char input[100];
    char working_dir[100];
    char temp;
    char ** vecteur;

    while (flag == 1) //tant que l'utilisateur n'a pas dit qu'il voulait quitter on reste dans le programme
    {
        getcwd(working_dir, sizeof(working_dir));
        printf("%s$ ", working_dir);
        scanf("%[^\n]", input); //je lis jusqu'à ce que j'appuie sur Entrée
        scanf("%c", &temp);     //je stoque le Entrée quelque part pour qu'il évite de faire des carabistouilles ailleur (sans cette line c'est un peu n'importe quoi)
        //printf("%s\n", input); // A utiliser si besoin pour le débug
        if (strcmp(input, "exit") == 0) // l'utilisateur veut quitter donc fin du programme
        {
            flag = 0;
        }

        else if (strcmp(input,"")!=0){ // Si l'utlisateur ne veux aucun des choix possibles au dessus, alors on execute sa commande avec le execvp
            deconcatCmd(input, &vecteur);
            execution(vecteur);
            strcpy (input, "");
        }
        
    }

    return 0;
}