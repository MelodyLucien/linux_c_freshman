#include<stdio.h>
static int local =1;
void g(){

   ++local;
   printf("local---:%d\n",local);
}
