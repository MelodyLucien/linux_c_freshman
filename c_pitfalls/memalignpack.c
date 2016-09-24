#include<stdio.h>
#pragma pack(4)
struct S1
{
  int a;
  char b;
  short c;
  char d;
};


int main(){

 printf("size :  int = %d\nsize :  char = %d\nsize :  short = %d\n",(int)sizeof(int),(int)sizeof(char),(int)sizeof(short));

 printf("size of S1= %d\n",(int)sizeof(struct S1));

 return 0;
}
