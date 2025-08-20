#include <iostream>
#include <string>
using namespace std;

/*
* 一、加法运算符的重载
*     1、成员函数重载
*     2、友元全局函数重载
*/

class Complex {

	friend Complex operator-(Complex &a , Complex &b);

public:
	Complex() :real(0) , image(0) {

	}

	Complex(int real , int image) {
		this->real = real;
		this->image = image;
	}

	~Complex() { }

	// 复数加法函数
	Complex add(Complex &other) {
		Complex ret;
		ret.real = this->real + other.real;
		ret.image = this->image + other.image;
		return ret;
	}

	// 成员函数重载
	Complex operator+(Complex &other) {
		Complex ret;
		ret.real = this->real + other.real;
		ret.image = this->image + other.image;
		return ret;
	}

	void ShowComplex() {
		cout << "复数是： " << real << " + " << image << "i" << endl;
	}

private:
	int real;
	int image;
};

// 友元全局函数重载
Complex operator-(Complex &a , Complex &b) {
	Complex ret;
	ret.real = a.real - b.real;
	ret.image = a.image - b.image;
	return ret;
}

int main() {

	Complex a(5 , 10);
	a.ShowComplex();
	Complex b(6 , 8);
	b.ShowComplex();

	Complex c = a.add(b);
	cout << "c: ";
	c.ShowComplex();

	Complex d = a + b;
	cout << "d: ";
	d.ShowComplex();

	Complex e = a - b;
	cout << "e: ";
	e.ShowComplex();

	return 0;
}




