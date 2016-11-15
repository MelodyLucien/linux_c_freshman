#include<stdio.h>
int global;
int local;
void f();
int main(){
   
  printf("global:%d, static local :%d\n",global,local);
   f();
   ++global;
   printf("global:%d,static local:%d\n",global,local);
   return 0;
}
