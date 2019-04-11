#include <iostream>
using namespace std;

const int r = 3; int c, total;

struct point {
	int x, y;
};

point nextPoint(char **mark, int x, int y) {
	while (mark[y][x] == '_') {
		x += 1;
		if (x > c - 1) {
			x = 0; y = y + 1;
			if (y == r) { point p = { -1,-1 }; return p; }
		}
	}

	point tmp = { x,y }; return tmp;
}

void Search(char **mark, int x, int y, int d) {
	if (x == -1) { ++total; return; }

	if (d == -1) { Search(mark, x, y, 0); Search(mark, x, y, 1); }

	else if (d == 0) {
		if (y < r && x < c && x + 1 < c && mark[y][x] == ' ' && mark[y][x + 1] == ' ') {
			mark[y][x] = '_';
			mark[y][x + 1] = '_';
			point p = nextPoint(mark, x, y);
			Search(mark, p.x, p.y, -1);
			mark[y][x] = ' ';
			mark[y][x + 1] = ' ';
		}
		else { return; }
	}

	else if (d == 1) {
		if (x < c && y < r && y + 1 < r && mark[y + 1][x] == ' ' &&  mark[y][x] == ' ') {
			mark[y + 1][x] = '_';
			mark[y][x] = '_';
			point p = nextPoint(mark, x, y);
			Search(mark, p.x, p.y, -1);
			mark[y + 1][x] = ' ';
			mark[y][x] = ' ';
		}
		else { return; }
	}
}

int main() {
	while (cin >> c && c != -1) {
		if (c % 2 || c == 0) { cout << 0 << endl; }

		char **mark = new char*[r];
		for (int i = 0; i < r; i++) {
			mark[i] = new char[c + 1];
		}
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				mark[i][j] = ' ';
			}
		}

		total = 0;
		Search(mark, 0, 0, -1);
		cout << total << endl;
	}
}
