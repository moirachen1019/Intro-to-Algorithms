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
	int n, m, s, y;
	cin >> n >> m >> s;
	vector<int> weight(m);
	vector<int> value(m);
	vector<int> table(s + 1, 0);
	vector<int> year(n);
	for (int i = 0; i < n; i++) {
		cin >> y;
		year[i] = y;
	}
	sort(year.begin(), year.end());
	int start, end, strength;
	int total_affect = 0;
	int total_strength = 0;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> strength;
		auto istart = lower_bound(year.begin(), year.end(), start);
		auto iend = upper_bound(year.begin(), year.end(), end);
		int count = iend - istart; //一場疫情會影響到幾個比賽
		weight[i] = strength;
		value[i] = count;
		total_affect += count;
		total_strength += strength;
	}
	if (total_strength <= s) {
		cout << n;
	}
	else {
		for (int i = 0; i < m; i++) {
			for (int j = s; j >= 0; j--) {
				if ( !(j - weight[i] < 0)) { //還在可負重範圍內
					table[j] = max(table[j], table[j - weight[i]] + value[i]); //不放v.s.放
				}
			}
		}
		cout << table[s] + (n - total_affect);
	}
}