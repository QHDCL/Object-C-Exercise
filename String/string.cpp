//����ʹ��string��Ľӿ�
#include<Windows.h>
#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;

//int main(){
//	//string�����Ĺ���������������޸�
//	string s1;                    //�չ���
//	string s2("I am chinese!");    //c����
//	string s3 = "I am chinese!";   //��ֵ����
//	string s4(s3);                 //��������
//	string s5(10, 'a');
//
//	string s6(s3, 5);
//
//	cout << s2 << endl;
//	cout << s2.size() << endl;
//	cout << s2.length() << endl;//�����ַ�����Ч�ַ�����
//	cout << s2.capacity() << endl;//���ؿռ��ܴ�С
//
//	cout << s3 << endl;
//	if (s3.empty()){
//		cout << "s3�ǿ��ַ���!" << endl;
//	}
//	else{
//		cout << "s3���ǿ��ַ���!" << endl;
//	}
//
//	cout << s4 << endl;
//	s4.clear();
//	cout << s4.size() << endl;
//	cout << s4.capacity() << endl;//���ؿռ��ܴ�С
//
//	cout << s5 << endl;
//	cout << "s5�ռ�" << endl;//���ؿռ��ܴ�С
//
//	cout << s5.capacity() << endl;//���ؿռ��ܴ�С
//
//	//s5.resize(20, 'c');        //����Ч�ַ���Ϊ20,�������'c'����
//	cout << s5 << endl;        
//	s5.resize(40);				//����Ч�ַ���Ϊ40, �������0����
//	cout << s5 << endl;
//
//	cout << s6 << endl;
//	s6.reserve(20);   //Ϊ�ַ���Ԥ���ռ�
//
//	cout << s6[3] << endl;   //����
//	system("pause");
//	return 0;
//}

//string �������޸�
//int main(){
//	string s1;
//	s1.push_back('I');
//	cout << s1 << endl;
//	s1.append(" am");
//	cout << s1 << endl;
//	s1 += " chinese";
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;            //��c������ʽ��ӡ�ַ���
//
//	cout << s1.find('a') << endl;          //(������)�����ַ�����'a'��λ��,��ָ����posλ��
//	cout << s1.rfind('a') << endl;			//������
//
//	cout << s1.substr(0, 3) << endl;      //�Ӹ���λ�ý�ȡ���������ַ�����
//	system("pause");
//	return 0;
//}

//string���Ӧ��
//#include<Windows.h>
//#include<iostream>
//#include<string>
//using namespace std;

////��ȡ�ļ����ĺ�׺
//void Filename(){
//	string str1("chen.txt");
//	string str2("F:\\work\\test.cpp");
//	string str3 = str1.substr(str1.rfind('.') + 1);
//	string str4 = str2.substr(str2.rfind('.') + 1);
//	cout << str3 << endl;
//	cout << str4 << endl;
//
//	string str = "http://www.baidu.com/aoq";
//	int begin = str.find("://") + 3;  
//	//��beginλ�ÿ�ʼ��'/'λ�÷���
//	int end = str.find('/',begin);     
//	//��beginλ�ÿ�ʼ,����end-begin�������ַ�
//	cout << str.substr(begin, end-begin) << endl;
//}
//
////getline()��ȡһ���ַ���
//void TestGetline(){
//	string str;
//	getline(cin, str);
//    cout<<str.substr(str.rfind(' ') + 1)<<endl;
//	cout << str.substr(str.rfind(' ') + 1).size() << endl;
//}

//class Solution{
//public:
//	//�ַ����е�һ��ֻ����һ�ε��ַ�
//	int firstUniqChar(string s){
//		//ͳ��ÿ���ַ����ֵĴ���
//		int count[256] = { 0 };
//		for (size_t i = 0; i < s.size();i++){
//			count[s[i]] += 1;
//		}
//	//�����ַ������ǰ������ֻ����һ�ε��ַ� 
//		for (size_t i = 0; i < s.size(); i++){
//			if (count[s[i]] == 1){
//				return i;
//			}
//		}
//		return -1;
//	}
//	//��ת�ַ�
//	string reversesting(string s){
//		if (s.empty()){
//			return s;
//		}
//		size_t begin = 0;
//		size_t end = s.size() - 1;
//
//		while (begin < end){
//			swap(s[begin], s[end]);
//			begin++;
//			end--;
//		}
//		return s;
//	}
//};
//
//int main(){
//
//	//Filename();
//	//TestGetline();
//
//	system("pause");
//	return 0;
//}



#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool IsNumberOrLetter(char c){
		if ((c >= '0'&&c <= '9') ||
			(c >= 'a'&&c <= 'z') ||
			(c >= 'A'&&c <= 'Z')){
			return true;
		}
		return false;
	}
	bool isPalindrome(string s) {
		if (s.empty())
			return true;
		int begin = 0;
		int end = s.size() - 1;
		char* p = (char*)s.c_str();
		while (begin < end)
		{
			// ��ǰ������һ�������ַ�������ĸ
			while (begin != end){
				if (IsNumberOrLetter(s[begin]))
					break;
				++begin;
			}
			// �Ӻ���ǰ��һ�������ַ�������ĸ
			while (begin < end){
				if (IsNumberOrLetter(s[end]))
					break;
				--end;
			}
			if (begin < end) {
				// ���start��endλ���ַ��Ƿ���� �����Ƿ����ִ�С�����
				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
					return false;
				++begin;
				--end;
			}
		}
		return true;
	}
};

//�ַ������
class Solution {
public:
	string addStrings(string num1, string num2) {
		int Lsize = num1.size();
		int Rsize = num2.size();

		//�Գ��ַ�����Ϊ�ⲿѭ��
		if (Lsize<Rsize){
			swap(num1, num2);
			swap(Lsize, Rsize);
		}

		string strRet;
		strRet.reserve(Lsize + 1);

		char cRet = 0;
		char cstep = 0;

		for (size_t i = 0; i < Lsize; ++i){
			cRet = num1[Lsize - i - 1] - '0' + cstep;
			cstep = 0;

			if (i < Rsize){
				cRet += num2[Rsize - i - 1] - '0';
			}

			if (cRet >= 10){
				cRet -= 10;
				cstep = 1;
			}

			strRet += cRet + '0';
		}
		if (cstep)
			strRet += '1';
		reverse(strRet.begin(), strRet.end());
		return strRet;
	}
};

int main(){
	return 0;
}