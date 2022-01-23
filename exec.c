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
    //return 1;
  }
  if (simba==0)   // Is child
  {
    execvp(argv[0], &argv[0]);
    //printf("The child didn't graduate, it's a failure.\n");   // This will execute only in case of exec failure,
    //return 1;                           // Since exec replaces a processus' pile.
  }
  else {      // Is parent
    waitpid(simba, &status, WUNTRACED | WCONTINUED); // Je ne sais pas trop ce que fait cette ligne mais je sais que ça marche très bien donc bon...
  }   
}
