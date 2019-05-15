#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int Partition(int l, int r) {
	int temp = vec[r];
	while (l != r) {
		while (vec[l] <= temp && r > l)
			++l;
		if (l < r) { vec[r] = vec[l]; --r; }

		while (vec[r] >= temp && r > l)
			--r;
		if (l < r) { vec[l] = vec[r]; ++l; }
	}
	vec[l] = temp;
	return l;
}

void QuickSort(int l, int r) {
	if (r <= l) { return; }
	int pivot = (l + r) / 2;
	swap(vec[pivot], vec[r]);
	pivot = Partition(l, r);
	QuickSort(l, pivot - 1);
	QuickSort(pivot + 1, r);
}

int main() {
	int n, k, num, n1, n2;
	cin >> n >> k;

	n1 = n;
	for (int i = 0; i <= n / 100000; ++i) {
		n2 = n1 > 100000 ? 100000 : n1;
		for (int j = 0; j < n2; ++j) {
			cin >> num;
			vec.push_back(num);
		}
		QuickSort(0, (int)vec.size() - 1);
		vec.erase(vec.begin() + k, vec.end());
		n1 -= n2;

		if (n1 <= 0) {
			cout << vec[k - 1];
			return 0;
		}
	}
}