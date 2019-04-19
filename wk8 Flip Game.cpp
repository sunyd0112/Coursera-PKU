#include <cstdio>
#include <queue>
using namespace std;

const int size11 = 4;
const int dir_num = 4;

struct info {
	int value;  // ״ֵ̬ 
	int step;   // ����
};
int dir[dir_num][2] = {
		{-1, 0}, {0, 1},
		{1, 0}, {0, -1},
};
int pos[size11 * size11]; // 16 �ַ�ת״̬
bool vis[1 << (size11 * size11)];   //���ĳ״̬�Ƿ��ѳ��ֹ�

// �ж�ĳ��λ���Ƿ���������
bool Judge(int x, int y) {
	if (x >= 0 && x < size11
		&& y >= 0 && y < size11)
		return true;
	else return false;
}

// Ԥ���� 16 �ַ�ת״̬
void Initialize() {
	for (int i = 0; i < size11; ++i) {
		for (int j = 0; j < size11; ++j) {
			// i*size11 + j �����
			int value = 1 << (i * size11 + j);
			for (int k = 0; k < dir_num; ++k) {
				int next_x = i + dir[k][0];
				int next_y = j + dir[k][1];
				if (Judge(next_x, next_y))
					// ���� 1<<(���) ���ɽ���λ������Ϊ1
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
		// ����ȫ�� (0) ��ȫ�� (2^16-1) ʱ���������ز���
		if (f.value == 0 || f.value == (1 << (size11 * size11)) - 1)
			return f.step;
		// ����ȫ�� 16 ��λ��
		for (int i = 0; i < size11 * size11; ++i) {
			// ͨ���������õ���ת���״̬
			info next = { f.value ^ pos[i], f.step + 1 };
			if (!vis[next.value]) {
				q.push(next);
				vis[next.value] = true;
			}
		}
	}

	return -1;  // �޷�����Ŀ��״̬������ -1
}

int main(int argc, char const* argv[]) {
	Initialize();
	char str[5];
	int value = 0;
	for (int i = 0; i < size11; ++i) {
		scanf("%s", str);
		// ������ʼ״̬��ֵ
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