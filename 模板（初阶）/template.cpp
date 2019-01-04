//模板
#if 0
#include<iostream>
using namespace std;
int Add(int left, int right){
	return left + right;
}
double Add(double left, double right){
	return left + right;
}
char Add(char left, char right){
	return left + right;
}

int main(){
	cout << Add(1, 2) << endl;
	cout<<Add(2.00, 3.00)<<endl;
	cout << Add('1', '2') << endl;;
	return 0;
}
#endif
//重载代码的复用率低,每次出现新的类型都要增加对应类型的函数
//代码易出错,可维护性低

//范写编程--编写与类型无关的通用的代码,是代码复用的手段
//出现模板,模板是范写编程的基础 
//函数模板--代表了一个函数家族,该函数与类型无关

#include<iostream>
using namespace std;
template<class T1,typename T2>

T1 Add(T1 left, T2 right){
	return left + right;
}

int main(){
	cout << Add<double>(1, 2.1) << endl;
	cout << Add<double>(2.00, 3.00) << endl;
	cout << Add('1', '2') << endl;;
	return 0;
}
