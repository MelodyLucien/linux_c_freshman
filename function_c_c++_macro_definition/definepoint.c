#include<stdio.h>
#define log(...) {printf(__VA_ARGS__); putchar('\n');}
#define logargs(args...) {printf(args); putchar('\n');}

int main(){
  printf("%s\n",__func__);
  log("i feel good");
  logargs("i feel good");
  return 0;
}
