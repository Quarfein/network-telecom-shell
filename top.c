#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* Code trouvé sur l'internet qui montre l'execution de la commande top.
Intéressant, à exploiter 
NB : Ne fait pas partie de notre shell*/

pid_t spawnChild(const char* program, char** arg_list)
{
    pid_t ch_pid = fork();
    if (ch_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (ch_pid > 0) {
        printf("spawn child with pid - %d\n", ch_pid);
        return ch_pid;
    } else {
        execvp(program, arg_list);
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    const char *args[] = { "top", NULL, NULL };

    pid_t child;
    int wstatus;

    child = spawnChild("top", args);

    if (waitpid(child, &wstatus, WUNTRACED | WCONTINUED) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
