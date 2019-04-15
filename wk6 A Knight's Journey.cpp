#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

vector<string> v; vector<string>::iterator vi;  
bool mark[30][30]; int sum, total, n, nn = 0, m, to[8][2] = { {-1,-2 }, { 1,-2 }, { -2,-1 }, { 2,-1 }, { -2,1 }, { 2,1 }, { -1,2 }, { 1,2 } };

void Dfs(int p1, int p2){
	string position;
	if (total == n * m) { 
		sum = total;
		cout << "Scenario #" << nn << ":" << endl;
		for (vi = v.begin(); vi != v.end(); ++vi) { cout << *vi; }
		cout << endl << endl; 
		return; 
	}
	
	for (int i = 0; i < 8; ++i) {
		p1 += to[i][0]; p2 += to[i][1];
		if (p1 >= 1 && p1 <= n && p2 >= 1 && p2 <= m && mark[p1][p2]==false) {
			mark[p1][p2] = true; ++total;
			position = p2 + 16 + '0'; position += (char)(p1 + '0');
			v.push_back(position);
			Dfs(p1, p2);
			if (sum == n * m) { return; }
			mark[p1][p2] = false; --total; vi = v.end() - 1; v.erase(vi); p1 -= to[i][0]; p2 -= to[i][1];
		}
		else { p1 -= to[i][0]; p2 -= to[i][1]; }
	}

}

int main() {
	int caseN; cin >> caseN;
	while (caseN - nn) {
		++nn;
		cin >> n >> m;

		memset(mark, false, sizeof(mark)); total = 1, sum=0; v.clear(); int p1 = 1, p2 = 1;
		mark[1][1] = true; v.push_back("A1"); 
		Dfs(p1, p2);
		if (sum != n * m) { cout << "Scenario #" << nn << ":" << endl << "impossible" << endl << endl; }
	}
	return 0;
}