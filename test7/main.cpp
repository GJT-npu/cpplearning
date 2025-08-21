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


class Complex {
	friend ostream &operator<<(ostream &c , Complex a);
public:
	// 默认构造函数
	Complex() :real(0) , image(0) { }

	// 带参数的构造函数
	Complex(int real , int image) {
		this->real = real;
		this->image = image;
	}

	// 析构函数
	~Complex() { }

	// 前置递增
	Complex& operator++() {
		this->real += 1;
		return *this;
	}

	// 后置递增
	Complex operator++(int) {
		Complex temp = *this; // 保存当前对象的状态
		this->real += 1; // 递增操作
		return temp; // 返回递增前的状态
	}

private:
	int real;
	int image;
};

ostream &operator<<(ostream &c , Complex a) {
	c << a.real << "+" << a.image << "i" << endl;
	return c;
}

int main() {

	Complex a(10 , 10);
	cout << a;

	++a;  // 前置递增
	cout << "前置递增后： " << ++a;

	a++; // 后置递增
	cout << "后置递增后： " << a++;
	cout << "后置递增后： " << a; // 再次输出，查看递增后的值

	return 0;
}
