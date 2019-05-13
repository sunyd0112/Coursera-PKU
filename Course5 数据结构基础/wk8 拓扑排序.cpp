#include<iostream>
#include<set>
using namespace std;

int In[1000000] = { 0 }, Out[1000000] = { 0 };
bool alone[1000000] = { 0 };
set<int> s, S[1000000]; set<int>::iterator si, tempsi;

int main(){
	int v, Line, v1, v2; cin >> v >> Line;
	while (Line--) {
		cin >> v1 >> v2;
		if (!S[v1].empty()) {
			si = S[v1].find(v2);
			if (si == S[v1].end()) {
				Out[v1]++; In[v2]++;
				S[v1].insert(v2); s.insert(v2);
			}
		}
		else if (v1 == v2) {
			alone[v1] = true; 
			s.insert(v1);
		}
		else {
			Out[v1]++; In[v2]++;
			S[v1].insert(v2);
			s.insert(v1); s.insert(v2);
		}
	}

	while (v > 1) {
		for (tempsi = s.begin(); tempsi != s.end(); ++tempsi) {
			if ((In[*tempsi] == 0 && Out[*tempsi] != 0)|| alone[*tempsi]==true) {
				if (!S[*tempsi].empty()) {
					for (si = S[*tempsi].begin(); si != S[*tempsi].end(); ++si) { 
						In[*si]--; 
						if (In[*si]==0 && Out[*si]==0){ alone[*si] = true; }
					}
				}
				Out[*tempsi] = 0; alone[*tempsi] = false;
				cout << 'v' << *tempsi << " ";
				si = s.find(*tempsi); s.erase(si);
				v--; break;
			}
		}
	}
	si = s.begin(); cout << 'v' << *si;

	return 0;
}