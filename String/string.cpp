//初步使用string类的接口
#include<Windows.h>
#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;

//int main(){
//	//string类对象的构造和类对象的容量修改
//	string s1;                    //空构造
//	string s2("I am chinese!");    //c构造
//	string s3 = "I am chinese!";   //赋值构造
//	string s4(s3);                 //拷贝构造
//	string s5(10, 'a');
//
//	string s6(s3, 5);
//
//	cout << s2 << endl;
//	cout << s2.size() << endl;
//	cout << s2.length() << endl;//返回字符串有效字符长度
//	cout << s2.capacity() << endl;//返回空间总大小
//
//	cout << s3 << endl;
//	if (s3.empty()){
//		cout << "s3是空字符串!" << endl;
//	}
//	else{
//		cout << "s3不是空字符串!" << endl;
//	}
//
//	cout << s4 << endl;
//	s4.clear();
//	cout << s4.size() << endl;
//	cout << s4.capacity() << endl;//返回空间总大小
//
//	cout << s5 << endl;
//	cout << "s5空间" << endl;//返回空间总大小
//
//	cout << s5.capacity() << endl;//返回空间总大小
//
//	//s5.resize(20, 'c');        //将有效字符改为20,多出的用'c'补充
//	cout << s5 << endl;        
//	s5.resize(40);				//将有效字符改为40, 多出的用0补充
//	cout << s5 << endl;
//
//	cout << s6 << endl;
//	s6.reserve(20);   //为字符创预留空间
//
//	cout << s6[3] << endl;   //访问
//	system("pause");
//	return 0;
//}

//string 类对象的修改
//int main(){
//	string s1;
//	s1.push_back('I');
//	cout << s1 << endl;
//	s1.append(" am");
//	cout << s1 << endl;
//	s1 += " chinese";
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;            //以c语言形式打印字符串
//
//	cout << s1.find('a') << endl;          //(正向找)返回字符串中'a'的位置,可指定从pos位找
//	cout << s1.rfind('a') << endl;			//反向找
//
//	cout << s1.substr(0, 3) << endl;      //从给定位置截取给定数量字符返回
//	system("pause");
//	return 0;
//}

//string类的应用
//#include<Windows.h>
//#include<iostream>
//#include<string>
//using namespace std;

////获取文件名的后缀
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
//	//从begin位置开始找'/'位置返回
//	int end = str.find('/',begin);     
//	//从begin位置开始,返回end-begin个数的字符
//	cout << str.substr(begin, end-begin) << endl;
//}
//
////getline()获取一行字符串
//void TestGetline(){
//	string str;
//	getline(cin, str);
//    cout<<str.substr(str.rfind(' ') + 1)<<endl;
//	cout << str.substr(str.rfind(' ') + 1).size() << endl;
//}

//class Solution{
//public:
//	//字符串中第一个只出现一次的字符
//	int firstUniqChar(string s){
//		//统计每个字符出现的次数
//		int count[256] = { 0 };
//		for (size_t i = 0; i < s.size();i++){
//			count[s[i]] += 1;
//		}
//	//按照字符次序从前往后找只出现一次的字符 
//		for (size_t i = 0; i < s.size(); i++){
//			if (count[s[i]] == 1){
//				return i;
//			}
//		}
//		return -1;
//	}
//	//反转字符
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
			// 从前往后找一个数字字符或者字母
			while (begin != end){
				if (IsNumberOrLetter(s[begin]))
					break;
				++begin;
			}
			// 从后往前找一个数字字符或者字母
			while (begin < end){
				if (IsNumberOrLetter(s[end]))
					break;
				--end;
			}
			if (begin < end) {
				// 检测start和end位置字符是否相等 或者是否不区分大小的相等
				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
					return false;
				++begin;
				--end;
			}
		}
		return true;
	}
};

//字符串相加
class Solution {
public:
	string addStrings(string num1, string num2) {
		int Lsize = num1.size();
		int Rsize = num2.size();

		//以长字符串作为外部循环
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