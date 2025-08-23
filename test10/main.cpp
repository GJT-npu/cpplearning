#include <iostream>
#include <string>
using namespace std;

/*
* 一、函数模板定义
* 
* 1、函数模板支持多个类型参数
* 2、函数模板的类型参数可以在函数体内使用
* 3、函数模板可以通过自动类型推导来调用
* 4、函数模板可以显式指定类型参数
* 5、一旦有类型不能推导出来，编译器就会报错
* 6、返回值类型无法作为推导依据
*/

//template <typename T>
//T add(T a, T b) {
//	return a + b;
//}
//int main() {
//
//	int a = 1;
//	int b = 6;
//
//	// 自动类型推导
//	int c = add(a , b); // 调用函数模板
//	cout << "int add: " << c << endl;
//
//	// 显式指定类型
//	c = add<int>(a , b);
//	cout << c << endl;
//
//	return 0;
//}

/*
* 二、类模板
*/

/*
* 1、实现动态数组类
* 2、并改用类模板来实现
* 3、成员函数类外实现
*/
template<typename T>
class DynamicArray {
public:
	DynamicArray(int n);

	~DynamicArray();

	T &operator[](int index);

private:
	T *elements; // 存储元素的指针
	int size;      // 数组大小
};

// 成员函数类外实现
template<typename T>
DynamicArray<T>::DynamicArray(int n) :size(n) {
	elements = new T[size]; // 动态分配内存
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[ ] elements; // 释放内存
}

template<typename T>
T &DynamicArray<T>::operator[](int index) {
	if (index < 0 || index >= size) {
		throw out_of_range("Index out of range");
	}
	return elements[index]; // 返回指定索引的元素
}

int main() {

	DynamicArray<int> arr(5); // 创建一个大小为5的动态数组
	for (int i = 0; i < 5; ++i) {
		arr[i] = i * 10; // 设置元素值
	}
	for (int i = 0; i < 5; ++i) {
		cout << "Element at index " << i << ": " << arr[i] << endl; // 输出元素值
	}
	return 0;
}

