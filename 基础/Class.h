
#include<iostream>
using namespace std;
class Date{

public:
	//默认构造函数
	Date(int year = 1900, int month = 1, int day = 1){
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值运算符重载
	Date& operator=(const Date& d){
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	bool ifLeapYear(int year){
		if ((year % 4 && year % 100) || (year % 400)){
			return true;
		}
		return false;
	}

	Date operator+(int days){
		_day += days;
		if (_day > 30){
			_month += 1;
			_day -= 30;
			if (_month > 12){
				_year += 1;
				_month -= 12;
			}
		}
		return *this;
	}
	Date operator-(int days){
		_day -= days;
		while (_day < 0){
			if (_day < 0){
				_month -= 1;
				_day += 30;
				if (_month < 0){
					_year -= 1;
					_month += 12;
				}
			}
		}
		return *this;
	}
/*
	int operator-(const Date& d){
		
	}*/

	Date& operator++(){
		_day += 1;
		return *this;
	}
	Date operator++(int){
		Date temp(*this);
		_day += 1;
		return temp;
	}
	Date& operator--(){
		_day -= 1;
		return *this;
	}
	Date operator--(int){
		Date temp(*this);
		_day -= 1;
		return temp;
	}
	bool operator>(const Date& d)const{
		return _year > d._year ||
			_year == d._year&&_month > d._month ||
			_year == d._year&&_month == d._month&&_day > d._day;
	}
	bool operator>=(const Date& d)const{
		return _year >= d._year ||
			_year == d._year&&_month >= d._month ||
			_year == d._year&&_month == d._month&&_day >= d._day;
	}
	bool operator<(const Date& d)const{
		return _year < d._year ||
			_year == d._year&&_month < d._month ||
			_year == d._year&&_month == d._month&&_day < d._day;
	}
	bool operator<=(const Date& d)const{
		return _year <= d._year ||
			_year == d._year&&_month <= d._month ||
			_year == d._year&&_month == d._month&&_day <= d._day;
	}
	bool operator==(const Date& d)const{
		return _year == d._year&&
			_month == d._month&&
			_day == d._day;
	}
	bool operator!=(const Date& d)const{
		return !(*this == d);
	}
	void Print()const{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int  _year;
	int _month;
	int _day;
};



