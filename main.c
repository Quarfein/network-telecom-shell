#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int flag = 1;
    char input[100];
    char working_dir[100];

    while (flag == 1)
    {
        getcwd(working_dir, sizeof(working_dir));
        printf("%s$ ", working_dir);
        scanf("%s", input);
        // printf("%s\n", input); //this has been used for debug
        // i hate life because switch case can't be used with strings
        if (strcmp(input, "exit") == 0)
        {
            flag = 0;
        }
    }

    return 0;

    // this whole thing really is a base. The most difficult things will be how do we make all of these commands?
}