
#include <stdio.h>
 
int main(void)
{
    fputs("hello", stdout);
    sleep(2);
    //这里一开始输出了换行符，所以前面的hello就被输出到屏幕上了。
    fputs("\nworld", stdout);
    sleep(2);
 
    return 0;
}

