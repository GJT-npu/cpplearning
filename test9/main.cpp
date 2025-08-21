#include <iostream>
#include <string>
using namespace std;

/*
* 一、多态
* 
* 多态是指同一个函数或方法可以作用于不同的对象或数据类型上，表现出不同的行为。
* 在父类中使用virtual声明一个虚函数，然后在子类中重写这个虚函数。
* 
* 函数传参是父类，传入不同的子类对象，调用时会根据对象的实际类型来决定调用哪个版本的函数。
*/
//class Animal {
//public:
//	virtual void sound() {
//		cout << "Animal makes a sound" << endl;
//	}
//};
//
//class Cat :public Animal {
//public:
//	void sound() {
//		cout << "喵" << endl;
//	}
//};
//class Dog :public Animal {
//public:
//	void sound() {
//		cout << "汪" << endl;
//	}
//};
//
//void sound(Animal &a) {
//	a.sound();
//}
//
//void test() {
//	Cat c;
//	Dog d;
//	
//	sound(c);
//	sound(d);
//}
//
//int main() {
//	Cat cat;
//	cat.Animal::sound(); // 调用父类的静态方法
//	test();
//
//	return 0;
//}


/*
* 二、虚函数
*	1、虚函数是指在基类中使用virtual关键字声明的成员函数。
*	2、虚函数允许在派生类中重写基类的函数。
*	3、虚函数指针的是通过基类指针或引用调用的函数。
*/
class Animal {
public:
	virtual void sound() {
		cout << "Animal makes a sound" << endl;
	}
	virtual void eat() {
		cout << "Animal eats" << endl;
	}
};

class Cat :public Animal {
public:
	void sound() override {
		cout << "喵" << endl;
	}
};

int main() {

	Cat c;
	c.sound();
	c.Animal::sound();

	cout << "Size of Animal:" << sizeof(Animal) << endl;

	return 0;
}