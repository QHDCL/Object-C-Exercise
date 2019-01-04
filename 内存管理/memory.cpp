//#include<iostream>
//using namespace std;
//#include<Windows.h>
//#include<malloc.h>

#if 0
int main(){
	// ��̬����һ��int���͵Ŀռ�
	int* p1 = new int;
	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
	int* p2 = new int(10);
	// ��̬����10��int���͵Ŀռ�
	int* p3 = new int[10];

	delete p1;
	delete p2;
	delete[] p3;
}
#endif

#if 0
class Test{
public:
	Test(){
		cout <<"Test()"<< this << endl;
	}
	~Test(){
		cout << "~Test()" << this << endl;
	}
private:
	int _num;
};

void Test1(){
	//malloc���뵥��Test���Ϳռ�
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);

	//����10��Test���͵Ŀռ�
	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
	free(p2);
}
void Test2(){
	//new���뵥��Test���͵Ŀռ�
	Test* p3 = new Test;
	delete p3;

	//����10��test���͵Ŀռ�
	Test* p4 = new Test[10];
	delete[] p4;
	
}

//�������Զ���ռ�ʱ,new����ù��캯��,delete�������������,malloc��free����
int main(){
	cout << "Test1()" << endl;
	Test1();

	cout << "Test2()" << endl;
	Test2();

	system("pause");
	return 0;
}
#endif

#if 0
//���һ����,����ֻ���ڶ��ϴ�������-------���캯��˽�л�
//1.����Ĺ��캯��,��������˽�л�
//2.�ṩһ����̬�ĳ�Ա����,�ڸú�������ɶѶ��󴴽�
class HeapOnly{
public:
	static 	HeapOnly* CreateObj(){
		cout << "chen" << endl;
		return new HeapOnly;
	}
	void print(){
		cout << "hello" << endl;
	}
private:
	//c++98
	//ֻ������
	HeapOnly(){}
	HeapOnly(const HeapOnly&);

	//c++11
	//HeapOnly(const HeapOnly&) = delete;
};

int main(){
	//HeapOnly H;   ����
	HeapOnly* H1 = HeapOnly::CreateObj();
	H1->print();
	system("pause");
	return 0;
}
#endif

#if 0
//����һ����,ֻ����ջ�ϴ�������(�����ٶ���)----���캯��˽�л�(������new�Ĺ���)
//class StackOnly{
//public :
//	StackOnly(){}
//private:
//	void* operator new(size_t size);
//	void operator delete(void* p);
//};
class StackOnly
{
public:
	void t(){
		cout << "yin" << endl;
	}
	static StackOnly CreateObject()
	{
		return StackOnly();//��������
	}
private:
	StackOnly() {}
};
int main(){
	//StackOnly s;
	//s.CreateObject();

	StackOnly s(StackOnly::CreateObject());  //�������� StackOnly::CreateObject()��ʱ�ռ�
	s.t();

	//StackOnly* s = new StackOnly;  //����
	system("pause");

	return 0;
}
#endif


#if 0
//����һ����,���ɱ�����---˽�л���������,��ֵ����
class NoCopy{
public:
	NoCopy(){
		cout << "NoCopy()" << this << endl;
	}
private:
	//NoCopy(const NoCopy&);
	//NoCopy& operator=(const NoCopy&);
};

void Test(){
	NoCopy N1;	

	NoCopy N2(N1);
	NoCopy N2 = N1;  //����
	//NoCopy N2;
	//N2 = N1;  //��ֵ
}

int main(){
	Test();

	//NoCopy N2(N1);
	system("pause");
	return 0;
}
#endif

