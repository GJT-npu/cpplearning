#include <iostream>
#include <string>
using namespace std;

//class Herro {
//public:
//	Herro() {
//		m_tp = 100;
//		cout << "Ĭ�Ϲ��캯����Herro������ɣ�" << endl;
//	}
//	Herro(int tp) {
//		m_tp = tp;
//		cout << "�вι��캯����Herro������ɣ�" << endl;
//	}
//	Herro(const Herro &other) {
//		m_tp = other.m_tp;
//		cout << "�������캯����Herro������ɣ�" << endl;
//	}
//	~Herro() {
//		cout << "����������Herro������ɣ�" << endl;
//	}
//
//private:
//	int m_tp;
//
//};
//
///*
//* 1��������������ʱ������������ʱ���ֲ��������������ڽ��������������ᱻ���á�
//* 2���������캯������ʱ����
//		1����һ��������һ��ͬ���͵Ķ����ʼ��ʱ��
//		2����Ϊ������������ʱ��
//		3����Ϊ��������ֵʱ��
//*/
//
//// �������������Ϳ������캯���ĵ���ʱ��
//
//
//// 1����һ��������һ��ͬ���͵Ķ����ʼ��ʱ��
//void func1() {
//	cout << "------------func1 start------------" << endl;
//	Herro h1;
//	Herro h2(h1);
//}
//
//// 2����Ϊ������������ʱ��
//// ע�⣺�������������ֵ���ݣ������ÿ������캯��
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
//// �������������ָ�봫�ݣ��򲻻���ÿ������캯��
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
//// ����������������ô��ݣ��򲻻���ÿ������캯��
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
//// 3����Ϊ��������ֵʱ��
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
//	Herro H5 = func5(); // rvo�Ż������������Ż����������캯���ĵ��� �ص�rvo�Ż�ָ�/Zc:nrvo- ����ÿ������캯��
//
//	return 0;
//}


/*
* ��ʼ���б���﷨
* 
* ���캯�����β�1�� �β�2������Ա����1���β�1������Ա����2���β�2��{}
*  
*/
//


/*
* ��̬��Ա�������ص㣺
* 1�����еĶ�����һ������
* 2������׶η����ڴ�
* 3����Ҫ�����н��������Ǹ�����������г�ʼ��
*/
class Herro {
public:

	Herro() {
		m_name = "jett";
		m_tp = 150;
	}
	~Herro() {

	}

	// ��̬��Ա����������
	static int m_HerroCount;

private:
	string m_name;
	int m_tp;
};

// ��ʼ�� ��̬��Ա���� ��Ҫ��������� �����������޶��� Herro::
int Herro::m_HerroCount = 10;


int main() {

	Herro h; //ʵ��������
	cout << h.m_HerroCount << endl;
	h.m_HerroCount = 20; // �޸ľ�̬��Ա������ֵ
	cout << Herro::m_HerroCount << endl; // ͨ���������ʾ�̬��Ա����


	return 0;
}







