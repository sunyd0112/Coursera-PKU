#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

int a[30][4] = { 0 }, result[30] = { 0 };
struct Pool {
	int fish, i, de;
	Pool(int pp1, int pp2, int pp3) :fish(pp1), i(pp2),de(pp3) {}
};

struct MyLess {
	bool operator()(const Pool & a1, const Pool & a2){
		if (a1.fish != a2.fish) { return a1.fish > a2.fish; }
		else return a1.i < a2.i;
	}
};

int main() {
	int n, h; multiset < Pool, MyLess > pooo; multiset<Pool, MyLess >::iterator pi, temppi;
	while (cin >> n) {
		if (n == 0) { return 0; }
		
		cin >> h; h *= 60; 
		memset(a, 0, sizeof(a)); memset(result, 0, sizeof(result)); pooo.clear();
		for (int i = 1; i <= n; ++i) { cin >> a[i][1]; }
		for (int i = 1; i <= n; ++i) { 
			cin >> a[i][2]; 
			pooo.insert((Pool(a[i][1], i, a[i][2])));
		}
		for (int i = 2; i <= n; ++i) { cin >> a[i][3]; a[i][3] *= 5; }

		if (n == 1) {
			cout << h << endl;
			cout << "Number of fish expected: " << h / 5 * (a[1][1] + a[1][1] - (h / 5 - 1) * a[1][2]) / 2 << endl;
			cout << endl;
			continue;
		}

		//compute separately if the man will only visit one pool
		//must consider whether the divisor is zero
		int sum = 0, tempsum = 0, count, temph;
		for (int i = 1; i <= n; ++i) {
			temph = h - a[i][3];
			if (a[i][2] == 0) { count = temph / 5; }
			else { count = min(temph / 5, a[i][1] / a[i][2] + 1); }
			tempsum = count * (a[i][1] + a[i][1] - (count - 1) * a[i][2]) / 2;
			if (tempsum > sum) {
				sum = tempsum;
				memset(result, 0, sizeof(n + 1)); result[i] = temph;
			}
		}

		//if he considered to visit every pool
		temph = h; tempsum = 0; int tempmax, tempi, templess;
		for (int i = 2; i <= n; ++i) { temph -= a[i][3]; a[i][3] = 0; }
		while (temph) {
			pi = pooo.begin();
			if (pi->fish <= 0) {
				if (tempsum > sum) {
					sum = tempsum; 
					for (int i = 1; i <= n; ++i) { result[i] = a[i][3] * 5; }
					result[1] += temph; break;
				}
			}
			else { 
				tempsum += pi->fish; a[pi->i][3] += 1; temph -= 5;
				tempmax = pi->fish - pi->de; tempi = pi->i; templess = pi->de; pooo.erase(pi);
				pooo.insert(Pool(tempmax, tempi, templess));
			}

		}
		if (temph <= 0) {
			if (tempsum > sum) {
				sum = tempsum;
				for (int i = 1; i <= n; ++i) { result[i] = a[i][3] * 5; }
				result[1] += temph;
			}
		}

		//cout
		int i;
		for ( i = 1; i < n; ++i) { cout << result[i] << ", "; }
		cout << result[i] << endl;
		cout << "Number of fish expected: " << sum << endl;
		cout << endl;
	}
	return 0;
}