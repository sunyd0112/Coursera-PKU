#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<map>
using namespace std;

char ex[55] = { '\0' }, space[105][305];

struct Node {
	char c;
	Node* l, * r;
	Node(char cc) { c = cc; l = NULL; r = NULL; }
};

int CountLayer(Node* root) {
	if (root == NULL)return 0;
	int L = CountLayer(root->l);
	int R = CountLayer(root->r);
	if (L >= R)return L + 1;
	else return R + 1;
}
void MakeTree(Node* root, int x, int y, int wide) {
	if (root == NULL)return;
	space[y][x - 1] = root->c;
	if (root->l != NULL) {
		space[y + 1][x - 2] = '/';
		MakeTree(root->l, x - wide, y + 2, wide >> 1);
	}
	if (root->r != NULL) {
		space[y + 1][x] = '\\';
		MakeTree(root->r, x + wide, y + 2, wide >> 1);
	}
}
int main() {
	//输出逆波兰表达式 
	string s; cin >> s;
	int pos = 0;
	stack<char> S;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] >= 'a' && s[i] <= 'z') { ex[pos++] = s[i]; }
		else if (s[i] == '(') { S.push(s[i]); }
		else if (s[i] == ')') {
			while (S.top() != '(') {
				ex[pos++] = S.top();
				S.pop();
			}
			S.pop();
		}
		else if (s[i] == '+' || s[i] == '-') {
			while (!S.empty() && S.top() != '(') {
				ex[pos++] = S.top();
				S.pop();
			}
			S.push(s[i]);
		}
		else if (s[i] == '*' || s[i] == '/') {
			while (!S.empty() && (S.top() == '*' || S.top() == '/')) {
				ex[pos++] = S.top();
				S.pop();
			}
			S.push(s[i]);
		}
	}
	while (!S.empty()) {
		ex[pos++] = S.top();
		S.pop();
	}
	cout << ex << endl;

	//输出表达式树 
	Node N('\0');
	Node* root = &N;
	stack<Node*>S1;
	for (int i = 0; i < pos; ++i) {
		root = new Node(ex[i]);
		if (ex[i]<'a' || ex[i]>'z') {
			root->r = S1.top();
			S1.pop();
			root->l = S1.top();
			S1.pop();
		}
		S1.push(root);
	}
	memset(space, ' ', sizeof(space));
	int Layer = CountLayer(root);
	MakeTree(root, 1 << (Layer - 1), 0, 1 << (Layer - 2));
	for (int i = 0; i < ((Layer << 1) - 1); ++i) {
		int j = 300;
	    while (j > 0 && space[i][j] == ' ') j--;
	    space[i][j + 1] = 0;
	}
	for (int i = 0; i < ((Layer << 1) - 1); ++i) { cout << space[i] << endl; }

	//输出表达式的值 
	int n, a;
	char c;
	stack<int>T;
	map<char, int> M;
	cin >> n;
	for (int i = 0; i < n; ++i) { cin >> c >> a; M[c] = a; }
	for (int i = 0; i < pos; ++i) {
		if (ex[i] >= 'a' && ex[i] <= 'z') {
			T.push(M[ex[i]]);
			continue;
		}
		int tmp1 = T.top(); T.pop();
		int tmp2 = T.top(); T.pop();
		if (ex[i] == '+') { T.push(tmp2 + tmp1); }
		else if (ex[i] == '-') { T.push(tmp2 - tmp1); }
		else if (ex[i] == '*') { T.push(tmp2 * tmp1); }
		else if (ex[i] == '/') { T.push(tmp2 / tmp1); }
	}
	cout << T.top() << endl;
	return 0;
}