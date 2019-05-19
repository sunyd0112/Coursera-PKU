#include<iostream>
#include<cstring>
#include<set>
#include<map>
using namespace std;

map<string, set<int> >M;
string s;

int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> m;
		for (int j = 1; j <= m; ++j) {
			cin >> s;
			if (M.find(s) != M.end()) { M[s].insert(i); }//M[s].insert(i)
			else {
				set<int>tmp;
				tmp.insert(i);
				M.insert(make_pair(s, tmp));
			}
		}
	}
	cin >> m;
	while (m--) {
		cin >> s;
		if (M.find(s) != M.end()) {
			set<int>::iterator it = M[s].begin();
			for (; it != M[s].end(); ++it) {
				cout << *it << " ";
			}
		}
		else {
			cout << "NOT FOUND";
		}
		cout << endl;
	}
	return 0;
}