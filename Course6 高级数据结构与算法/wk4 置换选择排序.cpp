#include <iostream>
#include <queue>
using namespace std;

int a[1000010], asize = 0, Size;
queue<int> q;

void siftDown() {
	int temp = a[1], i = 1, j = 2;
	while (j <= asize) {
		if (j + 1 <= asize && a[j] > a[j + 1]) ++j;
		if (temp > a[j]) {
			a[i] = a[j];
			i = j; j *= 2;
		}
		else break;
	}
	a[i] = temp;
}

int main() {
	int m, n, num; cin >> m >> n;
	while (m--) { cin >> num; q.push(num); }
	while (n--) {
		cin >> num;
		a[++asize] = num;
	}
	Size = asize;

	while (!q.empty() && asize!=0) {
		num = q.front(); q.pop();
		cout << a[1] << " ";

		if (num > a[1]) { a[1] = num; }
		else { a[1] = a[asize--]; }
		siftDown();
	}

	return 0;
}
