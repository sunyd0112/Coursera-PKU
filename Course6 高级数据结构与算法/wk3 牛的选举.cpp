#include<iostream>
#include<cstring>
using namespace std;

struct vote {
	long long f, s;
	int index;
	vote(){}
} Vote[50010];

int Count[10] = { 0 }, n, k, TempVote[50010];

void RadixSort(){
	int Radix = 1, k, tempin;
	long long tempf, temps;

	for (int i = 1; i <= 10; ++i) {
		memset(Count, 0, sizeof(Count));
		for (int j = 0; j < n; ++j) {
			k = (Vote[j].f / Radix) % 10;
			++Count[k];
		}
		for (int j = 1; j < 10; ++j) { Count[j] += Count[j - 1]; }
		for (int j = n - 1; j >= 0; --j) {
			k = (Vote[j].f / Radix) % 10;
			--Count[k];
			TempVote[j] = Count[k];
		}
		for (int j = 0; j < n; ++j) {
			while (TempVote[j] != j) {
				tempf = Vote[j].f; temps = Vote[j].s; tempin = Vote[j].index;
				Vote[j].f = Vote[TempVote[j]].f; Vote[j].s = Vote[TempVote[j]].s; Vote[j].index = Vote[TempVote[j]].index;
				Vote[TempVote[j]].f = tempf; Vote[TempVote[j]].s = temps; Vote[TempVote[j]].index = tempin;
				tempin = TempVote[TempVote[j]];
				TempVote[TempVote[j]]= TempVote[j];
				TempVote[j]= tempin;
			}
		}
		Radix *= 10;
	}
}

int main() {
	cin >> n >> k; int i = 0, N = n;
	while (N--) {
		long long v1, v2;
		cin >> v1 >> v2;
		Vote[i].f = v1; Vote[i].s = v2; Vote[i].index = i + 1;
		++i;
	}

	RadixSort(); 

	long long max = 0; int maxindex;
	for (int i = n - 1; i >= n - k; --i) {
		if (Vote[i].s > max) {
			max = Vote[i].s;
			maxindex = Vote[i].index;
		}
	}
	cout << maxindex;

	return 0;
}