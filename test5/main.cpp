#include <iostream>
#include <string>
using namespace std;

//class Herro {
//public:
//	Herro() {
//		m_tp = 100;
//		cout << "默认构造函数：Herro构造完成！" << endl;
//	}
//	Herro(int tp) {
//		m_tp = tp;
//		cout << "有参构造函数：Herro构造完成！" << endl;
//	}
//	Herro(const Herro &other) {
//		m_tp = other.m_tp;
//		cout << "拷贝构造函数：Herro构造完成！" << endl;
//	}
//	~Herro() {
//		cout << "析构函数：Herro析构完成！" << endl;
//	}
//
//private:
//	int m_tp;
//
//};
//
///*
//* 1、析构函数调用时机：函数结束时，局部变量的生命周期结束，析构函数会被调用。
//* 2、拷贝构造函数调用时机：
//		1）当一个对象被另一个同类型的对象初始化时，
//		2）作为函数参数传递时，
//		3）作为函数返回值时。
//*/
//
//// 测试析构函数和拷贝构造函数的调用时机
//
//
//// 1）当一个对象被另一个同类型的对象初始化时，
//void func1() {
//	cout << "------------func1 start------------" << endl;
//	Herro h1;
//	Herro h2(h1);
//}
//
//// 2）作为函数参数传递时，
//// 注意：如果函数参数是值传递，则会调用拷贝构造函数
//void test2(Herro h) {
//
//}
//
//void func2() {
//	cout << "------------func2 start------------" << endl;
//	Herro h2(300);
//	test2(h2);
//
//}
//
//// 如果函数参数是指针传递，则不会调用拷贝构造函数
//void test3(Herro* h) {
//
//}
//
//void func3() {
//	cout << "------------func3 start------------" << endl;
//	Herro h3(300);
//	test3(&h3);
//
//}
//
//// 如果函数参数是引用传递，则不会调用拷贝构造函数
//void test4(Herro &h) {
//
//}
//
//void func4() {
//	cout << "------------func4 start------------" << endl;
//	Herro h4(300);
//	test4(h4);
//
//}
//
//// 3）作为函数返回值时。
//
//Herro func5() {
//	cout << "------------func5 start------------" << endl;
//	Herro h5(200);
//	return h5;
//}
//
//int main() {
//
//	func1();
//	func2();
//	func3();
//	func4();
//	Herro H5 = func5(); // rvo优化，编译器会优化掉拷贝构造函数的调用 关掉rvo优化指令：/Zc:nrvo- 会调用拷贝构造函数
//
//	return 0;
//}


/*
* 初始化列表的语法
* 
* 构造函数（形参1， 形参2）：成员变量1（形参1），成员变量2（形参2）{}
*  
*/
//


/*
* 静态成员变量的特点：
* 1、所有的对象共享一份数据
* 2、编译阶段分配内存
* 3、需要在类中进行声明那个，在类外进行初始化
*/
class Herro {
public:

	Herro() {
		m_name = "jett";
		m_tp = 150;
	}
	~Herro() {

	}

	// 静态成员变量的声明
	static int m_HerroCount;

private:
	string m_name;
	int m_tp;
};

// 初始化 静态成员变量 需要在类外进行 加上作用域限定符 Herro::
int Herro::m_HerroCount = 10;


int main() {

	Herro h; //实例化对象
	cout << h.m_HerroCount << endl;
	h.m_HerroCount = 20; // 修改静态成员变量的值
	cout << Herro::m_HerroCount << endl; // 通过类名访问静态成员变量


	return 0;
}







