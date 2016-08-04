#include<stdio.h>

#define PI 3.142

int main()
{
  float result = 0 ;
  int i = 0;
  float n =0;
  printf("input a circle's radius");
  printf("\n");
  scanf("%f",&n);
  result=n*n*PI;
  printf("the result is %f",result);
  printf("\n");

   return 0;
}
