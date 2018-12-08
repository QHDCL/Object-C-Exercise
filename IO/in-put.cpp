////初步使用c++的输入输出
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a;
//	cin >> a;
//	cout << "Hello world!!!" << endl;
//	cout << "Hello world!!!" << endl;
//	cout << "a:"<<a << endl;
//	return 0;
//}

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
	cout << "x+y:" <<N3::add(20,20) << endl;

	cout << "g:" << g;

	system("pause");
	return 0;
}
#endif


#include<Windows.h>
#include<iostream>
using namespace std;
//缺省参数--声明或定义一个函数时,给参数一个默认值,调用时有实参用实参,反之用默认
//全缺省参数--参数全部给出默认值
void add(int x = 1, int y = 2){
	cout << "x+y=" << x+y << endl;
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
	cout << "两数和为:" << add(10,20) << endl;
	cout << "两数和为:" << add(12.45, 10.55) << endl;
	cout << "两数和为:" << add('1', '2') << endl;
	system("pause");
	return 0;
}
#endif