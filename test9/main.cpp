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
//class Animal {
//public:
//	virtual void sound() {
//		cout << "Animal makes a sound" << endl;
//	}
//	virtual void eat() {
//		cout << "Animal eats" << endl;
//	}
//};
//
//class Cat :public Animal {
//public:
//	void sound() override {
//		cout << "喵" << endl;
//	}
//};
//
//int main() {
//
//	Cat c;
//	c.sound();
//	c.Animal::sound();
//
//	cout << "Size of Animal:" << sizeof(Animal) << endl;
//
//	return 0;
//}

/*
* 三、纯虚函数和抽象类
*	1、纯虚函数是指在基类中声明但不实现的虚函数。
*   2、纯虚函数的声明形式为：virtual void functionName() = 0;
*   3、包含纯虚函数的类称为抽象类，不能实例化。
*	4、派生类必须实现所有的纯虚函数才能实例化。否则也是抽象类 不能实例化
*/
//class Animal {
//public:
//	virtual void sound() = 0; // 纯虚函数
//
//};
//class Cat :public Animal {
//public:
//
//	Cat() : m_age(0) { }
//
//	void sound() override {
//		cout << "喵" << endl;
//	}
//
//private:
//	int m_age;
//};
//
//int main() {
//	
//	Cat c;
//	c.sound();
//
//	return 0;
//}

/*
* 四、虚析构与纯虚析构
*	1、防止内存泄漏：当基类指针指向派生类对象时，如果基类的析构函数不是虚函数，可能导致派生类的析构函数无法被调用，从而造成内存泄漏。
*	2、纯虚析构函数：在抽象类中，可以将析构函数声明为纯虚函数，以确保派生类必须实现析构函数。
* 	3、虚析构函数：在基类中声明析构函数为虚函数，以确保在删除基类指针时，能够正确调用派生类的析构函数。
*   4、当父类指针指向派生类对象时，它实际上指向的是该对象中的父类子对象部分
*/
class Animal {
public:
	Animal(): size(NULL) { 
		size = new int(100); // 假设size是一个指向int的指针
		cout << "Animal构造函数" << endl; 
	} 

	virtual ~Animal() { 
		if (size) {
			delete size;
			size = NULL;
		}
		cout << "Animal虚析构函数" << endl; 
	} 

	virtual void sound() = 0; // 纯虚函数

	int *size;
};
class Cat :public Animal {
public:

	Cat() : m_age(NULL) {
		m_age = new int(10);
		cout << "Cat构造函数" << endl;
	}
	~Cat() {
		if (m_age) {
			delete m_age;
			m_age = NULL;
		}
		cout << "Cat虚析构函数" << endl;
	}

	void sound() {
		cout << "喵" << endl;
	}

	int *m_age;
};

int main() {

	//Cat c;
	//cout << *c.m_age << endl;

	// 指针a 访问不到子类的成员变量 
	// 当父类指针指向派生类对象时，它实际上指向的是该对象中的父类子对象部分
	Animal *a = new Cat();
	cout << *a->size << endl;
	delete a;

	Cat *c = new Cat();
	cout << *c->m_age << endl;
	delete c;

	return 0;
}