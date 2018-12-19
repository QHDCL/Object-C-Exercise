//初步使用c++的输入输出
#if 0
#include<iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	cout << "Hello world!!!" << endl;
	cout << "Hello world!!!" << endl;
	cout << "a:" << a << endl;
	return 0;
}
#endif

#if 0
#include<Windows.h>
#include<iostream>
using namespace std;   //使用命名空间std--包含输入输出
//命名空间
namespace N1{
	int a = 10;
	int b = 20;
}

namespace N2{
	int c = 30;
	int d = 40;
	namespace N3{
		int add(int x, int y){
			return x + y;
		}
	}
}

namespace N1{
	int e = 50;
	int f = 60;
}

using N2::c;               //引入命名空间成员使用
using namespace N2;        //引入命名空间使用

int main(){
	int g = 70;
	cout << "a:" << N1::a << endl;  //直接使用命名空间
	cout << "f:" << N1::f << endl;  //命名空间重名合并为一个
	cout << "c:" << c << endl;
	cout << "d:" << d << endl;
	cout << "x+y:" << N3::add(20, 20) << endl;
	cout << "g:" << g;
	system("pause");
	return 0;
}
#endif

#if 0
#include<Windows.h>
#include<iostream>
using namespace std;
//缺省参数--声明或定义一个函数时,给参数一个默认值,调用时有实参用实参,反之用默认
//全缺省参数--参数全部给出默认值
void add(int x = 1, int y = 2){
	cout << "x+y=" << x + y << endl;
}
//半缺省参数--从右往左给定默认值,不能有间隔
void sub(int x, int y = 1){
	cout << "x-y=" << x - y << endl;
}

int main(){

	add();                //不传实参,使用缺省参数
	add(10);              //传一个实参,从左向右匹配
	add(10, 20);          //实参全传,使用实参

	sub(1);
	sub(12, 2);

	system("pause");
	return 0;
}
#endif

#if 0
#include<Windows.h>
#include<iostream>
using namespace std;
int add(int x, int y){
	return x + y;
}
double add(double x, double y){
	return x + y;
}
char add(char x, char y){
	return x + y;
}
//函数重载 ---同一作用域中,函数名相同,参数列表(参数个数,参数类型,类型顺序)不同
int main(){
	cout << "两数和为:" << add(10, 20) << endl;
	cout << "两数和为:" << add(12.45, 10.55) << endl;
	cout << "两数和为:" << add('1', '2') << endl;
	system("pause");
	return 0;
}
#endif

//#include<Windows.h>
//#include<iostream>
//using namespace std;

//int main(){
//引用类型直接使用
//	int a = 10;
//	int& ra = a;
//	cout << "a:" << a << endl;
//	cout << "&a:" << &a << endl;
//	cout << "ra: " << ra << endl;
//	cout << "&ra: " << &ra << endl;
//	system("pause");
//	return 0;
//}


////引用类型做函数返回值 
//int& Add(int& left, int& right){
//	int ret = left + right;
//	return ret;
//}
//
//int main(){
//	int a = 10;
//	int b = 20;
//	//引用类型返回 
//	ret1 = Add(a, b);
//
//	int c = 40;
//	int d = 50;
//	int ret2 = Add(c, d);
//
//	printf("%d \n", ret1);
//	printf("%d \n", ret2);
//
//	system("pause");
//	return 0;
//}

//int c;
//
//void Add(int a, int b, int*& ra)
//{
//	//c=a+b;
//	//int c=a+b;
//	*ra = a + b;
//}
//int main()
//{
//	//ret引用的是返回值c，在第一个Add函数结束后，ret = 3，第二个Add函数后 ret 变成7，
//	//因为Add函数不会清理栈上的空间，所以即使Add函数结束后把开辟的空间还给了系统，
//	//但是空间内的c的值还在，ret还能访问到c的值，因此cout能打印得到Add（1,2）is：7.
//
//	int* ptr = (int *)malloc(sizeof(int));
//	//int b;
//	Add(1, 2, ptr);
//	//Add(3, 4);
//	printf("%d\n", *ptr);
//	printf("%d\n", *ptr);
//	return 0;
//}
//

////引用类型做参数
//void swap(int& left,int& right){
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//
//int main(){
//	int a = 10; 
//	int b = 20;
//	cout << "交换前:a="<< a<<" "<< "b=" << b << endl;
//	swap(a, b);
//	cout << "交换后:a="<< a <<" "<<"b="  << b << endl;
//	system("pause");
//	return 0;
//}


//指针与引用作为参数的效率
//#include<time.h>
//struct A{
//	int array[100000];
//};
//
//void Testp(A* a){
//}
//void Testq(A& a){
//}
//
//void TestTime(){
//	A a;
//	int begin1 = clock();
//	for (size_t i = 0; i < 100000; i++){
//		Testp(&a);
//	}
//	int end1 = clock();
//
//	int begin2 = clock();
//	for (size_t i = 0; i < 10000; i++){
//		Testq(a);
//	}
//	int end2 = clock();
//
//	cout << "int* time:"<<end1 - begin1 << endl;
//	cout << "int& time:"<<end2 - begin2 << endl;
//}
//int main(){
//	for (int i = 1; i < 10; i++){
//		TestTime();
//	}
//	system("pause");
//	return 0;
//}



