#include<iostream>
using namespace std;
void show(int num){
	cout<<num;
}
int main(){
	void (*fp) (int a);//括号一定要加，否则报错 error: cannot convert 'void(int)' to 'void*(int)' in assignment
        typedef void(*fp1)(int a);//这里可以使用typedef定义一个类型(type)，这里是一个返回值为void型函数指针的名叫fp1的函数指针类型
        fp1 fp_1 = show;//接着就可以定义某个具体的函数指针“变量”，这个变量的指针指向show这个函数
	fp = show;//fp同样指向show这个函数
	fp(5);
        fp_1(5);
	fp1 fparray[3]={show,show,show};
	fparray[1](10);
	return 0;
}
