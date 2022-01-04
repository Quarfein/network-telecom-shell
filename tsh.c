//juste pour tester
//shell minimal qui marche tant qu'il n'y a pas d'argument sur la commande

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>


int main ()  {
    int res;
    char cmd [50];
    while (1) {
        printf("Commande ? ");
        scanf("%s", &cmd);
        if (strcmp(cmd, "exit")==0){
            exit(0);
        }
        res=fork();
        if (res==0) {
            execlp(cmd, cmd, NULL);
        }
        else {
            wait(0);
        }
    }
}

