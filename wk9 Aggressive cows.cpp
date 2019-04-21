#include <iostream>
#include <algorithm>
using namespace std;

int N, C; long long a[100010] = { 0 };

bool check(long long n){
	long long temp = a[1]; int count = 1;
	for (int i=2; i <= N; ++i) {
		if (a[i] - temp >= n) { ++count; temp = a[i]; }
		if (count == C) { break; }
	}
	if (count != C) { return false; }
	else return true;
}

int main() {
	 cin >> N >> C;
	 if (N < C) { cout << 0; return 0; }
	for (int i = 1; i <= N; ++i) { cin>>a[i]; }
	sort(a, a + N);

	if (N == C) {
		long long minimum = a[2] - a[1];
		for (int i = 2; i < N; ++i) {
			if (a[i + 1] - a[i] < minimum) { minimum = a[i + 1] - a[i]; }
		}
		cout << minimum; return 0;
	}
	if (C == 2) { cout << a[N] - a[1]; return 0; }

	long long l = 1, r = a[N] - a[1], result = 0;
	while (l < r) {
		long long mid = (l + r) / 2;
		if (check(mid)) { result = mid; l = mid + 1; }
		else  r = mid - 1;
	}
	if (check(l)) { cout << l; }
	else cout << result;
	return 0;
}