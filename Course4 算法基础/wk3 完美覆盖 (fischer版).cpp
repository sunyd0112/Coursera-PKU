#include <iostream>
using namespace std;

int vertical(int);
int horizontal(int);

int count(int n) {
	if (n == 0) return 1;
	if (n % 2) return 0;
	return vertical(n) + horizontal(n);
}

// ´¹Ö±·½Ïò
int vertical(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return horizontal(n - 1) + vertical(n - 2);
}

// Ë®Æ½·½Ïò
int horizontal(int n) {
	if (n == 0) return 1;
	if (n == 1) return 0;
	return 2 * vertical(n - 1) + horizontal(n - 2);
}

int main() {
	int n;
	while (cin >> n && n != -1) {
		cout << count(n) << endl;
	}
	return 0;
}
