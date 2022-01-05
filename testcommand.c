#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

/*Petit programme qui montre comment utiliser le fonciton execvp
execvp veut dire exec en utilisant un vectuer (d'où le v) et en utilisant le Path (d'où le p)
En première argument, la commande doit avoir le nom de la commande à executer, sans argument (exemple ip)
et en deuxième argument, l'adresse du premier élément un tableau de pointeurs sur charactère. 
Ce tableau contient en premier élément la commande et les élément suivant sont les argument. 
Il doit se terminer par NULL
*/

int main ()  {
    int res;
    char ** vecteur; // Je crée un pointeur sur pointeur sur charactère
    vecteur = (char **)malloc(6 * sizeof(void *)); //je transforme le pointeur que je viens de crée en tableau en lui allouant de la place en mémoire
    vecteur[0] = "ip";  //la commande 
    vecteur[1] = "addr";    //un argument
    //vecteur[3] = "-4";
    //vecteur[4] = "/";         
    vecteur[2] = NULL; // je finis par un NULL
    //res = fork(); 
    //if (res==0){
        execvp(vecteur[0], &vecteur[0] ); //et j'execute
    //}

    
}
