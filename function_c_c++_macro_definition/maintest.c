#include <stdio.h>
#define _ANDROID_ android


#define GLOBAL(...)

#ifdef _ANDROID_
  int globals=2;
#endif

#if defined(_ANDROID_)
  int global=1;
#else
  int global=0
#endif


GLOBAL(
int pp=5;
char a[]="sdsd";
);

#define print printf("%s",__func__);

void foo(){
  printf("%s\n",__func__);
}

int main(){
  printf("%s\n",__func__);
  printf("hello!!,global=%d,globals=%d\n",global,globals);
  foo();
  return 0;
}
