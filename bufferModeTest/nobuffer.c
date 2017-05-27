
#include <stdio.h>
 
int main(void)
{
    fputs("hello", stderr);
    sleep(2);
    fputs("world", stderr);
    sleep(2);
 
    return 0;
}

