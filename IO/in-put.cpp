////����ʹ��c++���������
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
	cout << "x+y:" <<N3::add(20,20) << endl;

	cout << "g:" << g;

	system("pause");
	return 0;
}
#endif


#include<Windows.h>
#include<iostream>
using namespace std;
//ȱʡ����--��������һ������ʱ,������һ��Ĭ��ֵ,����ʱ��ʵ����ʵ��,��֮��Ĭ��
//ȫȱʡ����--����ȫ������Ĭ��ֵ
void add(int x = 1, int y = 2){
	cout << "x+y=" << x+y << endl;
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
	cout << "������Ϊ:" << add(10,20) << endl;
	cout << "������Ϊ:" << add(12.45, 10.55) << endl;
	cout << "������Ϊ:" << add('1', '2') << endl;
	system("pause");
	return 0;
}
#endif