#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void execution(char **argv){ 
    /* Fonction qui a pour but d'exécuter une commande.
    Elle prend en paramètre uniquement le vecteur (il contient la commande et les arguments) */


    pid_t simba;    //Simba is the state of our fork, the code returned by the function.
    simba=fork();
    int status;
    if (simba==-1){
        perror("fork failed");
        }
    if (simba==0){   // Is child
        execvp(argv[0], &argv[0]);
    }
    else {      // Is parent
        waitpid(simba, &status, WUNTRACED | WCONTINUED); // Permet d'attendre que le fils soit mort
    }   
}
