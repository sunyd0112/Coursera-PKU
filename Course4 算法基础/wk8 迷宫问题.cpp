#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int marked[5][5] = { 0 }; //to mark if the point has been covered
int to[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; //direction

struct ways {
	int i, j;
	vector<ways> v;
	ways(int ii, int jj) :i(ii), j(jj) {}
};
queue <ways> q;

int main() {
	int maze[5][5];
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> maze[i][j];
		}
	}
	q.push(ways(0, 0)); marked[0][0] = 1;//push and mark the first situation

	while (!q.empty()) {// Ready? Go!
		ways w = q.front(); w.v.push_back(w); //put itself in as a father position
		if (w.i==4 && w.j==4){ 
			for (vector<ways>::iterator vi = w.v.begin(); vi != w.v.end(); ++vi) {
				cout << "("<<vi->i<<", "<<vi->j<<")" << endl;
			}
			return 0; 
		} //found it!
		else {
			for (int i = 0; i < 4; ++i) {
				if (w.i+to[i][0]>=0 && w.i + to[i][0] <= 4 && w.j + to[i][1] >= 0 && w.j + to[i][1] <= 4 && marked[w.i + to[i][0]][w.j + to[i][1]]==0 && maze[w.i + to[i][0]][w.j + to[i][1]]!=1){
					marked[w.i + to[i][0]][w.j + to[i][1]] = 1;
					ways w1(w.i + to[i][0], w.j + to[i][1]); w1.v = w.v; q.push(w1);
				}
			}
			q.pop();
		}
	}

	return 0;
}
