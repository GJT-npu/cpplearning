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

/*
1、全局函数作为友元
*/
//class People {
//
//	friend void friendVisit(People *p);  // 声明全局函数friendVisit为友元函数
//
//public:
//	People() {
//		m_house = "大平层";
//		m_car = "BMW";
//	}
//
//	~People() { }
//
//	string m_house;
//
//private:
//	string m_car;
//};
//
//void friendVisit(People *p) {
//	cout << "访问房子" << p->m_house << endl;
//	cout << "访问汽车" << p->m_car << endl;
//}
//
//int main() {
//
//	People p1;
//	friendVisit(&p1);
//
//	return 0;
//}

/*
* 2、类作为友元
*    声明两个友元类People和Peoplefriend，Peoplefriend可以访问People的私有成员。
*    注意：在声明友元类时，需要在友元类的前面加上关键字friend。
*    在People中 声明 friend class Peoplefriend; 那么Peoplefriend类就可以访问People类的私有成员。
*/
//class People;  // 前向声明
//
//class Peoplefriend {
//public:
//	Peoplefriend() { }
//	~Peoplefriend() { }
//	void visit(People *p);  //成员函数声明
//};
//
//class People {
//	friend class Peoplefriend;  // 声明Peoplefriend类为友元类
//public:
//	People() {
//		m_house = "大平层";
//		m_car = "BMW";
//	}
//	~People() { }
//	string m_house;
//private:
//	string m_car;
//
//};
//
//// 成员函数实现
//void Peoplefriend::visit(People *p) {
//	cout << "访问房子" << p->m_house << endl;
//	cout << "访问汽车" << p->m_car << endl;
//}
//
//int main() {
//
//	People p1;
//	Peoplefriend p2;
//
//	p2.visit(&p1);  // 调用友元类的成员函数访问People类的私有成员
//
//	return 0;
//}

/*
* 3、成员函数作为友元
*	 Peoplefriend的某个函数可以访问People的私有成员变量
*	 在People类里面声明友元成员函数 friend void Peoplefriend::visitAll(People *p);
*/
class People;

class Peoplefriend {
public:
	Peoplefriend() {

	}
	
	void visitAll(People *p);
	void visitPub(People *p);
};


class People {
	friend void Peoplefriend::visitAll(People *p); //  声明友元成员函数
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

void Peoplefriend::visitAll(People *p) {
	cout << "访问房子" << p->m_house << endl;
	cout << "访问汽车" << p->m_car << endl;
}
void Peoplefriend::visitPub(People *p) {
	cout << "访问房子" << p->m_house << endl;
	//cout << "访问汽车" << p->m_car << endl;
}


int main() {

	People p1;
	Peoplefriend p2;

	p2.visitAll(&p1);
	p2.visitPub(&p1);

	return 0;
}


