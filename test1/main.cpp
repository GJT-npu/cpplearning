#include <iostream>
#include <string>
using namespace std;

string getHex(int x) {
	char buff[10];
	sprintf_s(buff , sizeof(buff) , "%X" , (x & 0xFFFF));
	//sprintf(buff , "%X" , (x & 0xFFFF));

	return ( string )buff;
}

int main() {

	int a[3][4] = {
		{1, 2, 3, 4 },
		{5, 6, 7, 8 },
		{9, 10, 11, 12 }
	};

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (j) {
				cout << ", ";
			}
			int *p = &a[i][j];
			cout << getHex((int) p);
		}
		cout << endl;
	}

	// 指针数组 每个元素指向行首地址
	int *q[3] = { a[0], a[1], a[2] };
	// 数组指针
	int(*p)[4];
	p = &a[0];

	cout << "-------------------------" << endl;
	cout << "1、指针 + i" << endl;

	cout << "数组指针 p + i" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )(p + i));
		cout << "第" << i << "个[4]数组的地址： " << s << endl;
	}
	cout << "指针数组 q + i" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )(q + i));
		cout << "第" << i << "个q元素的地址: " << s << endl;
	}

	cout << "-------------------------" << endl;
	cout << "2、*（指针 + i）" << endl;
	cout << "数组指针 *（p + i）" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )*(p + i));
		cout << "a数组第" << i << "行第0个元素的地址： " << s << endl;
	}
	cout << "指针数组 *（q + i）" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )*(q + i));
		cout << "a数组第" << i << "行第0个元素的地址: " << s << endl;
	}

	cout << "-------------------------" << endl;
	cout << "3、*（指针 + i）+ j" << endl;
	cout << "数组指针 *（p + i）+ j" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )(*(p + i) + 1));
		cout << "a数组第" << i << "行第1个元素的地址： " << s << endl;
	}
	cout << "指针数组 *（q + i）+ j" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )(*(q + i) + 2));
		cout << "a数组第" << i << "行第2个元素的地址: " << s << endl;
	}

	cout << "-------------------------" << endl;
	cout << "4、*(*（指针 + i）+ j)" << endl;
	cout << "数组指针 *（p + i）+ j" << endl;
	for (int i = 0; i < 3; ++i) {
		int number = *(*(p + i) + 1);
		cout << "a数组第" << i << "行第1个元素是： " << number << endl;
	}
	cout << "指针数组 *(*（q + i）+ j)" << endl;
	for (int i = 0; i < 3; ++i) {
		q[i][2] = 100;
		p[i][3] = 293;
		cout << "a数组第" << i << "行第2个元素是: " << *(*(q + i) + 2) << endl;
	}

	cout << "-------------------------" << endl << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (j) {
				cout << ",";
			}
			cout << a[i][j];
		}
		cout << endl;
	}





	return 0;
}