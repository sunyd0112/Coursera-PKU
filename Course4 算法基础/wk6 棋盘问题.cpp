#include<iostream>
#include<cstring>
using namespace std;

char** a; int markR[10] = { 0 }, markC[10] = { 0 }, total = 0, sum = 0, currentR = 1, currentC = 1;
int n, k;

void Dfs() {
	if (total == k) { 
		sum += 1; return; }

	for (int i = currentR; i <= n; ++i) { //剪枝1 下一个点从下一行开始
		for (int j = currentC; j <= n; ++j) {
			if (a[i][j] == '#' && markR[i] != 1 && markC[j] != 1) {
				markR[i] = 1; markC[j] = 1; ++total;
				currentR = i + 1; currentC = 1;
				Dfs();
				--total; markR[i] = 0; markC[j] = 0;
			}
		}
		currentC = 1;
	}

}

int main() {
	while (1) {
		cin >> n >> k; cin.get();
		if (n == -1 || k == -1) { return 0; }

		a = new char* [n + 1];
		for (int i = 0; i < n + 1; ++i) { a[i] = new char[n + 2]; }
		for (int i= 1; i <= n; ++i) { 
			for (int j = 1; j <= n; ++j) {
				cin >> a[i][j];
			}
		}

		sum = 0, currentR = 1, currentC = 1;
		memset(markR, 0, sizeof(markR)); memset(markC, 0, sizeof(markC)); 
		Dfs();
		cout << sum << endl;
	}
	return 0;
}
