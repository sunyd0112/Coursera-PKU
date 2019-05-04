#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

int n = 0, sum = 0; bool flag = false;
vector<int> leftN, leftM, resultM, tempmax;

typedef multimap<int, vector<int> > Map;
Map maxsum; Map::iterator maxi;

void Dfs(int N, vector<int> putN, vector<int> putM, int lenN) { 

	if (lenN == 1) { return; } //do not search for length 1, it is added in digitsum

	vector<int>::iterator mi, ni, temp;
	ni = putN.begin(); int firstN = *ni; //get the first number of what was left of n
	int combine = 0, minusN = N; leftM.clear(); leftN.clear(); sum = 0; //initiation
	
	for (mi=putM.begin(); mi != putM.end() - 1; ++mi) { 
		if (putM.end() - mi > lenN - 1) { //search the longest length first
			if (*mi > firstN && lenN==(int)putN.size()) { continue; } //可行性剪枝1
			for (int i = 0; i < lenN; ++i) {
				if (*(mi + i) > 9) { flag = true; break; } // have combined before
				combine += *(mi + i) * (int)pow(10, lenN - i - 1); 
			}
			if (flag) { combine = 0; flag = false; continue; } //可行性剪枝2
			if (combine > N) { combine = 0; continue; } //可行性剪枝3

			if (mi != putM.begin()) {
				for (temp = putM.begin(); temp < mi; ++temp) { leftM.push_back(*temp); } //leftM to continue recursion, store the M after combination
			}
			leftM.push_back(combine);
			if (mi < putM.end() - lenN) {
				temp=mi+ lenN;
				for ( ; temp < putM.end(); ++temp) { leftM.push_back(*temp);}
			}
			for (temp = leftM.begin(); temp != leftM.end(); ++temp) { sum += *temp; }
			//compute whether the sum of this combine will exceed n or not

			if (sum > n) { sum = 0; combine = 0; leftM.clear(); continue; } //可行性剪枝4
			else if (sum <= n && sum!=0) { 
				maxi = maxsum.find(sum); bool flagmax = false;
				if (maxi != maxsum.end()) {
					tempmax = maxi->second;
					if (tempmax.size() == leftM.size()) {
						flagmax = true;
						for (vector<int>::iterator tempMax = tempmax.begin(), temp = leftM.begin(); tempMax != tempmax.end(), temp != leftM.end(); ++tempMax, ++temp) {
							if (*temp != *tempMax) { flagmax = false; break; } //not exactly the same, the flag would turn false
						} //最优化剪枝1
						if (flagmax == false){ maxsum.insert(Map::value_type(sum, leftM)); } //if totally the same, wont add again
					}
					else { maxsum.insert(Map::value_type(sum, leftM)); } //not in the same length
				}
				else { maxsum.insert(Map::value_type(sum, leftM)); } //cant find this sum, then add
				sum = 0;
			}
		
			minusN -= combine; int tempminusN = minusN;//find leftN to continue recursion
			if (tempminusN == 0) { leftN.push_back(0); }
			else {
				for (int i = (int)putN.size(); i >= 0; --i) {
					if (tempminusN >= (int)pow(10, i)) { // will not include 0
						for (int j = 1; j <= i + 1; ++j) {
							leftN.push_back(tempminusN / (int)pow(10, i + 1 - j));
							tempminusN -= tempminusN / (int)pow(10, i + 1 - j) * (int)pow(10, i + 1 - j);
						}
						break;
					}
				}
			}
			Dfs(minusN, leftN, leftM, lenN); 
			leftM.clear(); leftN.clear(); sum = 0; combine = 0; minusN = N;
		}
	}
	Dfs(N, putN, putM, lenN - 1); 
	
}

int main() {
	vector<int> putN, putM; vector<int>::iterator mi; string N, M;
	while (cin >> N >> M) {
		if (N == "0" && M  == "0") { return 0; } //EOF

		putM.clear(); putN.clear(); maxsum.clear(); int digitsum = 0; flag = false; n = 0; //initiation

		for (int i = 0; i < (int)M.length(); ++i) { putM.push_back((int)(M.at(i) - '0')); } //put numbers into vectors

		for (int i = 0; i < (int)N.length(); ++i) {
			putN.push_back((int)(N.at(i) - '0'));
			n += (int)(N.at(i) - '0') * (int)pow(10, N.length() - 1 - i); //transfer string n into int
		}

		for (mi = putM.begin(); mi != putM.end(); ++mi) { digitsum += *mi; } //find the digitsum
		if (digitsum > n) { cout << "error" << endl; } //cases can be determined outside of Dfs
		else if (N == M) { cout << N << " " << M << endl; }
		else if (n==digitsum || putN.size() == 1) { 
			for (mi = putM.begin(); mi < putM.end() - 1; ++mi) { 
				if (*mi == 0) { flag = true; break; } // if there is 0 not in the last position, then must reject
			}
			if (flag) { cout << "rejected" << endl; }
			else {
				cout << digitsum << " ";
				for (mi = putM.begin(); mi != putM.end() - 1; ++mi) { cout << *mi << " "; }
				cout << *mi << endl;
			}
		}
		else { 
			maxsum.insert(Map::value_type(digitsum, putM)); 
 			Dfs(n, putN, putM, (int)putN.size()); 
			maxi = maxsum.end(); --maxi; int result = maxi->first; 
			Map::iterator howmanymax = maxsum.lower_bound(maxi->first);
			if (howmanymax!=maxi) { cout << "rejected" << endl; }
			else {
				cout << result << " ";
				resultM = maxi->second;
				for (mi=resultM.begin();mi<resultM.end()-1;++mi){ cout << *mi << " "; }
				cout << *mi << endl;
			}
		}
	}
	return 0;
}
