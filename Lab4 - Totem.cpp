#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define int long long
#define mod 1000000007

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int t;
	cin >> t;
	int num;
	int max = 0;
	vector<int> record(t);
	for (int i = 0; i < t; i++) {
		cin >> num;
		record[i] = num;
		if (num > max) {
			max = num;
		}
	}
	vector<int> ans(max + 1, 0);
	vector<int> sum;
	sum.push_back(0);
	sum.push_back(2);
	int up = 1, down = 1;
	for (int i = 3; i <= max; i++) {
		up = (sum[i - 3] + down + 1) % mod;
		down = (sum[i - 3] + 1) % mod;
		int modd = (sum[i - 2] + up + down) % mod;
		sum.push_back(modd);
		ans[i] = (modd * 4 + 1) % mod;
	}
	for (int i = 0; i < t; i++) {
		if (record[i] == 1) {
			cout << 1 << '\n';
		}
		else if (record[i] == 2) {
			cout << 9 << '\n';
		}
		else {
			cout << ans[record[i]] << '\n';
		}
	}

}