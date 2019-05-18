#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

struct Dictionary{
	char Eng[15];
	Dictionary* next[26];
};

char str[15] = { '\0' }, str1[15] = { '\0' }; int n; Dictionary* Dic, *dic;


void insert() {
	int len = strlen(str1), i; dic = Dic;
	for (i = 0; i < len - 1; ++i) {
		n = str1[i] - 'a';
		if (dic->next[n] == NULL) {
			dic->next[n] = new Dictionary;
			dic = dic->next[n];
			dic->Eng[0] = '\0';
			for (int j = 0; j < 26; ++j) {
				dic->next[j] = NULL;
			}
		}
		else { dic = dic->next[n]; }
	}
	n = str1[i] - 'a';
	if (dic->next[n]==NULL) {
		dic->next[n] = new Dictionary;
		for (int j = 0; j < 26; ++j) {
			dic->next[n]->next[j] = NULL;
		}
	}
	strcpy(dic->next[n]->Eng, str);
}

void search() { 
	int len = strlen(str1), i; dic = Dic;

	for (i = 0; i < len - 1; ++i) {
		n = str1[i] - 'a';
		if (dic->next[n] == NULL) {
			printf("eh\n"); return;
		}
		else { dic = dic->next[n]; }
	}
	n = str1[i] - 'a';
	if (dic->next[n] == NULL) {
		printf("eh\n"); return;
	}
	else if (dic->next[n]->Eng[0] == '\0') {
		printf("eh\n"); return;
	}
	else 
		printf("%s\n", dic->next[n]->Eng);
}

int main() {
	Dic = new Dictionary;
	for (int j = 0; j < 26; ++j) {
		Dic->next[j] = NULL;
	}
	while (str[0] = cin.get()){
		if (str[0]== '\n') { break; }
		scanf("%s%s", str+1, str1);
		insert();
		getchar();
	}

	while (scanf("%s", str1) != EOF){ search(); }
	
	return 0;
}
