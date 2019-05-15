#include <iostream>
#include <set>
using namespace std;

struct two {
	int l, r;
	two(int _l, int _r) :l(_l), r(_r) {}
};

struct cmp {
	bool operator()(const two& t1, const two& t2) {
		return t1.l > t2.l;
	}
};

multiset<int> S; multiset<int>::iterator Si, Sii;
set<two,cmp> Set;

int main() {
	int n, t, n1; cin >> n >> t;
	while (n--) {
		cin >> n1;
		S.insert(n1);
	}
	
	for (Si = S.begin(); Si != S.end(); ++Si) {
		int l = *Si;
		Sii = S.find(*Si + t);
		if (Sii != S.end() && Sii != Si) {
			int r = *Sii;
			Set.insert(two(l, r));
			S.erase(Sii);
		}
	}
	cout << (int)Set.size();

	return 0;
}