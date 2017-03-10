#include<stdio.h>
#define TEST 1
#if TEST
#define MM "iff"
#else 
#define MM "elsee"
#endif

// if  __builtin_expect(a,b) both a and b is 0,the return value is 0,otherwise it will be 1

#define isbuilt  __builtin_expect(0,0)

int main(){
  if(1)
     printf("%s\n",MM);

  if(isbuilt)
   {
     printf("isbuilt is 1\n");
   }else{
     printf("isbuilt is 0\n");
   }
}
