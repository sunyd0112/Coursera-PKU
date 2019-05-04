#include <iostream>
using namespace std;

int measure(int x, int y)
{
	int z = y;
	while (x % y != 0)
	{
		z = x % y;
		x = y;
		y = z;
	}
	return z;
}

int main() {
	int M, N;
	while (cin >> M >> N) { cout << measure(M, N) << endl; }

	return 0;
}
