//ģ��
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
//���ش���ĸ����ʵ�,ÿ�γ����µ����Ͷ�Ҫ���Ӷ�Ӧ���͵ĺ���
//�����׳���,��ά���Ե�

//��д���--��д�������޹ص�ͨ�õĴ���,�Ǵ��븴�õ��ֶ�
//����ģ��,ģ���Ƿ�д��̵Ļ��� 
//����ģ��--������һ����������,�ú����������޹�

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
