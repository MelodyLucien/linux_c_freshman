#include<stdio.h>
#define log(...) {printf(__VA_ARGS__); putchar('\n');}
int main(){
  log("i feel good");
  return 0;
}
