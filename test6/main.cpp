#include<iostream>
#include<string>
using namespace std;


/*
* 一、友元的目的：
* 
* 让一个类或者函数可以访问另一个类的私有成员。
* 
* 友元的关键字：friend;
* 
* 三种友元：
* 1、全局函数作为友元
* 2、类作为友元
* 3、成员函数作为友元
*/

// 1、全局函数作为友元
class People {

	friend void friendVisit(People *p);  // 声明全局函数friendVisit为友元函数

public:
	People() {
		m_house = "大平层";
		m_car = "BMW";
	}

	~People() { }

	string m_house;

private:
	string m_car;
};

void friendVisit(People *p) {
	cout << "访问房子" << p->m_house << endl;
	cout << "访问汽车" << p->m_car << endl;
}

int main() {

	People p1;
	friendVisit(&p1);

	return 0;
}