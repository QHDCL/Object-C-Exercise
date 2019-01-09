#if 0
#include<iostream>
using namespace std;
#include<vector>
#include<string>

//vector ����
void Testvector1(){
	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(v2);
	int array[] = { 1, 2, 3, 4, 5 };
	vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));
	string s("hello");
	s += "hhhh";
	vector<char> v5(s.begin(), s.end());
}

//vector����
void Testvector2(){
	size_t sz;
	vector<int> foo;
	foo.reserve(100);       //Ԥ���ռ�,����ı�����ЧԪ�ظ���
	sz = foo.capacity();
	cout << sz << endl;
	cout << foo.size() << endl;
	cout << "foo capacity fown!" << endl;
	for (int i = 0; i < 100; i++){
		foo.push_back(i);
		if (sz != foo.capacity()){
			sz = foo.capacity();
			cout << "capacity change" << sz << endl;
		}
	}
	cout << foo.size()<<endl;
}

//vector ������
void Testvector3(){
	int array[] = { 1, 2, 4, 5, 6 };
	vector<int> v1(array, array + sizeof(array) / sizeof(array[0]));

	vector<int>::iterator it = v1.begin();
	//while (it != v1.end()){
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	//��Χforѭ��.e����v��ÿ��Ԫ��
	for (auto& e : v1){
		cout << e << " ";
	}
	cout << endl;

	//c++11�ṩ���б��ʼ��
	vector<int> v2{ 1, 2, 3, 4, 5 };
	for (size_t i = 0; i < v2.size(); i++){
		cout << v2[i] << " ";
	}
	cout << endl;
}

//vector ��ɾ�Ĳ�
void Testvector4(){
	vector<int> v1;
	v1.push_back(1);   //β��
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	cout << "v1�е���Ч���ݸ���:" << v1.size() << "�ֱ�Ϊ:" <<endl;
	for (auto e : v1){
		cout << e << " ";
	}
	cout << endl;
	v1.pop_back();    //βɾ
	v1.pop_back();
	cout << "v1�е���Ч���ݸ���:" << v1.size() << "�ֱ�Ϊ:" << endl;
	for (auto e : v1){
		cout << e << " ";
	}
	cout << endl;
}



//find insert  erase
void Testvector5(){
	vector<int> v1{ 1, 2, 3, 4, 5 };
	for (auto e : v1){
		cout << e << " ";
	}
	cout << endl;

	//ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);

	//ʹ��insert��posλ��ǰ����6
	v1.insert(pos, 6);
	for (auto e : v1){
		cout << e << " ";
	}
	cout << endl;

	//ʹ��eraseɾ��posλ�õ�����
	//ǰ��ʹ����insert,�ᵼ��iteratorʧЧ,�����¸���posλ��
	pos = find(v1.begin(), v1.end(), 3);
	v1.erase(pos);
	for (auto e : v1){
		cout << e << " ";
	}
	cout << endl;
}

//void swap(vector& v)
//��������vector��ֵ
void Testvector6(){
	vector<int>v{ 1, 2, 3, 4, 5 };
	cout << "����ǰ" << endl;
	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	vector<int> swapv{7,2,3};
	cout << "swapv data:";
	for (size_t i = 0; i < swapv.size(); ++i)
	{
		cout << swapv[i] << " ";
	}
	cout << endl;

	cout << "������" << endl;
	swapv.swap(v);
	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	cout << "swapv data:";
	for (size_t i = 0; i < swapv.size(); ++i)
	{
		cout << swapv[i] << " ";
	}
	cout << endl;
}

int main(){
//	Testvector1();
//	Testvector2();
//	Testvector3();
//	Testvector4();
//	Testvector5();
	Testvector6();
	return 0;
}
#endif

#include<assert.h>
#include<iostream>
using namespace std;

namespace bit{
	template<class T>
	class vector{
	public:
		typedef T* iterator;
		typedef T* reverse_iterator;
	public:
		//Ĭ�Ϲ���
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		//���첢��ʼ��
		vector(size_t n, const T& data = T()){
			_start = new T[n];
			for (size_t i = 0; i < n; i++){
				_start[i] = data;
			}
			_finish = _start + n;
			_endOfStorage = _finish;
		}

		//���乹��
	     vector(T* first, T* last){
			size_t  size = last - first;
			_start = new T[size];
			_finish = _start;
			while (first != last){
				*_finish = *first;
				_finish++;
				first++;
			}
			_endOfStorage = _finish;
		}