#if 0
//��λnew���ʽ----�൱�ڰ�new������(�����ռ䡢���ù��캯��)�ֿ���
//����ڴ��ʹ�� 
class Test{
public:
	Test()
		: _data(0){
		cout << "Test():" << this << endl;
	}
	~Test(){
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

void Test1(){
	// p����ָ���ֻ��������Test������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
	Test* p = (Test*)malloc(sizeof(Test));
	new(p) Test; // ע�⣺���Test��Ĺ��캯���в���ʱ���˴���Ҫ����
	delete  p;
}

int main(){
	Test1();
	system("pause");
	return 0;
}
#endif

#if 0
// ����������x64�Ľ��̣���������ĳ������ԣ�
#include <iostream>
using namespace std;
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif


#include<iostream>
using namespace std;

//����ģʽ---����ģʽ����һ����ֻ�ܱ�ʵ����һ�� ����׼ȷ��˵��ֻ����һ��ʵ�����Ķ�����ࡣ
//����ģʽ--�����ò���,���������ͻᴴ��һ��Ψһ��ʵ������
 
//class Singleton{
//public:
//	static Singleton* GetInstace(){
//		return m_instace;
//	}
//	void Print(){
//		cout << "Print()" << this << endl;
//	}
//	void Exit(){
//		cout << "Exit()" << this << endl;
//	}
//private:
//	Singleton(){}
//
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//private:
//	static Singleton* m_instace=new Singleton;
//};
//
//Singleton* Singleton::m_instace;//�ڳ������֮ǰ��ɵ��������ʵ����
//
//int main(){
//	Singleton *p1 = Singleton::GetInstace();
//	Singleton *p2 = Singleton::GetInstace();
//	p1->Print();
//	p2->Exit();
//	if (p1 == p2){
//		cout << p1 <<" "<< p2 << endl;
//	}
//	return 0;
//}

//����ģʽ
// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
// ȱ�㣺����

#if 0
#include<Windows.h>
#include <mutex>
#include <thread>

class Singleton{
public:
	static Singleton* GetInstace(){
		if (m_instace == nullptr){			//˫����--��֤����������.			
			m_mtx.lock();
			if (m_instace == nullptr){     //����--��֤���̰߳�ȫ
				m_instace = new Singleton;
			}
			m_mtx.unlock();
		}
		return m_instace;
	}

	void Print(){
		cout << "Print"<<this << endl;
	}
  //ʵ��һ����Ƕ����������
	class Delete{
	public:
		~Delete(){
			if (Singleton::m_instace){
				free(Singleton::m_instace);
				cout << "����������!!!" << endl;
			}
		}
		static Delete _D;
	};
private:
	Singleton(){}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton* m_instace;		//��������ָ��
	static mutex m_mtx;					//������
};

void func(int n){
	cout << Singleton::GetInstace() << endl;
}

Singleton* Singleton::m_instace = nullptr; 
mutex Singleton::m_mtx;		
Singleton::Delete _D;

void Test(){
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
	cout << Singleton::GetInstace() << endl;
	cout << Singleton::GetInstace() << endl;

	Singleton::Delete d;
	d._D;
}
int main(){
	Test();

//	Singleton* s1 = Singleton::GetInstace();
//	Singleton* s2 = Singleton::GetInstace();
//  s1->Print();
//  s2->Print();
//	cout << s1 << endl;
//	cout << s2 << endl;
	system("pause");
	return 0;
}
#endif

#if 0
//����ģʽ
#include<iostream>
using namespace std;
class Singleton{
public:
	static Singleton* GetInstace(){
		return m_instace;
	}
	static Singleton* m_instace;
private:
	Singleton(){}
};
Singleton* Singleton::m_instace=new Singleton;
int main()
{
	Singleton *t1 = Singleton::GetInstace();
	Singleton *t2 = Singleton::GetInstace();
	cout << t1 << " " << t2 << endl;
	system("pause");
	return 0;
}
#endif

#include<iostream>
using namespace std;
class T{
public:
	T(){
	}
	~T(){
		if (p != NULL){
			//free(p);
			delete p;
		}
		cout << "~T()" << endl;
	}
private:
	int * p = (int *)malloc(sizeof(int));
	
};

void Te(){
	T t;
}
int main(){
	Te();
	return 0;
}