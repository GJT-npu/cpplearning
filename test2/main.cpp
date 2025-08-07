
#include <iostream>
using namespace std;

struct Point {
	double x , y;
};

struct Rectangle {
	Point ld; // left down
	Point rt; // right top
};

int main() {

	Rectangle r1 , r2;

	// Input format: ld.x ld.y rt.x rt.y for each rectangle
	while (cin >> r1.ld.x >> r1.ld.y >> r1.rt.x >> r1.rt.y) {

		cin >> r2.ld.x >> r2.ld.y >> r2.rt.x >> r2.rt.y;

		double x1 = max(r1.ld.x , r2.ld.x);
		double x2 = min(r1.rt.x , r2.rt.x);

		double y1 = max(r1.ld.y , r2.ld.y);
		double y2 = min(r1.rt.y , r2.rt.y);
		printf("%.2lf" , (x2 - x1) * (y2 - y1));
		cout << endl;
	}



	return 0;
}