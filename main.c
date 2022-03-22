#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exec.h"
#include "deconcat.h"
#include "signature.h"

#define IMPUT_SIZE 100 //Taille max de la commande entrée par l'utilisateur
#define DIR_SIZE 200 //Taille max du chemin absolu du répertoire courant

int main()
{
    int flag = 1;
    char input[IMPUT_SIZE];
    char working_dir[DIR_SIZE];
    char temp;
    char ** vecteur;
    char *new_dir;

    char main_dir[DIR_SIZE];
    getcwd(main_dir, sizeof(main_dir)); //répertoire d'arrivé donc considéré comme répertoire home

    signature();

    while (flag == 1) //tant que l'utilisateur n'a pas dit qu'il voulait quitter on reste dans le programme
    {
        strcpy (input, ""); //Je place un champ vide à l'intérieur de ma commande
        getcwd(working_dir, sizeof(working_dir));
        printf("%s$ ", working_dir);
        scanf("%[^\n]", input); //je lis jusqu'à ce que j'appuie sur Entrée
        scanf("%c", &temp);     //je stoque le "Entrée" de scanf précédent, sans cette ligne le "Entrée" du scanf va rerentrer dans le scanf et ce jusqu'à l'infini donc très important.
        deconcatCmd(input, &vecteur); // Je découpe ma commande
        //printf("Input est : %s\n", input); // A utiliser si besoin pour le débug
        if (strcmp(input,"") != 0 ) { //S'il y a une commande alors :
            if (strcmp(input, "exit") == 0) // l'utilisateur veut quitter donc fin du programme
            {
                flag = 0;
            }
            else if (strcmp(vecteur[0], "cd") == 0 ){ //si la commande commance par cd alors :
                if (vecteur[1] == NULL){ // Dans le cas où il y a juste cd sans argument alors on revient au répertoire de base cf. main_dir
                    new_dir = main_dir;
                }
                else if ( *vecteur[1] == 47) { //si ça commance par un "/"  (si c'est un chemin absolu)
                    new_dir = vecteur[1];
                }
                else {  //sinon (donc c'est un chemin relatif)
                    new_dir = strcat(working_dir, "/");     //on rajout un "/""
                    new_dir = strcat(new_dir, vecteur[1]);      //puis l'argument donné
                }
                if (chdir(new_dir) != 0) { //si le dossier n'existe pas on affiche une erreur. NB : Dans tous les cas chdir est exécuté
                    perror("Changement de répertoire impossible");
                }
            }
            else { // Si l'utlisateur ne veux aucun des choix possibles au dessus, alors on execute sa commande avec le execvp
                execution(vecteur); //j'exécute
            }
        }
    }

    return 0;
}