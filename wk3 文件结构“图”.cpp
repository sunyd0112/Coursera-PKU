#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class com {
public:
	bool operator()(string a, string b) {
		int a1 = a.length(), b1 = b.length(), i;
		for (i = 0; i < a1 && i < b1; i++) {
			if (a[i] < b[i])
				return false;
			if (b[i] < a[i])
				return true;
		}
		if (i == a1) return false;
		return true;
	}
};

string command; priority_queue<string, vector<string>, com> pri[1000]; int flag;

int main() {
	int n = 0, level = 0;
	cout << "DATA SET " << ++level << ":" << endl;
	cout << "ROOT" << endl;
	while (cin >> command) { 
		if (command == "#") { return 0; }
		if (flag == 1) {
			cout << "DATA SET " << ++level << ":" << endl;
			cout << "ROOT" << endl; flag = 0;
		}
		if (command.at(0) == 'f') {
			if (n == 0) { pri[n].push(command); }
			else { pri[n].push(command); }
		}
		else if (command.at(0) == 'd') {
			++n;
			for (int i = 0; i < n; ++i) { cout << "|     ";
			}
			cout << command << endl;
		}
		else if (command == "*") {
			while (!pri[n].empty()) { cout << pri[n].top() << endl; pri[n].pop(); }
			cout << endl;
			flag = 1; 
		}
		else if (command == "]") {
			while (!pri[n].empty()) {
				for (int j = 0; j < n; ++j) {
					cout << "|     ";
				}
				cout << pri[n].top() << endl; pri[n].pop();
			}
			--n; 
		}
	}
}