#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 100000000;
struct node
{
	int lson, rson, fa;
	int v;
	char 
		s[100];
};
node tree[50010];
int cmp(node x, node y)
{
	return strcmp(x.s, y.s) < 0;    //字符串比较用这个；换成return x.s < y.s 就WA了
}
void inset_node(int now)
{
	int j = now - 1;
	while (tree[j].v < tree[now].v)
		j = tree[j].fa;
	tree[now].lson = tree[j].rson;
	tree[j].rson = now;
	tree[now].fa = j;
}
void travel(int now)
{
	if (now == 0) return;
	printf("(");
	travel(tree[now].lson);
	printf("%s/%d", tree[now].s, tree[now].v);
	travel(tree[now].rson);
	printf(")");
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		getchar();
		for (int i = 1; i <= n; i++)
		{
			scanf("%[a-z]/%d", tree[i].s, &tree[i].v);
			getchar();
			tree[i].lson = tree[i].rson = tree[i].fa = 0;
		}
		sort(tree + 1, tree + n + 1, cmp);
		tree[0].fa = tree[0].lson = tree[0].rson = 0;
		tree[0].lson = 0;
		tree[0].v = INF;
		for (int i = 1; i <= n; i++)
			inset_node(i);

		travel(tree[0].rson);
		printf("\n");
	}

	return 0;
}
