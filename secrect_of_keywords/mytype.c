#include<stdio.h>
typedef int INT32;
typedef short CHAR;
typedef unsigned char BYTE;
typedef struct {
   INT32 i;
   CHAR c;
   BYTE b1;
   BYTE b2;
} Demo;

int main (){
   
	   INT32 i;
	   BYTE b;
	   CHAR a;
	   Demo d;

	 printf("%d,%d\n",sizeof(INT32),sizeof(i));
	 printf("%d,%d\n",sizeof(CHAR),sizeof(a));
	 printf("%d,%d\n",sizeof(BYTE),sizeof(b));
	 printf("%d,%d\n",sizeof(Demo),sizeof(d));


 
  return 0;
}
