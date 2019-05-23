#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m; map<long long, long long>::iterator mi;
int n;

int main() {
	while (cin >> n) {
		if (n == 0) { return 0; }
		
		if (n == 1) {
			long long p, id; cin >> id >> p;
			m.insert(map<long long, long long>::value_type(p, id));
		}
		else if (n == 2) {
			if (m.empty()) { cout << 0 << endl; continue; }
			mi = m.end(); --mi;
			cout << mi->second << endl;
			m.erase(mi);
		}
		else if (n == 3) {
			if (m.empty()) { cout << 0 << endl; continue; }
			mi = m.begin();
			cout << mi->second << endl;
			m.erase(mi);
		}
	}

	return 0;
}
