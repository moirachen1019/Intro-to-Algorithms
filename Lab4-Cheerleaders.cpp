#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define int long long

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	int num;
	vector<int> number(n);
	vector<int> listemp(n, 100000000000);
	vector<int> lispos(n);
	vector<int> ldstemp(n, 0);
	vector<int> ldspos(n);
	int liscount = 0;
	int ldscount = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		number[i] = num;
		if (i == 0) {
			listemp[liscount] = num;
			liscount++;
			lispos[i] = 1;

			ldstemp[ldscount] = -num;
			ldscount++;
			ldspos[i] = 1;
		}
		else {
			if (num > listemp[liscount - 1]) { //可以接在後面
				listemp[liscount] = num;
				liscount++;
				lispos[i] = liscount;
			}
			else { //不可接在後面
				auto iter = lower_bound(listemp.begin(), listemp.end(), num);
				int index = distance(listemp.begin(), iter);
				listemp[index] = num;
				lispos[i] = index + 1;
			}
			if (-num > ldstemp[ldscount - 1]) { //可以接在後面
				ldstemp[ldscount] = -num;
				ldscount++;
				ldspos[i] = ldscount;
			}
			else { //不可接在後面
				auto iter2 = lower_bound(ldstemp.begin(), ldstemp.end(), -num);
				int index2 = distance(ldstemp.begin(), iter2);
				ldstemp[index2] = -num;
				ldspos[i] = index2 + 1;
			}
		}
	}
	vector<int> rlistemp(n, 100000000000);
	vector<int> rlispos(n);
	vector<int> rldstemp(n, 0);
	vector<int> rldspos(n);
	int rliscount = 0;
	int rldscount = 0;
	for (int i = (n - 1); i >= 0 ; i--) {
		if (i == (n - 1)) {
			rlistemp[rliscount] = number[i];
			rliscount++;
			rlispos[i] = 1;

			rldstemp[rldscount] = -number[i];
			rldscount++;
			rldspos[i] = 1;
		}
		else {
			if (number[i] > rlistemp[rliscount - 1]) { //可以接在後面
				rlistemp[rliscount] = number[i];
				rliscount++;
				rlispos[i] = rliscount;
			}
			else { //不可接在後面
				auto iter3 = lower_bound(rlistemp.begin(), rlistemp.end(), number[i]);
				int index3 = distance(rlistemp.begin(), iter3);
				rlistemp[index3] = number[i];
				rlispos[i] = index3 + 1;
			}
			if (-number[i] > rldstemp[rldscount - 1]) { //可以接在後面
				rldstemp[rldscount] = -number[i];
				rldscount++;
				rldspos[i] = rldscount;
			}
			else { //不可接在後面
				auto iter4 = lower_bound(rldstemp.begin(), rldstemp.end(), -number[i]);
				int index4 = distance(rldstemp.begin(), iter4);
				rldstemp[index4] = -number[i];
				rldspos[i] = index4 + 1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++){
		//cout << rldspos[i] << " " << rlispos[i] << endl;
		if (ldspos[i] + rldspos[i] > max) {
			max = ldspos[i] + rldspos[i];
		}
		if (lispos[i] + rlispos[i] > max) {
			max = lispos[i] + rlispos[i];
		}

	}
	cout << max - 1;
}