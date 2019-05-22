#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

char s[22];
queue<string> que;

struct Dictionary {
	int a;
	Dictionary* next[26];
}* Dic, *dic;

void insert() {
	int len = strlen(s), n, i; dic = Dic;
	for (i = 0; i < len - 1; ++i) {
		n = s[i] - 'a';
		if (dic->next[n] == NULL) {
			dic->next[n] = new Dictionary;
			dic = dic->next[n];
			dic->a = 1;
			for (int i = 0; i < 26; ++i) { dic->next[i] = NULL; }
		}
		else {
			dic = dic->next[n];
			dic->a += 1;
		}
	}
	n = s[i] - 'a';
	if (dic->next[n] == NULL) {
		dic->next[n] = new Dictionary;
		dic = dic->next[n];
		dic->a = 1;
		for (int i = 0; i < 26; ++i) { dic->next[i] = NULL; }
	}
	else { 
		dic = dic->next[n]; 
		dic->a += 1;
	}
}

void output(int count) {
	cout<<s<<" ";
	for (int i = 0; i <= count; ++i) { cout << s[i]; }
	cout << endl;
}

void search() {
	int len = strlen(s), n, i, count = 0; dic = Dic;
	for (i = 0; i < len - 1; ++i) {
		n = s[i] - 'a';
		dic = dic->next[n];
		if (dic->a > 1) { count = i + 1; }
	}
	output(count);
}

int main() {
    Dic = new Dictionary;
	Dic->a = 0;
	for (int i = 0; i < 26; ++i) { Dic->next[i] = NULL; }
	
	while (cin>>s) {
	    que.push(s);
		insert();
	}

	while (!que.empty()) {
	    memcpy(s, que.front().c_str(), sizeof(s));
		que.pop();
		search();
	}

	return 0;
}
