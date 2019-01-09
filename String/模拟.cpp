//ģ��ʵ��string��
//����Ҫ��ʵ��String��Ĺ��졢�������졢��ֵ����������Լ�����������
//#include<iostream>
//using namespace std;
//#include<string.h>
//#pragma warning(disable:4996)

#if 0
//����ϵͳĬ�ϸ�����ǳ����,��ֵ����
class String{
public:
	String(const String& s)
		:_str(s._str)
	{}
private:
	char* _str;
};
#endif


#if 0
//��ͳ��ʽ--���
class String{
public:
	//����
	String(const char* str = ""){
		/*if (str == nullptr){
		_str = new char[1];
		*_str = '\0';
		}
		else{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		}*/
		if (str == nullptr)
			_str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//��������
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	//��ֵ����
	String& operator=(const String& s){
		if (this != &s){
			//delete[] _str;
			//_str=new char[strlen(s._str)+1];
			//strcpy(_str,s._str);    //�ռ��������ʧ��

			char* ptr = new char[strlen(s._str) + 1];
			strcpy(ptr, s._str);
			delete[] _str;
			_str = ptr;
		}
		return *this;
	}
	//����
	~String(){
		if (_str){
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char *_str;
};
#endif

#if 0
//���--����
class String{
public:
	String(const char * str=""){
		if (str == nullptr)
			_str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(nullptr)
	{
		String strPtr(s._str);
		swap(_str, strPtr._str);
	}
	String& operator=(String s){
		swap(_str, s._str);
		return *this;
	}
	~String(){
		if (_str){
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void TestString(){
	String s1("hello");
	String s2(s1);
	String s3 = s2;
}

int main(){
	TestString();
	return 0;
}
#endif

#if 0
//һ������������1�ĸ���
#include<Windows.h>
#include<iostream>
using namespace std;
int main(){
	/*int x = 9999;
	int count = 0;
	while (x){
		count++;
		x = x&(x - 1);
	}
	cout << count << endl;*/
	int x = 8 & 7;
	int y = 9998 & 9997;
	cout << x << endl;
	cout << y << endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<Windows.h>
#include<iostream>
using namespace std;

int main(){
	int sorct[10] = { 0 };
	cout << "����10��ѧ���ɼ�" << endl;
	for (int i = 0; i < 10; i++){
		cin >> sorct[i];
	}
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10 - 1 - i; j++){
			if (sorct[j] < sorct[j + 1]){
				int tmp = sorct[j];
				sorct[j] = sorct[j + 1];
				sorct[j + 1] = tmp;
			}
		}
	}
	
	cout << "ѧ���ɼ��иߵ���Ϊ" << endl;
	for (int i = 0; i < 10; i++){
		cout <<sorct[i]<<" ";
	}
	cout<< endl;
	system("pause");
	return 0;
}
#endif

//ģ��ʵ��string��

#include<iostream>
using namespace std;

namespace bit{
	class string{
	public:
		typedef char* iterator;
	public:
		string(const char * str=""){
			if (str == nullptr)
				_str = "";
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const char* str, size_t size)
			:_str(new char[size + 1])
			, _capacity(size)
			, _size(size)
		{
			strncpy(_str, str, size);
			_str[size] = '\0';
		}
		string(const string& s)
			:_str(new char[s._capacity+1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}
		string& operator=(const string& s){
			if (this != &s){
				char* ptr = new char[(s._capacity) + 1];
				strcpy(ptr, s._str);

				delete[] _str;
				_str = ptr;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		~string(){
			if (_str){
				delete[] _str;
				_str = nullptr;
			}
		}
		//////////////////////////////////////
		//Iterator ������
		iterator begin(){
			return _str;
		}
		iterator end(){
			return _str + _size;
		}
		/////////////////////////////////////
		//capacity  ����
		size_t size(){
			return _size;
		}
		size_t capacity(){
			return _capacity;
		}
		bool empty(){
			return 0 == _size;
		}
		void resize(size_t newSize, char ch = 0){
			int oldSize = size();
			//�µ������ַ�С�ڱ������Ч�ַ�
			if (newSize < _size){
				_str[_size] = '0';
				_size = newSize;
			}
			else{
				int _oldCapacity = capacity();
				//�µ���Ч�ַ���������,����
				if (newSize>_oldCapacity){
					_capacity = newSize;
					//������ʱ�ռ�
					char* pStr = new char[_capacity + 1];
					strcpy(pStr,_str);
					delete[] _str;
					_str = pStr;
					//����Ĳ���ch���
					memset(_str + _size, ch, newSize - _size);
					_str[newSize] = '0';
					_size = newSize;
				}
			}
		}
		void reserve(size_t newCapacity){
			size_t oldCapacity = capacity();
			if (newCapacity > oldCapacity){
				char* pStr = new char[newCapacity + 1];
				strcpy(pStr, _str);
				delete _str;
				_str = pStr;
				_capacity = newCapacity;
			}
		}
		void clear(){
			_str[0] = '\0';
			_size = 0;
		}
		///////////////////////////////////////////////
		//
		char &operator[](size_t index){
			return _str[index];
		}
		const char &operator[](size_t index)const{
			return _str[index];
		}
		/////////////////////////////////////////////////
		//modity  �޸�
		string& operator+=(char ch){
			if (_size == _capacity){
				reserve(2 * _capacity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
//		string& operator+=(char* ch);
//		string& operator+=(const string& s);

		void push_back(char ch){
			*this += ch;
		}
		string& append(const char* str);
		string& append(string& s){
			return append(s.c_str());
		}
//		string& append(string& s, size_t pos, size_t n);
		const char* c_str()const{
			return _str;
		}

		//bool operator>(const string& s);
		//bool operator>=(const string& s);
		//bool operator<(const string& s);
		//bool operator<=(const string& s);
		//bool operator==(const string& s);
		//bool operator!=(const string& s);

		size_t find(char ch, size_t pos){
			for (size_t i = pos; i < _size; i++){
				if (_str[i] == ch){
					return i;
				}
			}
			return -1;
		}
		string substr(size_t pos, size_t n){
			int len = strlen(_str + pos);
			if (len < n){
				n = len;
			}
			return string(_str + pos, n);
		}
	private:
		char* _str;
		int _size;
		int _capacity;
	};
}




