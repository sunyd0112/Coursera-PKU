#include <iostream>
using namespace std;

#define N 51
long long a[N + 1][N + 1];

int main() {
	//  freopen("in.txt", "r", stdin);
	for (int i = 0; i <= N; i++) {
		a[0][i] = 1;
	}
	a[1][1] = 1;
	for (int i = 2; i < N; i++) {
		for (int j = i; j >= 1; j--) {
			a[i][j] = a[i - j][j] + a[i][j + 1];
		}
	}

	int n;
	while (cin >> n) {
		cout << a[n][1] << endl;
	}
	return 0;
}
