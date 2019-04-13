#include<iostream>
#include<cstring>
#include<set>
using namespace std;

int Search(int s, multiset<int> A, multiset<int> B, int F[10010]) {
	set<int>::iterator ai = A.end(); --ai; set<int>::iterator bi = B.end(); --bi;
	int count = 0;
	if (*ai + *bi < s) { return 0; }
	ai = A.begin(); bi = B.begin();
	if (*ai + *bi > s) { return 0; }
	else {
		for ( ; ai != A.end(); ++ai) {
			if (F[*ai] == -1) { F[*ai] = B.count(s - *ai); }
			count += F[*ai]; 
		}
	}
	return count;
}

multiset<int> A, B;

int main() {
	int caseN; cin >> caseN;
	while (caseN--) {
		int s; cin >> s;
		int a, a1; cin >> a;
		for (int i = 0; i < a; ++i) { cin >> a1; A.insert(a1); }
		int b, b1; cin >> b;
		for (int i = 0; i < b; ++i) { cin >> b1; B.insert(b1); }
		int F[10010];
		memset(F, -1, sizeof(F));
		cout << Search(s, A, B, F) << endl;
		A.clear(); B.clear();
	}
}