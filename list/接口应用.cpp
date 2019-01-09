//#include<iostream>
//using namespace std;

#if 0
#include<list>
#include<vector>
template<class T>
void Print(const T& l){
	for (const auto e : l){
		cout << e <<"--->";
	}
	cout <<"NULL"<< endl;
}

//����
void Demolist1(){
	list<int> l1;           //�յ�
	list<int> l2(4, 10);    //��4��ֵΪ10��Ԫ��
	vector<int> v1{ 1, 2, 3, 4, 5 };
	list<int> l3(v1.begin(),v1.end());  //���乹��
	list<int> l4(l3);           //��������

	Print(l2);
	Print(l3);
	Print(v1);
	Print(l4);
}

//iterator
void Demolist2(){
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	// ʹ���������������list�е�Ԫ��
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;
	// ʹ�÷�������������ӡlist�е�Ԫ��
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		cout << *it << " ";
	cout << endl;
}

//capacity
void Demolist3(){
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	
	//��ӡlist����Ч�Ľ�����
	cout << l.size() << endl;
	//�п�
	if (l.empty())
		cout << "�յ�list" << endl;
	else{
		Print(l);
	}
}

//access
void Demolist4(){
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	Print(l);

	l.front() = 100;
	l.back() = 100;
	Print(l);
}

//modifiers  ��ɾ�Ĳ�
void Demolist5(){
	vector <int> v {1, 2, 3, 4, 5};
	list<int> l(v.begin(), v.end());
	Print(l);

	l.push_front(100);
	l.push_back(100);
	Print(l);

	l.pop_front();
	l.pop_back();
	Print(l);

	l.insert(l.begin(), 99);

	//l.erase(l.end());
	Print(l);

	l.resize(15, 88);
	Print(l);

	//��������list�е�Ԫ��
	list<int> l2;
	l.swap(l2);
	Print(l);
	Print(l2);

	l2.clear();
	if (l2.empty()){
		cout << "�յ�����" << endl;
	}
	else{
		Print(l2);
	}
}

void DemoListIterator(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	list<int> l (arr, arr+sizeof(arr) / sizeof(arr[0]));
	auto it = l.begin();
	while (it != l.end()){
		//l.erase(it);   //list�ĵ�����ʧЧ��ָɾ���ڵ��,��ָ��Ľ����Ч
		//it++;			//���´�ʹ��itʱ�����it���¸�ֵ.

		//l.erase(it++);
		//it=l.erase(it);
	}
	Print(l);
}

int main(){
	Demolist1();
	//Demolist2();
	//Demolist3();
	//Demolist4();
	//Demolist5();
	//DemoListIterator();
	return 0;
}
#endif


#if 0
//list ��ģ��ʵ��
//�ײ�:��ͷ����˫��ѭ������

namespace bit{
	//ͷ���
	template<class T>
	struct ListNode{
		ListNode(const T& val = T())
			:_pPre(nullptr)
			, _pNext(nullptr)
			, _val(val)
		{}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};

	template<class T>
	class list{
		typedef ListNode<T> Node;
		typedef Node* pNode;
	public:
		list(){
			CreatHead();
		}

		list(size_t n, const T& val = T()){
			CreatHead();
			for (size_t i = 0; i < n; i++){
				push_back(val);
			}
		}

		list(T* first, T* last){
			CreatHead();
			while (first != last){
				push_back(*first);
				first++;
			}
		}

		list(list<T>& l);
		list<T>& operator=(const list<T>& l);

		~list(){
			clear();
			delete _pHead;
			_pHead = nullptr;
		}

		/////////////////////////////////////////
		//capacity ����
		size_t size()const{
			size_t count = 0;
			pNode pCur = _pHead->_pNext;
			while (pCur != _pHead){
				count++;
				pCur = pCur->_pNext;
			}
			return count;
		}

		bool empty()const{
			return _pHead->_pNext == _pHead;
		}

