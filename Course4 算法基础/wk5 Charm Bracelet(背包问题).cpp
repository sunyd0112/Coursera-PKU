#include<iostream>
#include<algorithm>
using namespace std;

int w[3405], d[3405], c[12888] = { 0 };

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) { cin >> w[i] >> d[i]; }
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >= 0; --j) {
			if (j - w[i - 1] < 0) { continue; }
			c[j] = max(c[j], (c[j - w[i - 1]] + d[i - 1]));
		}
	}
	cout << c[m];
	return 0;
}
