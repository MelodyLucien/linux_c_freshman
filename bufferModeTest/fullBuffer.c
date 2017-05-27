
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
 
int main(void)
{
    printf("full buf test!\n");
    FILE *stream;
    if ((stream = fopen("./log.txt", "a")) == NULL) {
        printf("error: %d\n", errno);
        exit(1);
    }
     
    char buf[BUFSIZ];//size 8192
    printf("buf size %d\n",BUFSIZ);
    setvbuf(stream, buf, _IOFBF,  BUFSIZ);
    fputs("hello world!", stream);
 
    sleep(20);
    printf("over write!\n");
 
    return 0;
}

