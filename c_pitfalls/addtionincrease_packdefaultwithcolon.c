#include<stdio.h>
#include<stdbool.h>
//default pack(4)
//#pragma pack(1)
struct S1
{
  char a:7;
  char b:7;
  char c:7;
  char d:7;
  char e:4;
};

struct S2
{
  int a:7;
  int b:7;
  int c:7;
  int d:7;
  int e:4;
};

int main(){

 printf("size :  int = %d\nsize :  char = %d\nsize :  short = %d\n",(int)sizeof(int),(int)sizeof(char),(int)sizeof(short));

 printf("size of S1= %d\n",(int)sizeof(struct S1));
 printf("size of S2= %d\n",(int)sizeof(struct S2));

 return 0;
}
