#include <iostream>
using namespace std;

int father[100100], relation[100100];

int Father(int x) {
	if (x == father[x])
		return x;
	else {
		int temp = Father(father[x]);
		relation[x] = (relation[father[x]] + relation[x]) % 2;
		father[x] = temp;
	}
	return father[x];
}

void Union(int x, int y) {
	int fx = Father(x);
	int fy = Father(y);
	father[fx] = fy;
	if (relation[y] == 0)
		relation[fx] = 1 - relation[x];
	else
		relation[fx] = relation[x];
}

int main() {
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			father[i] = i;
			relation[i] = 0;
		}
		while (M--) {
			getchar();
			char cmd; int n1, n2;
			cin >> cmd >> n1 >> n2;

			if (cmd == 'D')
				Union(n1, n2);
			else if (cmd == 'A') {
				int fx = Father(n1);
				int fy = Father(n2);

				if (fx != fy)
					cout << "Not sure yet." << endl;
				else if (relation[n1] == relation[n2])
					cout << "In the same gang." << endl;
				else
					cout << "In different gangs." << endl;
			}
		}
	}
	return 0;
}
