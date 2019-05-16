#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

struct peanuts {
	int amount, i, j;
	peanuts(){}
	peanuts(int _a, int _i, int _j):amount(_a),i(_i),j(_j){}
};

struct cmp {
	bool operator ()(peanuts& p1, peanuts& p2) {
		return p1.amount < p2.amount;
	}
};

priority_queue<peanuts, vector<peanuts>, cmp> pri;
int grass[55][55];

int main() {
	int caseN; cin >> caseN;
	while (caseN--) {
		int M, N, K; cin >> M >> N >> K; peanuts Dodo;

		memset(grass, 0, sizeof(grass));
		while (!pri.empty()){ Dodo = pri.top(); pri.pop(); }

		for (int i = 1; i <= M; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> grass[i][j];
				if (grass[i][j] > 0) {
					pri.push(peanuts(grass[i][j], i, j));
				}
			}
		}
		int curi = 0, curj = 0, count = 0;
		Dodo = pri.top(); pri.pop();
		if (K < Dodo.i * 2 + 1) { cout << 0 << endl; continue; }
		else if (K == Dodo.i * 2 + 1){ cout << grass[Dodo.i][Dodo.j] << endl; continue; }
		else { 
			K -= Dodo.i + 1; count += grass[Dodo.i][Dodo.j]; 
			curi = Dodo.i; curj = Dodo.j;
		}

		while (!pri.empty()) {
			Dodo = pri.top(); pri.pop();
			if (K < abs(Dodo.i - curi) + abs(Dodo.j - curj) + 1 + Dodo.i) {
				break;
			}
			else if (K == abs(Dodo.i - curi) + abs(Dodo.j - curj) + 1 + Dodo.i) {
				count += grass[Dodo.i][Dodo.j]; break;
			}
			else {
				count += grass[Dodo.i][Dodo.j];
				K -= abs(Dodo.i - curi) + abs(Dodo.j - curj) + 1;
				curi = Dodo.i; curj = Dodo.j;
			}
		}
		cout << count << endl;
	}
	
	return 0;
}