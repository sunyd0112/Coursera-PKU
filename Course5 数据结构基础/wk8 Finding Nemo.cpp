#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct Labyrinth {
	int u, d, l, r;
} Lab[205][205];

struct Marlin {
	int x, y, door;
	Marlin(int _x, int _y, int _door) :x(_x), y(_y), door(_door) {}
	friend bool operator <(const Marlin& m1, const Marlin& m2) {
		return m1.door > m2.door;
	}
};

int Nemox, Nemoy, visited[205][205] = { 0 }, maxx = 0, maxy = 0;
priority_queue<Marlin> pri;

void BFS() {
	int x, y, x1, y1, door, door1;
	while (!pri.empty()) { pri.pop(); }
	pri.push(Marlin(0, 0, 0));
	visited[0][0] = 1;

	while (!pri.empty()) {
		Marlin marlin = pri.top(); pri.pop();
		x = marlin.x; y = marlin.y; door = marlin.door;
		if (x == Nemox && y == Nemoy) { cout << door << endl; return; }

		if (Lab[x][y + 1].d != -1 && visited[x][y + 1] != 1 && x >= 0 && y + 1 >= 0 && x <= maxx && y + 1 <= maxy) {
			x1 = x; y1 = y + 1;
			visited[x1][y1] = 1;
			door1 = door + Lab[x1][y1].d;
			pri.push(Marlin(x1, y1, door1));
		}
		if (Lab[x][y - 1].u != -1 && visited[x][y - 1] != 1 && x >= 0 && y - 1 >= 0 && x <= maxx && y - 1 <= maxy) {
			x1 = x; y1 = y - 1;
			visited[x1][y1] = 1;
			door1 = door + Lab[x1][y1].u;
			pri.push(Marlin(x1, y1, door1));
		}
		if (Lab[x + 1][y].l != -1 && visited[x + 1][y] != 1 && x + 1 >= 0 && y >= 0 && x + 1 <= maxx && y <= maxy) {
			x1 = x + 1; y1 = y;
			visited[x1][y1] = 1;
			door1 = door + Lab[x1][y1].l;
			pri.push(Marlin(x1, y1, door1));
		}
		if (Lab[x - 1][y].r != -1 && visited[x - 1][y] != 1 && x - 1 >= 0 && y >= 0 && x - 1 <= maxx && y <= maxy) {
			x1 = x - 1; y1 = y;
			visited[x1][y1] = 1;
			door1 = door + Lab[x1][y1].r;
			pri.push(Marlin(x1, y1, door1));
		}
	}
	cout << -1 << endl;
	return;
}

int main() {
	int M, N;
	while (cin >> M >> N) {
		if (M == -1 && N == -1) { return 0; }

		int x, y, d, t;
		memset(Lab, 0, sizeof(Lab));
		memset(visited, 0, sizeof(visited));

		while (M--) {
			cin >> x >> y >> d >> t;
			if (d == 0) { //x
				for (int i = 0; i < t; ++i) {
					Lab[x + i][y].d = -1;
					Lab[x + i][y - 1].u = -1;
				}

				if (maxx < x + t) { maxx = x + t; }
				if (maxy < y) { maxy = y; }
			}
			else if (d == 1) {//y
				for (int i = 0; i < t; ++i) {
					Lab[x][y + i].l = -1;
					Lab[x - 1][y + i].r = -1;
				}

				if (maxx < x) { maxx = x; }
				if (maxy < y + t) { maxy = y + t; }
			}
		}
		while (N--) {
			cin >> x >> y >> d;

			if (d == 0) {
				Lab[x][y].d = 1;
				Lab[x][y - 1].u = 1;

				if (maxx < x) { maxx = x; }
				if (maxy < y) { maxy = y; }
			}
			else if (d == 1) {
				Lab[x][y].l = 1;
				Lab[x - 1][y].r = 1;

				if (maxx < x) { maxx = x; }
				if (maxy < y) { maxy = y; }
			}
		}
		double posx, posy;
		cin >> posx >> posy;
		if (posx < 1 || posy < 1 || posx>maxx || posy>maxy) {
			cout << 0 << endl; continue;
		}
		Nemox = (int)posx; Nemoy = (int)posy;
		BFS();
	}
	return 0;
}
