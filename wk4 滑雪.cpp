#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

struct Num{
	int i, j, L;
	Num(int ii, int jj, int LL) :i(ii), j(jj), L(LL) {}
};

int main() {
	int m, n; cin >> m >> n;
	int H[110][110] = { 0 }; int maxmillion = 0;
	multimap<int, Num> M; multimap<int, Num>::iterator Mi, Mii;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> H[i][j]; Num num(i, j, 1);
			M.insert(multimap<int, Num>::value_type(H[i][j], num));
		}
	}

	for (Mi = M.begin(); Mi != M.end(); ++Mi) {
		if (Mi->second.L > maxmillion) { maxmillion = Mi->second.L; }
		if (H[Mi->second.i - 1][Mi->second.j] > H[Mi->second.i][Mi->second.j]) {

			int count = M.count(H[Mi->second.i - 1][Mi->second.j]);
			Mii = M.lower_bound(H[Mi->second.i - 1][Mi->second.j]);
			for (int i = 1; i < count; ++i) { 
				if (Mii->second.i != Mi->second.i - 1 || Mii->second.j != Mi->second.j) { ++Mii; }
				else { break; }
			}

			Mii->second.L = max(Mii->second.L, Mi->second.L + 1);
			if (Mii->second.L>maxmillion){ maxmillion = Mii->second.L; }
		}
		if (H[Mi->second.i][Mi->second.j - 1] > H[Mi->second.i][Mi->second.j]) {

			int count = M.count(H[Mi->second.i][Mi->second.j - 1]);
			Mii = M.lower_bound(H[Mi->second.i][Mi->second.j - 1]);
			for (int i = 1; i < count; ++i) {
				if (Mii->second.j != Mi->second.j - 1 || Mii->second.i != Mi->second.i) { ++Mii; }
				else { break; }
			}

			Mii->second.L = max(Mii->second.L, Mi->second.L + 1);
			if (Mii->second.L > maxmillion) { maxmillion = Mii->second.L; }
		}
		if (H[Mi->second.i + 1][Mi->second.j] > H[Mi->second.i][Mi->second.j]) {

			int count = M.count(H[Mi->second.i + 1][Mi->second.j]);
			Mii = M.lower_bound(H[Mi->second.i + 1][Mi->second.j]);
			for (int i = 1; i < count; ++i) {
				if (Mii->second.i != Mi->second.i + 1 || Mii->second.j != Mi->second.j) { ++Mii; }
				else { break; }
			}

			Mii->second.L = max(Mii->second.L, Mi->second.L + 1);
			if (Mii->second.L > maxmillion) { maxmillion = Mii->second.L; }
		}
		if (H[Mi->second.i][Mi->second.j + 1] > H[Mi->second.i][Mi->second.j]) {

			int count = M.count(H[Mi->second.i][Mi->second.j + 1]);
			Mii = M.lower_bound(H[Mi->second.i][Mi->second.j + 1]);
			for (int i = 1; i < count; ++i) {
				if (Mii->second.j != Mi->second.j + 1 || Mii->second.i != Mi->second.i) { ++Mii; }
				else { break; }
			}

			Mii->second.L = max(Mii->second.L, Mi->second.L + 1);
			if (Mii->second.L > maxmillion) { maxmillion = Mii->second.L; }
		}
	}

	cout << maxmillion;
	return 0;
}