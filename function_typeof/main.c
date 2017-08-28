 #include<stdlib.h>

typedef struct 
{
 int x;
 char y;
}astruct,* pastrcut;

int main()
{
 int sizem,sizew;
 int x = 3;

 typeof(&x) m;//extract the type of x

 sizem = sizeof(m);
 *m = 5;

 typeof(((astruct *)5)->y) w;//extract the type of y

 sizew = sizeof(w);
 w = 'a';
 return 1;

}


