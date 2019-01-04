//#include<iostream>
//using namespace std;
//#include<Windows.h>
//#include<malloc.h>

#if 0
int main(){
	// 动态申请一个int类型的空间
	int* p1 = new int;
	// 动态申请一个int类型的空间并初始化为10
	int* p2 = new int(10);
	// 动态申请10个int类型的空间
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
	//malloc申请单个Test类型空间
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);

	//申请10个Test类型的空间
	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
	free(p2);
}
void Test2(){
	//new申请单个Test类型的空间
	Test* p3 = new Test;
	delete p3;

	//申请10个test类型的空间
	Test* p4 = new Test[10];
	delete[] p4;
	
}

//在申请自定义空间时,new会调用构造函数,delete会调用析构函数,malloc和free不会
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
//设计一个类,该类只能在堆上创建对象-------构造函数私有化
//1.将类的构造函数,拷贝声明私有化
//2.提供一个静态的成员函数,在该函数中完成堆对象创建
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
	//只需声明
	HeapOnly(){}
	HeapOnly(const HeapOnly&);

	//c++11
	//HeapOnly(const HeapOnly&) = delete;
};

int main(){
	//HeapOnly H;   错误
	HeapOnly* H1 = HeapOnly::CreateObj();
	H1->print();
	system("pause");
	return 0;
}
#endif

#if 0
//创建一个类,只能在栈上创建对象(不能再堆上)----构造函数私有化(即屏蔽new的功能)
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
		return StackOnly();//无名对象
	}
private:
	StackOnly() {}
};
int main(){
	//StackOnly s;
	//s.CreateObject();

	StackOnly s(StackOnly::CreateObject());  //拷贝构造 StackOnly::CreateObject()临时空间
	s.t();

	//StackOnly* s = new StackOnly;  //错误
	system("pause");

	return 0;
}
#endif


#if 0
//创建一个类,不可被拷贝---私有化拷贝构造,赋值重载
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
	NoCopy N2 = N1;  //拷贝
	//NoCopy N2;
	//N2 = N1;  //赋值
}

int main(){
	Test();

	//NoCopy N2(N1);
	system("pause");
	return 0;
}
#endif

#if 0
//定位new表达式----相当于把new的两步(创建空间、调用构造函数)分开做
//配合内存池使用 
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
	// p现在指向的只不过是与Test对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
	Test* p = (Test*)malloc(sizeof(Test));
	new(p) Test; // 注意：如果Test类的构造函数有参数时，此处需要传参
	delete  p;
}

int main(){
	Test1();
	system("pause");
	return 0;
}
#endif

#if 0
// 将程序编译成x64的进程，运行下面的程序试试？
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

//单例模式---单例模式就是一个类只能被实例化一次 ，更准确的说是只能有一个实例化的对象的类。
//饿汉模式--不管用不用,程序启动就会创建一个唯一的实例对象
 
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
//Singleton* Singleton::m_instace;//在程序入口之前完成单例对象的实例化
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

//懒汉模式
// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
// 缺点：复杂

#if 0
#include<Windows.h>
#include <mutex>
#include <thread>

class Singleton{
public:
	static Singleton* GetInstace(){
		if (m_instace == nullptr){			//双层检测--保证阻塞机会少.			
			m_mtx.lock();
			if (m_instace == nullptr){     //加锁--保证多线程安全
				m_instace = new Singleton;
			}
			m_mtx.unlock();
		}
		return m_instace;
	}

	void Print(){
		cout << "Print"<<this << endl;
	}
  //实现一个内嵌垃圾回收类
	class Delete{
	public:
		~Delete(){
			if (Singleton::m_instace){
				free(Singleton::m_instace);
				cout << "对象已清理!!!" << endl;
			}
		}
		static Delete _D;
	};
private:
	Singleton(){}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton* m_instace;		//单例对象指针
	static mutex m_mtx;					//互斥锁
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
//饿汉模式
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