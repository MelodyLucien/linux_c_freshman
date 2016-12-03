#include <stdio.h>
#define print printf("%s",__func__);
void foo(){
  print
  printf("hello!!\n");
}
int main(){
  foo();
  return 0;
}
