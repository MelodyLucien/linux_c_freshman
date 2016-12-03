#include<stdio.h>
#include<stdbool.h>
#pragma pack(1)
struct S1
{
  int a;
};

struct S2
{
  int b;
  bool f:1;
};

int main(){

 printf("size :  int = %d\nsize :  char = %d\nsize :  short = %d\n",(int)sizeof(int),(int)sizeof(char),(int)sizeof(short));

 printf("size of S1= %d\n",(int)sizeof(struct S1));
 printf("size of S2= %d\n",(int)sizeof(struct S2));

 return 0;
}
