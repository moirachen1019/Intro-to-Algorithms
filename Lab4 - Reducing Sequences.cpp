#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define int long long
vector<int> v;

int sum(int l, int r) {
	int sum = 0;
	for (int i = l; i <= r; i++) {
		sum += v[i];
	}
	return sum;
}

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	int num;
	cin >> n;
	v.resize(n);
	vector<vector<int> > record;
	for (int i = 0; i < n; i++){
		cin >> num;
		v[i] = num;
	}
	for (int i = 0; i < n; i++){
		vector<int>temp;
		for (int j = 0; j < n; j++){
			temp.push_back(-1000000000000000000);
		}
		record.push_back(temp);
	} 
	for (int len = 1; len <= n; (len = len + 2)) {  // 枚舉所有"奇數"區間長度
		for (int l = 0; (l + len - 1) <= (n - 1); l++) {  // 枚舉左端點，邊界為右端點小於等於n
			int r = (l + len - 1);  // 根據長度算出右端點
			if (len == 1) { // 區間長度為1時，為入口（l 和 r 相同）
				record[l][r] = 0;
			}
			else if (len == 3) {
				record[l][r] = v[l] * v[r] - v[l + 1];
			}
			else {   // 區間長度不是 1 跟 3 時，表示這段區間需要更新
				for (int first = l; first <= r - 2; (first = first + 2)) {  // 枚舉兩個分割點 待確認結尾
					for (int second = l + 1; second <= r - 1; (second = second + 2)) {
						record[l][r] = max(record[l][r], record[l][first] + record[first + 1][second] + (record[second + 1][r] + sum(l, first) * sum(second + 1, r) - sum(first + 1, second))); //reward + 這三個產生的reward
					}
				}
			}
		}

	}
	cout << record[0][n - 1];
}