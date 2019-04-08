#include<iostream>
using namespace std;

char painting1[16][17]; int painting[16][17], drawing[16][17], s;

bool guess() {
	int r, c;
	for (r = 1; r < s; ++r) {
		for (c = 1; c < s + 1; ++c) {
			drawing[r + 1][c] = (painting[r][c] + drawing[r][c] + drawing[r - 1][c] + drawing[r][c - 1] + drawing[r][c + 1]) % 2;
		}
	}
	for (c = 1; c < s + 1; ++c) {
		if (painting[s][c] != (drawing[s][c] + drawing[s][c + 1] + drawing[s][c - 1] + drawing[s - 1][c]) % 2) { return false; }
	}
	return true;
}

int enumerate() {
	int r, c, min = s * s + 1, step = 0;
	for (c = 1; c < s + 1; ++c) { drawing[1][c] = 0; }//第一行先全设为0
	while (!drawing[1][s + 1]==1) {
		if (guess() == false) {
			++drawing[1][1]; c = 1;
			while (drawing[1][c] > 1) { drawing[1][c] = 0; ++c; ++drawing[1][c]; }//二进制
		}
		else {
			for (r = 1; r < s + 1; ++r) {
				for (c = 1; c < s + 1; ++c) {
					if (drawing[r][c] == 1) { ++step; }
				}
			}
			if (min > step) { min = step; }
			step = 0;
			++drawing[1][1]; c = 1;
			while (drawing[1][c] > 1) { drawing[1][c] = 0; ++c; ++drawing[1][c]; }
		}
	}
	return min;
}

int main() {
	int caseN; cin >> caseN;
	for (int i = 0; i < caseN; ++i) {
		int r, c, min; cin >> s;
		for (r = 0; r < s + 1; ++r) { drawing[r][0] = drawing[r][s + 1] = 0; } //这两步给外边一圈清零
		for (c = 1; c < s + 1; ++c) { drawing[0][c] = 0; }
		for (r = 1; r < s + 1; ++r) {
			for (c = 1; c < s + 1; ++c) {
				cin >> painting1[r][c];
			}
		}
		for (r = 1; r < s + 1; ++r) {
			for (c = 1; c < s + 1; ++c) {
				if (painting1[r][c] == 'w') { painting[r][c] = 1; } //wy转成01方便计算
				else if (painting1[r][c] == 'y') { painting[r][c] = 0; }
			}
		}
		min = enumerate();
		if (min != s * s + 1) { cout << min << endl; }
		else { cout << "inf" << endl; }
	}
	return 0;
}