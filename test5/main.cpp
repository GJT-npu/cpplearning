#include <iostream>
#include <string>
using namespace std;



/*
* 一、构造函数和析构函数的调用时机
* 1、析构函数调用时机：函数结束时，局部变量的生命周期结束，析构函数会被调用。
* 2、拷贝构造函数调用时机：
		1）当一个对象被另一个同类型的对象初始化时，
		2）作为函数参数传递时，
		3）作为函数返回值时。
*/
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
//// 测试析构函数和拷贝构造函数的调用时机
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
* 二、初始化列表的语法
* 
* 构造函数（形参1， 形参2）：成员变量1（形参1），成员变量2（形参2）{}
*  
*/
//class Herro {
//public:
//	Herro(string name, int tp, int speed) : m_name(name), m_tp(tp), m_speed(speed) {
//		cout << "Herro构造完成！" << endl;
//	}
//
//	~Herro() {
//		cout << "Herro析构完成！" << endl;
//	}
//
//	void ShowInfo() const {
//		cout << "Name: " << m_name << endl;
//		cout << "TP: " << m_tp << endl;
//		cout << "Speed: " << m_speed << endl;
//	}
//
//private:
//	string m_name;
//	int m_tp;
//	int m_speed;
//};
//int main() {
//
//	Herro h("jett" , 150 , 300); // 使用初始化列表进行初始化
//	h.ShowInfo();
//
//	return 0;
//}


/*
* 三、静态成员变量的特点：
* 1、所有的对象共享一份数据
* 2、编译阶段分配内存
* 3、需要在类中进行声明那个，在类外进行初始化
*/
//class Herro {
//public:
//
//	Herro() {
//		m_name = "jett";
//		m_tp = 150;
//	}
//	~Herro() {
//
//	}
//
//	// 静态成员变量的声明
//	static int m_HerroCount;
//
//private:
//	string m_name;
//	int m_tp;
//};
//
//// 初始化 静态成员变量 需要在类外进行 加上作用域限定符 Herro::
//int Herro::m_HerroCount = 10;
//
//
//int main() {
//
//	Herro h; //实例化对象
//	cout << h.m_HerroCount << endl;
//	h.m_HerroCount = 20; // 修改静态成员变量的值
//	cout << Herro::m_HerroCount << endl; // 通过类名访问静态成员变量
//
//
//	return 0;
//}

/*
* 四、静态成员函数的特点：
* 1、所有对象共享函数
* 2、只能访问静态成员变量，不能访问非静态成员变量
* 3、可以使用类名直接调用
* 4、不能使用this指针
*/
//class Herro {
//public:
//	Herro() {
//		m_name = "jett";
//		m_tp = 150;
//	}
//	~Herro() {
//
//	}
//
//	// 声明静态成员变量  可以添加const修饰符 无法被修改
//	static int m_HerroCount;
//
//	// 定义静态成员函数
//	static void ShowCount() {
//		m_HerroCount += 100;
//		cout << "当前Herro对象数量：" << m_HerroCount << endl;
//	}
//
//
//private:
//	string m_name;
//	int m_tp;
//};
//
//// 初始化静态成员变量
//int Herro::m_HerroCount = 100;
//
//int main() {
//
//	Herro h1;
//
//	h1.m_HerroCount = 200; // 非const对象可以修改静态成员变量
//	cout << "类名直接调用：" << Herro::m_HerroCount << endl;
//	cout << "对象直接调用：" << h1.m_HerroCount << endl;
//
//	cout << "调用静态成员函数：" << endl;
//	h1.ShowCount();
//	Herro::ShowCount();
//
//	return 0;
//}

/*
* 五、this指针的特点：
* 1、解决成员变量和形参同名的问题
* 2、*this指针是一个隐含的指针，指向当前对象
* 3、this指针只能在类的非静态成员函数中使用
* 
* this      *this
*  &h     *(&h) == h
*/
//class Herro {
//public:
//
//	Herro(int m_tp) {
//		this->m_tp = m_tp; // 1、使用this指针解决成员变量和形参同名的问题
//		cout << this << endl; // 输出当前对象的地址
//		cout << "(*this).m_tp: " << (*this).m_tp << endl; // 2、*this指针是一个隐含的指针，指向当前对象
//	}
//
//	int m_tp;
//};
//int main() {
//
//	Herro h(100);
//	cout << "m_tp: " << h.m_tp << endl;
//	cout << "当前对象的地址：" << &h << endl; // 输出当前对象的地址
//
//	Herro h2(200);
//	cout << "m_tp: " << h2.m_tp << endl;
//	cout << "当前对象的地址：" << &h2 << endl; // 输出当前对象的地址
//
//
//	return 0;
//}

/*
* 六、const修饰成员函数的特点：
* 1、const修饰成员函数，表示该函数不能修改成员变量的值
* 2、const成员函数可以被const对象调用
* 3、const成员函数不能修改成员变量的值，也不可以调用其他非const成员函数
*/
//class Herro {
//public:
//	Herro(int tp) : m_tp(tp) {
//		cout << "Herro构造完成" << endl;
//	}
//
//	~Herro() { }
//
//	int GetTp() const{
//		//m_tp = m_tp + 1; //1、const修饰成员函数，表示该函数不能修改成员变量的值
//		return m_tp;
//	}
//
//	void SetTp(int tp) {
//		m_tp = tp;
//	}
//
//	int SetGetTp() const {
//		ShowTp();
//		return m_tp;
//	}
//
//	void ShowTp() const{
//		cout << "SetGetTp调用" << endl;
//	}
//
//
//private:
//	int m_tp;
//};
//int main() {
//
//	//1、const修饰成员函数，GetTp中不能改变成员变量m_tp的值
//	Herro h1(100);
//	cout << "初始化 h1 m_tp: " << h1.GetTp() << endl; // 调用const成员函数
//
//	// 2、const成员函数可以被const对象调用
//	const Herro h2(150);
//	//cout << h2.SetTp(100) << endl; // 调用非const成员函数，编译错误
//	cout << "初始化 h2 m_tp: " << h2.GetTp() << endl; // const对象调用const成员函数
//
//	// 3、const成员函数不能修改成员变量的值，也不可以调用其他非const成员函数
//	Herro h3(200);
//	cout << h3.SetGetTp() << endl;
//
//	return 0;
//}

/*
* 七、mutable修饰成员变量的特点:
* 1、mutable修饰的成员变量可以在const成员函数中修改
* 2、mutable修饰的成员变量可以被const对象访问
*/
class Herro {
public:
	Herro():m_tp(0),m_TpCouner(0) { }

	~Herro() { }

	int getTp() const{
		m_TpCouner++;
		return m_tp;
	}

	void printCounter() const {
		cout << "" << "getTp被调用了" << m_TpCouner << "次" << endl;
	}

private:
	int m_tp;
	mutable int m_TpCouner; // 1、mutable修饰的成员变量可以在const成员函数中修改

};
int main() {

	Herro h1;
	h1.getTp() , h1.getTp() , h1.getTp() , h1.getTp() , h1.getTp() , h1.getTp() , h1.getTp();

	h1.printCounter();

	//2、mutable修饰的成员变量可以被const对象访问 m_TpCouner一直在增加
	const Herro h2;
	h2.getTp() , h2.getTp() , h2.getTp() , h2.getTp() , h2.getTp();
	h2.printCounter();

	return 0;
}


