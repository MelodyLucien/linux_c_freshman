#include<stdio.h>
#define TEST 1
#if TEST
#define MM "iff"
#else 
#define MM "elsee"
#endif
int main(){
  if(1)
  printf("%s\n",MM);

}
