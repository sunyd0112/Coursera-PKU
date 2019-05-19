#include<iostream>
#include<set>
#include<map>
using namespace std;

map<int, set<int> >M;
set<int>::iterator si, sii;
int s;

int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> m;
		for (int j = 1; j <= m; ++j) {
			cin >> s;
			if (M.find(i) != M.end()) M[i].insert(s); 
			else {
				set<int>tmp;
				tmp.insert(s);
				M.insert(make_pair(i, tmp));
			}
		}
	}

	cin >> m;
	while (m--) {
		set<int> add, del; bool flag = true;

		for (int i = 1; i <= n; ++i) {
			int command; cin >> command;
			if (command == -1) {
				for (si = M[i].begin(); si != M[i].end(); ++si) {
					del.insert(*si);
				}
			}
			else if (command == 1) {
				if (!add.empty()) {
					for (si = add.begin(); si != add.end(); ++si) {
						sii = M[i].find(*si);
						if (sii == M[i].end()) { del.insert(*si); }
					}
				}
				else {
					for (si = M[i].begin(); si != M[i].end(); ++si) {
						add.insert(*si);
					}
					flag = false;
				}
			}
		}
		for (si = del.begin(); si != del.end(); ++si) {
			sii = add.find(*si);
			if (sii != add.end()) { add.erase(sii); }
		}
		if (add.empty()) { cout<<"NOT FOUND"<<endl; }
		else {
			for (si = add.begin(); si != add.end(); ++si) {
				cout << *si << " ";
			}
			cout << endl;
		}
		del.clear(); add.clear();
	}
	return 0;
}