#include<iostream>
#include<queue>
using namespace std;

struct Node {
	char root;
	int num;
	Node* childarray[26], *father;
	Node(char c, int ch=0, Node* N=NULL):root(c), num(ch), father(NULL){}
};

Node* root('\0'), * child('\0'), * cur('\0');
queue<Node*> Q, QR;

void MakeTree() {
	Q.push(root);
	while (!Q.empty()) {
		cur = Q.front(); Q.pop();
		int i = 1;
		while (i <= cur->num) {
			char childc; cin >> childc;
			int childn; cin >> childn;
			child = new Node(childc, childn, cur);
			if (childn > 0) { Q.push(child); }
			cur->childarray[i] = child;
			++i;
		}
	}
}

void PostOrder(Node* N) {
	if (N->num > 0) {
		for (int i = 1; i <= N->num;++i) {
			if (N->childarray[i]->num > 0) { PostOrder(N->childarray[i]); }
			else cout << N->childarray[i]->root << " ";
		}
		cout << N->root << " ";
	}
	else cout << N->root << " ";
}

int main() {
	int caseN; cin >> caseN;
	while (caseN--) {
		char c; cin >> c;
		int n; cin >> n;
		root = new Node(c,n);
		QR.push(root);
		MakeTree();
	}
	while (!QR.empty()) { 
		root = QR.front(); QR.pop();
		PostOrder(root);
     }

	return 0;
}