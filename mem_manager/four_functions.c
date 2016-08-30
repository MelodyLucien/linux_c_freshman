#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
  four main functions for mem manage
  void *malloc(unsigned int size);
  void *calloc(unsigned int n,unsigned int size);
  void *realloc(void *address, unsigned int size);
  void *memset(void *s,char ch,unsigned int n);
*/

int b = 10;
int main()
{
     printf("*******************use malloc**********************\n");
     long * p=(long *)malloc(200);
     int * n=(int*)malloc(400);
     double * d = (double *)malloc(1000);
     printf("malloc %x\n",p);

     printf("the size of malloc long * is %d\n",sizeof(p));
     printf("the size of  long is %d\n",sizeof(long));
     printf("the size of malloc int is %d\n",sizeof(int));
     printf("the size of malloc double is %d\n",sizeof(double));

     printf("the size of malloc int * is %d\n",sizeof(n));
     printf("the size of malloc double * is %d\n",sizeof(d));


     free(p);

     printf("*******************use callloc for an array**********************\n");
     int * intArray;
     intArray=(int *)calloc(5,sizeof(int));
     printf("the size of intArray is %d \n",sizeof(intArray));
     printf("the address of intArray is %x \n",&intArray);


     printf("*******************use reallloc for an array**********************\n");
     intArray=(int *)realloc(intArray,24);
     printf("the size of intArray is %d\n",sizeof(intArray));
     printf("the address of intArray is %x\n",&intArray);

     int a =5;
     printf("the address of static address of int a in main function is %x\n",&a);

     printf("the address of global address of int b outside main function is %x\n",&b);

     free(intArray);

     printf("*************************use memset*******************************\n");
     char *s= "hello world\n";
     printf("the string of s is %s\n",s);
     memset(&s,'*',strlen(s)-1);
     printf("after memset ,the content of s is %s\n",s);
     free(s);


   return 0;
}
