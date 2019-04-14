#include<iostream>
using namespace std;

long long Find[255][255];

void Search() {
	for (int num = 0; num < 250; num++) {
		for (int k = 0; k < 250; k++) {
			if (num == 0) {
				Find[num][k] = 1; //对半开
			}
			else if (k > num) {
				Find[num][k] = 0; //不会有的
			}
			else {
				Find[num][k] = 1;  //随便置一个先
			}
		}
	}

	for (int num = 2; num < 250; num++){
		for (int k = num / 2; k >= 1; k--){
			Find[num][k] = Find[num - 2 * k][k] + Find[num][k + 1];
		}
	}
}

int main(){
	int n; Search();
	while (cin >> n && n != 0) { cout << n << " " << Find[n][1] << endl; }
	return 0;
}
