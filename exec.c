#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

char* execution(char *cmd, char **argv){ //Fonction qui a pour but d'exécuter une commande.
    
    
    pid_t simba;    //Simba is the state of our fork, the code returned by the function.
    simba=fork();
    if (simba==-1){
        perror("fork failed");
        return 1;
    }
    if (simba==0)   // Is child
    {
        execvp(cmd, argv);
        printf("The child didn't graduate, it's a failure.\n");   // This will execute only in case of exec failure,
		return 1;                           // Since exec replaces a processus' pile.
    }
    else {      // Is parent
        waitpid(simba); // Waits for a status report from the child. WUNTRACED is only here in case we use SIG actions in further development.
    }
    
    
    
}