		void resize(size_t newSize, const T& val = T()){
			size_t oldSize = size();
			if (oldSize < newSize){
				for (size_t i = oldSize; i < newSize; i++){
					push_back(val);
				}
			}
			else{
				for (size_t i = newSize; i < oldSize; i++){
					pop_back(val);
				}
			}
		}

		////////////////////////////////////////////////////////
		//access  ����
		T& front(){
			return	_pHead->_pNext->_val;
		}
		const T& front()const{
			return	_pHead->_pNext->_val;
		}

		T& back(){
			return	_pHead->_pPre->_val;
		}
		const T& back()const{
			return	_pHead->_pPre->_val;
		}

		//////////////////////////////////////////////////
		//modify  Ԫ���޸�
		void push_back(const T& val){
			pNode pNewNode = new Node(val);
			// �Ȱ��½ڵ�β���ȥ
			pNewNode->_pNext = _pHead;
			pNewNode->_pPre = _pHead->_pPre;
			// ������ʣ������ָ��
			_pHead->_pPre = pNewNode;
			pNewNode->_pPre->_pNext = pNewNode;
		}

		void pop_back(){
			// �ҵ���ɾ���ڵ�
			pNode pDel = _pHead->_pPre;
			if (pDel != _pHead)
			{
				_pHead->_pPre = pDel->_pPre;
				pDel->_pPre->_pNext = _pHead;
				delete pDel;
			}
		}

		void push_front(const T& val){
			pNode pNewNode = new Node(val);
			// �Ȱ��½ڵ�β���ȥ
			pNewNode->_pNext = _pHead->_pNext;
			pNewNode->_pPre = _pHead;
			// ������ʣ������ָ��
			_pHead->_pNext = pNewNode;
			pNewNode->_pNext->_pPre = pNewNode;
		}

		void pop_front(){
			// �ҵ���ɾ���ڵ�
			pNode pDel = _pHead->_pNext;
			if (pDel != _pHead)
			{
				_pHead->_pNext = pDel->_pNext;
				pDel->_pNext->_pPre = _pHead;
				delete pDel;
			}
		}

		void clear(){
			pNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;

		}

		private:
		void CreatHead(){
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}

	private:
		pNode _pHead;
	};
}

int main(){
	int arr[] = { 1, 2, 3, 4 };
	bit::list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));

	L.push_back(5);
	L.push_back(6);
	L.push_back(7);
	L.push_back(8);
	cout << L.size() << endl;
	cout <<"β���Ԫ��"<< L.back() << endl;
	cout <<"ͷ���Ԫ��"<< L.front() << endl;

	L.pop_back();
	L.pop_front();
	cout << L.size() << endl;
	cout << "β���Ԫ��" << L.back() << endl;
	cout << "ͷ���Ԫ��" << L.front() << endl;

	return 0;
}
#endif

#if 0
#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

bool cmp(int x, int y)
{
	return x > y;
}

template<class T>
void Print1(const T& t){
	for (auto e : t){
		cout << e <<" ";
	}
	cout << endl;
}

void DemoSortVector(){
	vector<int> v { 2, 34, 67, 432, 23 };
	Print1(v);

	sort(v.begin(), v.end());   //ϵͳ����,Ĭ������
	Print1(v);

	sort(v.begin(), v.end(),cmp);//����������,����ʽ
	Print1(v);
}

int main(){
	DemoSortVector();
	return 0;
}
#endif

#include<iostream>
using namespace std;
#include<list>

bool cmp(int x, int y)
{
	return x > y;
}

template<class T>
void Print(T& t){
	for (auto e : t){
		cout << e << "-->";
	}
	cout << "NULL" << endl;
}

void DemoListSort(){
	list<int> L{ 12, 2, 43, 54, 32 };
	Print(L);
	//sort(L.begin(), L.end(),cmp);
	L.sort();    //Ĭ������
	Print(L);

	L.sort(cmp);   
	Print(L);
}

int main(){
	DemoListSort();
	return 0;
}