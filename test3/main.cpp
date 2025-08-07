#include <iostream>
#include <algorithm>
using namespace std;

struct Intervel {
	int s;
	int e;
}I[100];

bool cmp(const Intervel &a , const Intervel &b) {
	return a.e < b.e;
}

int main() {

	int n;

	while (cin >> n && n) {
		for (int i = 0; i < n; ++i) {
			cin >> I[i].s >> I[i].e;
		}

		sort(I , I + n , cmp);
		int end = -1;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (I[i].s >= end) {
				end = I[i].e;
				ans++;
			}
		}
		cout << ans << endl;

	}

	return 0;
}