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

	// ָ������ ÿ��Ԫ��ָ�����׵�ַ
	int *q[3] = { a[0], a[1], a[2] };
	// ����ָ��
	int(*p)[4];
	p = &a[0];

	cout << "-------------------------" << endl;
	cout << "1��ָ�� + i" << endl;

	cout << "����ָ�� p + i" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )(p + i));
		cout << "��" << i << "��[4]����ĵ�ַ�� " << s << endl;
	}
	cout << "ָ������ q + i" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )(q + i));
		cout << "��" << i << "��qԪ�صĵ�ַ: " << s << endl;
	}

	cout << "-------------------------" << endl;
	cout << "2��*��ָ�� + i��" << endl;
	cout << "����ָ�� *��p + i��" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )*(p + i));
		cout << "a�����" << i << "�е�0��Ԫ�صĵ�ַ�� " << s << endl;
	}
	cout << "ָ������ *��q + i��" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )*(q + i));
		cout << "a�����" << i << "�е�0��Ԫ�صĵ�ַ: " << s << endl;
	}

	cout << "-------------------------" << endl;
	cout << "3��*��ָ�� + i��+ j" << endl;
	cout << "����ָ�� *��p + i��+ j" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )(*(p + i) + 1));
		cout << "a�����" << i << "�е�1��Ԫ�صĵ�ַ�� " << s << endl;
	}
	cout << "ָ������ *��q + i��+ j" << endl;
	for (int i = 0; i < 3; ++i) {
		string s = getHex(( int )(*(q + i) + 2));
		cout << "a�����" << i << "�е�2��Ԫ�صĵ�ַ: " << s << endl;
	}

	cout << "-------------------------" << endl;
	cout << "4��*(*��ָ�� + i��+ j)" << endl;
	cout << "����ָ�� *��p + i��+ j" << endl;
	for (int i = 0; i < 3; ++i) {
		int number = *(*(p + i) + 1);
		cout << "a�����" << i << "�е�1��Ԫ���ǣ� " << number << endl;
	}
	cout << "ָ������ *(*��q + i��+ j)" << endl;
	for (int i = 0; i < 3; ++i) {
		q[i][2] = 100;
		p[i][3] = 293;
		cout << "a�����" << i << "�е�2��Ԫ����: " << *(*(q + i) + 2) << endl;
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