#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void execution(char **argv){ 
//Fonction qui a pour but d'exécuter une commande.
//Elle prend en paramètre uniquement le vecteur (il contient la commande et les arguments)
    
    
    pid_t simba;    //Simba is the state of our fork, the code returned by the function.
    simba=fork();
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
      //  waitpid(simba); // Waits for a status report from the child. WUNTRACED is only here in case we use SIG actions in further development.
    }   
}

/* int main() {
  char ** vecteur; // Je crée un pointeur sur pointeur sur charactère
  vecteur = (char **)malloc(6 * sizeof(void *)); //je transforme le pointeur que je viens de crée en tableau en lui allouant de la place en mémoire
  vecteur[0] = "ip";  //la commande 
  vecteur[1] = "addr";    //un argument
  execution(vecteur);
  return 0;
}
 */