#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>


int main ()  {
    int res;
    char ** vecteur;
    vecteur = (char **)malloc(6 * sizeof(void *));
    vecteur[1] = "tu";
    vecteur[2] = "addr";
    //vecteur[3] = "-4";
    //vecteur[4] = "/";
    vecteur[4] = NULL;
    res = fork(); 
    if (res==0){
        execvp("ip", &vecteur[1] );
    }

    
}
