#include <iostream>
#include <string>
using namespace std;

/*
* 一、加法运算符的重载
*     1、成员函数重载
*     2、友元全局函数重载
* 
* 二、左移运算符的重载
*/

//class Complex {
//
//	friend Complex operator-(Complex &a , Complex &b);
//	friend ostream & operator<<(ostream &cout , Complex a);
//
//public:
//	Complex() :real(0) , image(0) {
//
//	}
//
//	Complex(int real , int image) {
//		this->real = real;
//		this->image = image;
//	}
//
//	~Complex() { }
//
//	// 复数加法函数
//	Complex add(Complex &other) {
//		Complex ret;
//		ret.real = this->real + other.real;
//		ret.image = this->image + other.image;
//		return ret;
//	}
//
//	// 成员函数重载
//	Complex operator+(Complex &other) {
//		Complex ret;
//		ret.real = this->real + other.real;
//		ret.image = this->image + other.image;
//		return ret;
//	}
//
//	void ShowComplex() {
//		cout << "复数是： " << real << " + " << image << "i" << endl;
//	}
//
//private:
//	int real;
//	int image;
//};
//
//// 友元全局函数重载
//Complex operator-(Complex &a , Complex &b) {
//	Complex ret;
//	ret.real = a.real - b.real;
//	ret.image = a.image - b.image;
//	return ret;
//}
//
//ostream & operator<<(ostream &cout , Complex a) {
//	cout << "<<重载：" << a.real << "+" << a.image << endl;
//	return cout;
//}
//
//int main() {
//
//	Complex a(5 , 10);
//	a.ShowComplex();
//	Complex b(6 , 8);
//	b.ShowComplex();
//
//	Complex c = a.add(b);
//	cout << "c: ";
//	c.ShowComplex();
//
//	Complex d = a + b;
//	cout << "d: ";
//	d.ShowComplex();
//
//	Complex e = a - b;
//	cout << "e: ";
//	e.ShowComplex();
//
//	cout << d << endl;
//
//	return 0;
//}

/*
* 三、递增重载
*     1、前置递增
*     2、后置递增
*/
//class Complex {
//	friend ostream &operator<<(ostream &c , const Complex &a);
//public:
//	// 默认构造函数
//	Complex() :real(0) , image(0) { }
//
//	// 带参数的构造函数
//	Complex(int real , int image) {
//		this->real = real;
//		this->image = image;
//	}
//
//	// 析构函数
//	~Complex() { }
//
//	// 前置递增
//	Complex &operator++() {
//		this->real += 1;
//		return *this;
//	}
//
//	// 后置递增
//	Complex operator++(int) {
//		Complex temp = *this; // 保存当前对象的状态
//		this->real += 1; // 递增操作
//		return temp; // 返回递增前的状态
//	}
//
//private:
//	int real;
//	int image;
//};
//
//ostream &operator<<(ostream &c , const Complex &a) {
//	c << a.real << "+" << a.image << "i" << endl;
//	return c;
//}
//
//int main() {
//
//	Complex a(10 , 10);
//	cout << a;
//
//	++a;  // 前置递增
//	cout << "前置递增后： " << ++a;
//
//	a++; // 后置递增
//	cout << "后置递增后： " << a++;
//	cout << "后置递增后： " << a; // 再次输出，查看递增后的值
//
//	return 0;
//}


/*
* 四、赋值运算符重载
*/
//class Hero {
//public:
//	Hero():m_Data(NULL){ }
//
//	Hero(int data) {
//		++count;
//		m_Data = new int;
//		*m_Data = data;
//		cout << "构造函数调用，当前对象数量：" << count << " " << this << endl;
//	}
//
//	~Hero() {
//		--count;
//		if (m_Data != NULL) {
//			delete m_Data;
//			m_Data = NULL;
//		}
//		cout << "析构函数调用，当前对象数量：" << count << " " << this << endl;
//	}
//
//	// 赋值运算符重载
//	Hero& operator=(Hero &h) {
//		if (this != &h) { // 防止自我赋值
//			*m_Data = *h.m_Data; // 直接赋值
//		}
//		return *this; // 返回当前对象的引用
//	}
//
//
//	int *m_Data;
//	static int count; // 静态成员变量 所有对象共享
//};
//
//int Hero::count = 0;
//
//int main() {
//
//	Hero h1(1);
//	Hero h2(2);
//
//	Hero h3(3);
//
//	cout << h1.m_Data << ":" << *h1.m_Data << endl;
//	cout << h2.m_Data << ":" << *h2.m_Data << endl;
//	h1 = h2;  // 内存泄露
//	cout << h1.m_Data << ":" << *h1.m_Data << endl;
//	cout << h2.m_Data << ":" << *h2.m_Data << endl;
//
//	h1 = h2 = h3;  // 链式赋值
//	cout << h1.m_Data << ":" << *h1.m_Data << endl;
//	cout << h2.m_Data << ":" << *h2.m_Data << endl;
//	cout << h3.m_Data << ":" << *h3.m_Data << endl;
//
//}

/*
* 五、关系运算符重载
*/
//class Point {
//public:
//	Point():m_x(0),m_y(0){ }
//	
//	Point(int x , int y) {
//		m_x = x;
//		m_y = y;
//	}
//
//	~Point(){ }
//
//	bool operator==(const Point &other) const{
//		return (m_x == other.m_x && m_y == other.m_y);
//	}
//
//
//private:
//	int m_x;
//	int m_y;
//
//};
//
//
//int main() {
//
//	Point p1(4 , 5);
//	Point p2(6 , 7);
//
//	if (p1 == p2) {
//		cout << "相等" << endl;
//	}
//	else {
//		cout << "不相等" << endl;
//	}
//
//	return 0;
//}



