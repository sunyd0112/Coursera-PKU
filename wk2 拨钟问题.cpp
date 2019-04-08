#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int clock1[10], moveclock1[10], moveclock11[10], minimum = 28; vector<int> v;

void guess(int i, int j, int k) {
	int step = 0;
	moveclock1[1] = i; moveclock1[2] = j; moveclock1[3] = k;
	moveclock1[4] = (4 - (clock1[1] + moveclock1[1] + moveclock1[2]) % 4) % 4;//看超了4多少 然后就可以确定
	moveclock1[5] = (4 - (clock1[2] + moveclock1[1] + moveclock1[2] + moveclock1[3]) % 4) % 4;
	moveclock1[6] = (4 - (clock1[3] + moveclock1[2] + moveclock1[3]) % 4) % 4;   
	moveclock1[7] = (4 - (clock1[4] + moveclock1[1] + moveclock1[4] + moveclock1[5]) % 4) % 4; 
	moveclock1[8] = (4 - (clock1[7] + moveclock1[4] + moveclock1[7]) % 4) % 4;
	moveclock1[9] = (4 - (clock1[5] + moveclock1[1] + moveclock1[3] + moveclock1[5] + moveclock1[7]) % 4) % 4;
	if ((clock1[6] + moveclock1[6] + moveclock1[5] + moveclock1[3] + moveclock1[9]) % 4 == 0 && (clock1[8] + moveclock1[8] + moveclock1[5] + moveclock1[7] + moveclock1[9]) % 4 == 0 && (clock1[9] + moveclock1[8] + moveclock1[9] + moveclock1[6]) % 4 == 0) {
		for (int ii = 0; ii < 9; ++ii) { step += moveclock1[ii]; }
		if (step < minimum) { minimum = step; memcpy(moveclock11, moveclock1, sizeof(int) * 10); }
	}
	return;
}

void enumerate() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++){
			for (unsigned int k = 0; k < 4; k++){
				guess(i, j, k);
			}
		}
	}
}

int main(){
	int s;
	for (s = 1; s <= 9; ++s) { cin >> clock1[s]; }
	enumerate();
	for (int i = 1; i < 10; ++i) {
		while (moveclock11[i] != 0) { v.push_back(i); --moveclock11[i];}
	}
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) { cout << *i << " " ; }
	return 0;
}