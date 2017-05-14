#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t cpid, w;
    int status;
    printf("parent PID is %d, groupid = %d\n", getpid(),getpgid(getpid()));
   // printf("hello yes.\n");
    cpid = fork();

    if (cpid == 0) {            /* Code executed by child */
        if (argc == 1){
            printf("i am child now i pause()\n");
            pause();
            printf("i resume now \n");
         }/* Wait for signals */

         //use _exit to not relase some resource shared by parents
        _exit(atoi(argv[1]));          /* atoi() for converting string to int*/

    } else {
         printf("child PID is %d, groupid = %d\n", cpid,getpgid(cpid));
         /* Code executed by parent */
        do {
            w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
            printf("after child process sstate change!\n");
            if (w == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

            if (WIFEXITED(status)) {
                printf("exited, status=%d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("killed by signal %d\n", WTERMSIG(status));
            } else if (WIFSTOPPED(status)) {
                printf("stopped by signal %d\n", WSTOPSIG(status));
            } else if (WIFCONTINUED(status)) {
                printf("continued\n");
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        exit(EXIT_SUCCESS);
    }
}
