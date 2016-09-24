#include<stdio.h>
#define DEBUG 0
#ifdef DEBUG
#define myprint(...) printf(__VA_ARGS__);
#endif

int main(){
  int i =0;
  myprint("hello!!! %d\n",i);


  return 0;
}
