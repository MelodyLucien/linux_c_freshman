#include<stdio.h>
int main(){
   unsigned int i=1;
   
   printf("the unsigned int  size is %d\n",(int)sizeof(unsigned int));
   
   
   printf("the  int  size is %d\n",(int)sizeof(int));

   printf("the unsighed short int size is %d\n",(int)sizeof(unsigned short int));

   if(i>-1){
    printf("i am bigger than -1\n");
   }else{
    printf("i am not bigger than -1\n");
   }

   
   printf("the unsigned int   1 is %x\n",i);
   printf("the signed int i  -1 is %x\n",-1);
   
   return 0;
}
