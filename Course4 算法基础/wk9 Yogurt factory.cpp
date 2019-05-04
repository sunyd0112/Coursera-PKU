#include <iostream>
using namespace std;

int N, S; int a[10010][3] = { 0 };

long long solve(){
	long long cost = a[1][1] * a[1][2]; int temp = 1;
	for (int i = 2; i <= N; ++i) {
		if ((a[i][1] - a[temp][1]) > S * (i - temp)) { cost += a[temp][1] * a[i][2] + a[i][2] * S * (i - temp); }
		else { temp = i; cost += a[i][1] * a[i][2]; }
	}
	return cost;
}

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= 2; ++j) {
			cin >> a[i][j];
		}
	}

	if (N == 1) { cout << a[1][1] * a[1][2]; return 0; }
	else { cout << solve(); }

	return 0;
}
