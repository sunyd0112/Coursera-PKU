#include <iostream>
#include <vector>
using namespace std;

vector<int> v; vector<int>::iterator vi;

int main() {
	int n, sum; bool flag = false;
	while (cin >> n) { v.push_back(n); if (n == 0) { break; } }

	vi = v.begin();
	while (*vi) {
		n = *vi;
		for (int i = 1; ; ++i) {
			if ((i * n + 1) % (n - 1) != 0) { continue; }
			sum = (i * n + 1) / (n - 1);
			for (int j = 1; j < *vi; ++j) {
				if ((sum * n + 1) % (n - 1) != 0 && j != *vi - 1) { break; }
				else { 
					if (j == *vi - 1) { sum = sum * n + 1; flag = true; }
					else { sum = (sum * n + 1) / (n - 1); }
				}
			}
			if (flag) { cout << sum << endl; flag = false; sum = 0; break; }
		}
		v.erase(vi); vi = v.begin();
	}

	return 0;                     
}
