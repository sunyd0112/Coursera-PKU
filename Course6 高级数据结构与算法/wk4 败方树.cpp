#include <iostream>
using namespace std;

int a[100010] = { 0 }, b[10010] = { 0 }, n, m, lowext, offset;

int winner(int x, int y) {
	if (a[x] > a[y])return y;
	else return x;
}

int loser(int x, int y) {
	if (a[x] > a[y])return x;
	else return y;
}

void play(int p, int l, int r) {

	b[p] = loser(l, r);
	int temp1, temp2;
	temp1 = winner(l, r);
	while (p > 1 && p % 2) { //compete all the way up to the top
		temp2 = winner(temp1, b[p / 2]);
		b[p / 2] = loser(temp1, b[p / 2]);
		temp1 = temp2;
		p /= 2;
	}
	b[p / 2] = temp1;
}

void replay(int i) {
	int p;
	if (i <= lowext)
		p = (i + offset) / 2;
	else p= (i - lowext + n - 1) / 2;

	b[0] = winner(i, b[p]); //put every winner temporarily in b[0] because the last winner is gone anyway
	b[p] = loser(i, b[p]);
	while (p / 2 >= 1) {
		int temp = winner(b[p / 2], b[0]);
		b[p / 2] = loser(b[p / 2], b[0]);
		b[0] = temp;
		p /= 2;
	}
}

void BuildLoserTree() {
	int i, s;
	for (s = 1; s * 2 <= n - 1; s +=s);
	lowext = 2 * (n - s); offset = 2 * s - 1; //lowext to compute number of nodes in the bottom; offset to computer its father node

	for (i = 2; i <= lowext; i += 2)
		play((offset + i) / 2, i - 1, i);

	if (n % 2) { //if n is odd, an external node should be compared with an internal node
		play(n / 2, b[(n - 1) / 2], lowext + 1);
		i = lowext + 3;
	}
	else { i = lowext + 2; }
	for (; i <= n; i += 2) { //what was left of it
		play((i - lowext + n - 1) / 2, i - 1, i);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) { cin >> a[i]; }

	BuildLoserTree();

	for (int i = 0; i < n; ++i) { cout << a[b[i]] << " "; }
	cout << endl;

	while (m--) {
		int m1, m2; cin >> m1 >> m2;
		a[m1 + 1] = m2;
		replay(m1 + 1);
		for (int i = 0; i < n; ++i) {
			cout << a[b[i]] << " ";
		}
		cout << endl;
	}

	return 0;
}
