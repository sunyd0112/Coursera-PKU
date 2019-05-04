#include <iostream>
#include <queue>
using namespace std;

struct node {
	int l, r, fa; //subscript of N to indicate the position
	int p, w;
	bool operator<(const node& x) const {
		return w > x.w; //com function used in priority_queue
	}
}; node N[220];

int main() {
	priority_queue<node> q;
	int n, w, t = 0;
	while (cin >> n) {
		while (n--) {
			cin >> w;
			++t;
			N[t] = node{ 0,0,t,w,0 };
			q.push(N[t]);
		}
		while (q.size() > 1) {
			node x1 = q.top();
			q.pop();
			node x2 = q.top();
			q.pop();
			++t;
			N[t] = node{ x1.p,x2.p,t,x1.w + x2.w,0 };
			N[x1.p].fa = t;
			N[x2.p].fa = t;
			q.push(N[t]);
		}
		int ans = 0;
		for (int i = 1; i <= t; i++) {
			if (N[i].l == 0) {
				int dep = 0;
				node x = N[i];
				while (x.fa != 0) {
					++dep;
					x = N[x.fa];
				}
				ans += dep * N[i].w;
			}
		}
		cout << ans << endl;
	}
	return 0;
}