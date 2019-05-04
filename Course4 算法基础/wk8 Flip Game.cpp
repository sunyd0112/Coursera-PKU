#include <cstdio>
#include <queue>
using namespace std;

const int size11 = 4;
const int dir_num = 4;

struct info {
	int value;  // 状态值 
	int step;   // 步数
};
int dir[dir_num][2] = {
		{-1, 0}, {0, 1},
		{1, 0}, {0, -1},
};
int pos[size11 * size11]; // 16 种翻转状态
bool vis[1 << (size11 * size11)];   //标记某状态是否已出现过

// 判断某个位置是否在棋盘内
bool Judge(int x, int y) {
	if (x >= 0 && x < size11
		&& y >= 0 && y < size11)
		return true;
	else return false;
}

// 预处理 16 种翻转状态
void Initialize() {
	for (int i = 0; i < size11; ++i) {
		for (int j = 0; j < size11; ++j) {
			// i*size11 + j 即编号
			int value = 1 << (i * size11 + j);
			for (int k = 0; k < dir_num; ++k) {
				int next_x = i + dir[k][0];
				int next_y = j + dir[k][1];
				if (Judge(next_x, next_y))
					// 加上 1<<(编号) 即可将此位置设置为1
					value += 1 << (next_x * size11 + next_y);
			}
			pos[i * size11 + j] = value;
		}
	}
}

int BFS(int value) {
	queue<info> q;
	info s = { value, 0 };
	q.push(s);
	vis[s.value] = true;
	while (!q.empty()) {
		info f = q.front();
		q.pop();
		// 盘面全黑 (0) 或全白 (2^16-1) 时结束，返回步数
		if (f.value == 0 || f.value == (1 << (size11 * size11)) - 1)
			return f.step;
		// 搜索全部 16 个位置
		for (int i = 0; i < size11 * size11; ++i) {
			// 通过异或运算得到翻转后的状态
			info next = { f.value ^ pos[i], f.step + 1 };
			if (!vis[next.value]) {
				q.push(next);
				vis[next.value] = true;
			}
		}
	}

	return -1;  // 无法到达目标状态，返回 -1
}

int main(int argc, char const* argv[]) {
	Initialize();
	char str[5];
	int value = 0;
	for (int i = 0; i < size11; ++i) {
		scanf("%s", str);
		// 计算起始状态的值
		for (int j = 0; j < size11; ++j) {
			if (str[j] == 'w')
				value += 1 << (i * size11 + j);
		}
	}
	int ans = BFS(value);
	if (ans >= 0) printf("%d\n", ans);
	else printf("Impossible\n");

	return 0;
}
