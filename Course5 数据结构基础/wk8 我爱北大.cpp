#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int Distance[35][35], Path[35][35], p, q, r;
string str1, str2;
map<string, int> Place; map<string, int>::iterator p1, p2;

void InputPlace() {
	memset(Distance, 0, sizeof(Distance)); 
	memset(Path, -1, sizeof(Path));

	cin >> p; 
	for (int i = 0; i < p; ++i) {
		cin >> str1;
		Place.insert(map<string, int>::value_type(str1, i));
		for (int j = 0; j < p; ++j) {
			if (i == j) { Path[i][j] = i; }
			else { Distance[i][j] = INT_MAX; }
		}
	}
}

void InputRoad() {
	cin >> q; 
	while (q--) {
		cin >> str1 >> str2;
		p1 = Place.find(str1); p2 = Place.find(str2);
		int i = p1->second, j = p2->second;
		int distance; cin >> distance;
		if (distance < Distance[i][j]) {
			Distance[i][j] = distance;
			Distance[j][i] = distance;
		}
	}

	for (int k = 0; k < p; ++k) {
		for (int i = 0; i < p; ++i) {
			for (int j = 0; j < p; ++j) {
				int d1 = Distance[i][j], d2 = INT_MAX;
				if (Distance[i][k] != INT_MAX && Distance[k][j] != INT_MAX) {
					d2 = Distance[i][k] + Distance[k][j];
				}
				if (d2 < d1) {
					Distance[i][j] = d2; 
					Path[i][j] = k;
				}
			}
		}
	}
}

void Printresult(int a, int b) {
	if (Path[a][b] == -1) {
		for (p1 = Place.begin(); p1 != Place.end(); p1++) {
			if (p1->second == b) { str1 = p1->first; break; }
		}
		cout << "->(" << Distance[a][b] << ")->" << str1;
		return;
	}
	Printresult(a, Path[a][b]);
	Printresult(Path[a][b], b);
}

void FindRoad() {
	cin >> r;
	while (r--) {
		cin >> str1 >> str2;
		p1 = Place.find(str1); p2 = Place.find(str2);
		int i = p1->second, j = p2->second;
		
		if (i == j) { cout << p1->first << endl; continue; }
		cout << p1->first;Printresult(i, j);cout << endl;
	}
}

int main() {

	InputPlace();
	InputRoad();
	FindRoad();

	return 0;
}