#include <iostream>
using namespace std;

int main() {
	int caseN; cin >> caseN;
	while (caseN) {
		--caseN;
		int n; cin >> n;

		int area = n * 4 + 2; 
		for (int i = n / 2; i > 1; --i) {
			if (n % i == 0) { //除开第一层
				int j = n / i; 
				if ((i * j + i + j) * 2 < area) { area= (i * j + i + j) * 2; } //除开第二层之前先替换
				for (int k = j / 2; k > 1; --k) {
					if (j % k == 0) { //除开第二层
						int jj = j / k;
						if ((i * jj + jj * k + i * k) * 2 < area) { area= (i * jj + jj * k + i * k) * 2; }
					}
				}
			}
		}
		cout << area << endl;
	}

	return 0;                     
}