//����ʹ��c++���������
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
using namespace std;   //ʹ�������ռ�std--�����������
//�����ռ�
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

using N2::c;               //���������ռ��Աʹ��
using namespace N2;        //���������ռ�ʹ��

int main(){
	int g = 70;
	cout << "a:" << N1::a << endl;  //ֱ��ʹ�������ռ�
	cout << "f:" << N1::f << endl;  //�����ռ������ϲ�Ϊһ��
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
//ȱʡ����--��������һ������ʱ,������һ��Ĭ��ֵ,����ʱ��ʵ����ʵ��,��֮��Ĭ��
//ȫȱʡ����--����ȫ������Ĭ��ֵ
void add(int x = 1, int y = 2){
	cout << "x+y=" << x + y << endl;
}
//��ȱʡ����--�����������Ĭ��ֵ,�����м��
void sub(int x, int y = 1){
	cout << "x-y=" << x - y << endl;
}

int main(){

	add();                //����ʵ��,ʹ��ȱʡ����
	add(10);              //��һ��ʵ��,��������ƥ��
	add(10, 20);          //ʵ��ȫ��,ʹ��ʵ��

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
//�������� ---ͬһ��������,��������ͬ,�����б�(��������,��������,����˳��)��ͬ
int main(){
	cout << "������Ϊ:" << add(10, 20) << endl;
	cout << "������Ϊ:" << add(12.45, 10.55) << endl;
	cout << "������Ϊ:" << add('1', '2') << endl;
	system("pause");
	return 0;
}
#endif

//#include<Windows.h>
//#include<iostream>
//using namespace std;

//int main(){
//��������ֱ��ʹ��
//	int a = 10;
//	int& ra = a;
//	cout << "a:" << a << endl;
//	cout << "&a:" << &a << endl;
//	cout << "ra: " << ra << endl;
//	cout << "&ra: " << &ra << endl;
//	system("pause");
//	return 0;
//}


////������������������ֵ 
//int& Add(int& left, int& right){
//	int ret = left + right;
//	return ret;
//}
//
//int main(){
//	int a = 10;
//	int b = 20;
//	//�������ͷ��� 
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
//	//ret���õ��Ƿ���ֵc���ڵ�һ��Add����������ret = 3���ڶ���Add������ ret ���7��
//	//��ΪAdd������������ջ�ϵĿռ䣬���Լ�ʹAdd����������ѿ��ٵĿռ仹����ϵͳ��
//	//���ǿռ��ڵ�c��ֵ���ڣ�ret���ܷ��ʵ�c��ֵ�����cout�ܴ�ӡ�õ�Add��1,2��is��7.
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

////��������������
//void swap(int& left,int& right){
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//
//int main(){
//	int a = 10; 
//	int b = 20;
//	cout << "����ǰ:a="<< a<<" "<< "b=" << b << endl;
//	swap(a, b);
//	cout << "������:a="<< a <<" "<<"b="  << b << endl;
//	system("pause");
//	return 0;
//}


//ָ����������Ϊ������Ч��
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



