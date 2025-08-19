#include <iostream>
using namespace std;

class Herro {
public:
	Herro() {
		m_tp = 100;
		cout << "Ĭ�Ϲ��캯����Herro������ɣ�" << endl;
	}
	Herro(int tp) {
		m_tp = tp;
		cout << "�вι��캯����Herro������ɣ�" << endl;
	}
	Herro(const Herro &other) {
		m_tp = other.m_tp;
		cout << "�������캯����Herro������ɣ�" << endl;
	}
	~Herro() {
		cout << "����������Herro������ɣ�" << endl;
	}

private:
	int m_tp;

};

/*
* 1��������������ʱ������������ʱ���ֲ��������������ڽ��������������ᱻ���á�
* 2���������캯������ʱ����
		1����һ��������һ��ͬ���͵Ķ����ʼ��ʱ��
		2����Ϊ������������ʱ��
		3����Ϊ��������ֵʱ��
*/

// �������������Ϳ������캯���ĵ���ʱ��


// 1����һ��������һ��ͬ���͵Ķ����ʼ��ʱ��
void func1() {
	cout << "------------func1 start------------" << endl;
	Herro h1;
	Herro h2(h1);
}

// 2����Ϊ������������ʱ��
// ע�⣺�������������ֵ���ݣ������ÿ������캯��
void test2(Herro h) {

}

void func2() {
	cout << "------------func2 start------------" << endl;
	Herro h2(300);
	test2(h2);

}

// �������������ָ�봫�ݣ��򲻻���ÿ������캯��
void test3(Herro* h) {

}

void func3() {
	cout << "------------func3 start------------" << endl;
	Herro h3(300);
	test3(&h3);

}

// ����������������ô��ݣ��򲻻���ÿ������캯��
void test4(Herro &h) {

}

void func4() {
	cout << "------------func4 start------------" << endl;
	Herro h4(300);
	test4(h4);

}

// 3����Ϊ��������ֵʱ��

Herro func5() {
	cout << "------------func5 start------------" << endl;
	Herro h5(200);
	return h5;
}

int main() {

	func1();
	func2();
	func3();
	func4();
	Herro H5 = func5(); // rvo�Ż������������Ż����������캯���ĵ��� �ص�rvo�Ż�ָ�/Zc:nrvo- ����ÿ������캯��

	return 0;
}