#include"Class.h"
#include<windows.h>
#include<iostream>
using namespace std;

int main(){
	Date d1(2018, 12, 19);
	//d1.Print();
	
	//Date d2(d1);
	//d2.Print();

	//cout <<( d1 == d2 )<< endl;
	////cout << d2.operator==(d1) << endl;

	//d2 = d1++;
	//d1.Print();
	//d2.Print();
	//d2 = ++d1;
	//d1.Print();
	//d2.Print();

	bool i = d1.ifLeapYear(2018);
	cout << "isLeapYear:" << i << endl;

	//Date d3;
	//d3 = d2;
	//d3.Print();
	//d3 + 25;
	//d3.Print();
	
	//d3 - 55;
	//d3.Print();

	//cout << (d2 == d3) << endl;
	//cout << (d2 != d3) << endl;

	//Date  d4;
	//Date  d5(1996, 10, 25);
	//d4.Print();
	//d5.Print();
	//cout <<"d4>d5?:"<<(d4 > d5) << endl;
	//cout << "d4>=d5?:"<<(d4 >= d5) << endl;

	//cout << "d4<d5?:" << (d4 < d5) << endl;
	//cout << "d4<=d5?:" << (d4 <= d5) << endl;
	system("pause");
	return 0;
}