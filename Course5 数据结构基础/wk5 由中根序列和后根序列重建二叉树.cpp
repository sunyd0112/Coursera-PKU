#include <iostream>
#include <map>
#include <stack>
using namespace std;

int father, node;
stack<int> In, Post, InR, PostR;
map<int, int> M; map<int, int>::iterator Mi;
void Findright();

void Findleft() {
	int count = 0;
	while (In.top() != node) {
		++count;
		InR.push(In.top()); In.pop();
	}
	InR.push(In.top()); In.pop();//pop root

	for (int i = 0; i < count; ++i) { PostR.push(Post.top()); Post.pop(); } //find node 2
	father = node; node = Post.top(); cout << node << " "; //how to eliminate the blank
	M.insert(map<int, int>::value_type(node, father));
	PostR.push(Post.top()); Post.pop();

}

void Findright() {
	Mi = M.find(node); int count = 0;
	if (InR.empty() || InR.top() != Mi->second) { return; }
	while (1) {
		if (PostR.top() == Mi->first) { PostR.pop(); break; }
		else { PostR.pop(); }
	}
	InR.pop();
	while (!In.empty()) { In.pop(); }

	while (1) {
		if (PostR.top() == Mi->second) { break; }
		++count;
		Post.push(PostR.top()); PostR.pop();
	}
	if (count == 0) { return; }
	PostR.push(Post.top()); // push back 9

	for (int i = 0; i < count; ++i) { In.push(InR.top()); InR.pop(); }
	if (!Post.empty()) {
		father = Mi->second; node = Post.top();
		M.insert(map<int, int>::value_type(node, father));
		cout << node << " "; Post.pop();
		while (!Post.empty()) {
			while (!Post.empty()) { Findleft(); }
			Findright();
		}

		node = Mi->second; Findright();
	}
}

int main() {
	int n = 0, root = 0; char nn;
	while (cin >> n) { //inorder
		In.push(n);
		nn = cin.get();
		if (nn == '\n') { break; }
	}
	while (cin >> n) { //postorder
		Post.push(n);
		nn = cin.get();
		if (nn == '\n') { break; }
	}

	if (Post.empty()) { return 0; } //empty input
	root = n; node = n; cout << node << " ";
	Post.pop(); PostR.push(node);//root

	while (!Post.empty()) { Findleft(); } //find all node in the left
	Findright();

	return 0;
}