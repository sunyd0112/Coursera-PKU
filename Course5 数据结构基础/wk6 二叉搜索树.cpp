#include <iostream>
using namespace std;

struct node {
	int n;
	node* l, * r;
};

void PreOrder(node* a) {
	if (a != NULL) {
		cout << a->n << " ";
		PreOrder(a->l);
		PreOrder(a->r);
	}
}

int main() {
	node* root, * fa, * cur; char nn;
	int n; cin >> n; 
	root = new node;
	root->n = n; root->l = NULL; root->r = NULL;

	while (cin >> n) {
		cur = new node;
		cur->n = n; cur->l = NULL; cur->r = NULL;

		fa = root;
		while (fa) {
			if (cur->n == fa->n) { break; }
			else if (cur->n > fa->n) { 
				if (fa->r == NULL) { fa->r = cur; break; }
				else fa = fa->r; 
			}
			else if (cur->n < fa->n) { 
				if (fa->l == NULL) { fa->l = cur; break; }
				else fa = fa->l; 
			}
		}
		nn = cin.get();
		if (nn == '\n') { break; }
	}
	PreOrder(root);

	return 0;
}