		////��������
		//vector(const vector<T>& v)
		//	:_start(new T[v.size()])
		//	, _finish(v._start+v.size())
		//	, _endOfStorage(_finish)
		//{
		//	for (size_t i = 0; i < v.size(); i++){
		//		_start[i] = v._start[i];
		//	}
		//}

		////��ֵ���������
		//vector<T>& operator= (const vector<T>& v){
		//	if (this != &v){
		//		size_t size = v._endOfStorage - v._start;
		//		T* pStart = new T[size];
		//		memcpy(pStart, v._start,size*sizeof(T));
		//		delete[] _start;
		//		_start = pStart;
		//		_finish = _start+size;
		//		_endOfStorage = _finish;
		//	}
		//	return *this;
		//}

		 //��ֵ���������
		 vector<T>& operator= (const vector<T>& v){
			 swap(v);
			 return *this;
		 }
		//����
		~vector(){
			if (_start){
				delete[] _start;
				_start = _finish = _endOfStorage = nullptr;
			}
		}

		//����
		void Swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}
		////////////////////////////////////////
		//iterator   ������
		iterator begin(){
			return _start;
		}

		iterator end(){
			return _finish;
		}

		reverse_iterator rbegin(){
			retrun end();
		}
		reverse_iterator rend(){
			return begin();
		}
		//////////////////////////////////////////
		//capacity
		//��Ч���ݸ���
		size_t size()const{
			return _finish - _start;
		}
		//����
		size_t  capacity()const{
			return _endOfStorage - _start;
		}
		//�п�
		bool eamty()const{
			return _finish == _start;
		}
		//����
		void reserve(size_t newCapacity){
			size_t oldCapacity = capacity();
			if (newCapacity > oldCapacity){
				size_t oldSize = size();
				T* tmp = new T[newCapacity];
				memcpy(tmp, _start, oldSize*sizeof(T));
				delete[] _start;
				_start = tmp;
				_finish = _start + oldSize;
				_endOfStorage = _start + newCapacity;
			}
		}
		//�ñ���Ч���ݸ���
		void resize(size_t newSize, const T& data = T()){
			size_t oldSize = size();
			//����
			if (newSize <= oldSize){
				_finish = _start + newSize;
			}
			else{
				//����
				if (newSize > capacity()){
					T* tmp = new T[newSize];
					memcpy(tmp, _start, sizeof(T) * oldSize);
					delete[] _start;
					_start = tmp;
					_endOfStorage = _start + newSize;
				}
				for (size_t i = oldSize; i < newSize; i++){
					_start[i] = data;
				}
				_finish = _start + newSize;
			}
		}

		////////////////////////////////////////////////
		//����
		T& operator[](size_t index){
			assert(index < size());
			return _start[index];
		}
		const T& operator[](size_t index)const{
			assert(index < size());
			return _start[index];
		}
		T& front(){
			return _start[0];
		}
		const T& front()const{
			return _start[0];
		}

		T& back(){
			return *(_finish-1);
		}
		const T& back()const{
			return *(_finish-1);
		}

		/////////////////////////////////////
		//midfy  Ԫ���޸�
		void push_back(const T& data){
			if (size() == capacity()){
				reserve(2 * (_endOfStorage - _start)+3);
			}
			*_finish++ = data;
		}

		void pop_back(){
			_finish--;
		}
		iterator insert(iterator pos, const T& data);
		iterator erase(iterator pos);
	private:
		T* _start;
		T* _finish;
		T* _endOfStorage;
	};
}

template<class T>
void Print( T& v){
	for (auto& e : v){
		cout << e << " ";
	}
	cout << endl;
}

void Testvector1(){
	bit::vector<int> v1(5, 1);
	bit::vector<int> v2;
	//bit::vector<int> v3(v1);
	bit::vector<int> v4 = v1;
	
	cout << v2.eamty() << endl;
	cout << v4.capacity() << endl;
	cout << v1[0] << " "<< v1.front()<< endl;
	cout << v1.back() << endl;
	Print(v1);
}

void Testvector2(){
	bit::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	Print(v);
	v.pop_back();
	Print(v);
}


void Testvector3(){
	bit::vector<int> v(1,1);
	cout << "����:" << v.capacity()<< "  " << "��С:" <<v.size() << endl;
	Print(v);

	v.reserve(10);
	cout << "����:" << v.capacity() << "  " << "��С:" << v.size() << endl;

	v.resize(4);
	cout << "����:" << v.capacity() << "  " << "��С:" << v.size() << endl;


	v.resize(8,9);
	cout << "����:" << v.capacity() << "  " << "��С:" << v.size() << endl;
	Print(v);

}

int main(){
	//Testvector1();
	//Testvector2();
	Testvector3();
	return 0;
}











