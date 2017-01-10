#include<stdio.h>
int main(){
  char test[30];
  char *my="my";
  char *thanks="thanks";
  int n=snprintf(test,20,"%s,%s",my,thanks);
  printf("%s\n",test);  
  return 0;
}
