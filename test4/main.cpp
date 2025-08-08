#include <iostream>
using namespace std;


int main() {
	
	double *pt = new double[3];
	pt[0] = 0.1;
	pt[1] = 0.5;
	pt[2] = 0.8;

	cout << "pt[1] is :" << pt[1] << " location : " << pt + 1 << endl;
	pt = pt + 1;
	cout << "pt[0] is :" << pt[0] << " location : " << pt << endl;
	cout << "pt[1] is :" << pt[1] << " location : " << pt + 1 << endl;
	cout << "pt[2] is :" << pt[2] << " location : " << pt + 2 << endl;

	pt = pt - 1;

	cout << "pt[0] is :" << pt[0] << " location : " << pt << endl;
	delete[ ] pt;


}