#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long

signed main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){ //整個要跑幾次

		int n;
		cin >> n;
		string ans = "Yes";
		vector<int> need;
		map<int, int> money;

		for (int j = 0; j < n; j++) { //幾個室友跑幾次，把大家的錢集中，抓出需要找錢的
			int sum, m1000, m500, m100, m50, m10, m5, m1;
			cin >> sum >> m1000 >> m500 >> m100 >> m50 >> m10 >> m5 >> m1;
			money[1000] += m1000;
			sum = sum - 1000 * m1000;
			money[500] += m500;
			sum = sum - 500 * m500;
			money[100] += m100;
			sum = sum - 100 * m100;
			money[50] += m50;
			sum = sum - 50 * m50;
			money[10] += m10;
			sum = sum - 10 * m10;
			money[5] += m5;
			sum = sum - 5 * m5;
			money[1] += m1;
			sum = sum - 1 * m1;
			if (sum != 0) {
				need.push_back(-sum);
			}
		}

		for (int r = 0; r < need.size(); r++) { //以人為單位開始找錢
			auto iter = money.end();
			--iter;
			for (int ii = 0; ii < 7; ii++) {
				if ( (iter->first) <= need[r] ) { // 幣值要小於等於要找的錢才能找
					need[r] -= (iter->first) * (iter->second);
					if (need[r] == 0) { //剛好處理掉
						money[iter->first] = 0; //這種幣值歸0
						break;
					}
					else if (need[r] > 0) { //還沒處理掉
						money[iter->first] = 0; //這種幣值歸0，繼續進入迴圈
					}
					else if (need[r] < 0) { //用的硬幣太多了
						double fneed = (double)(-need[r]);
						double ffirst = (double)(iter->first);
						double ftarget = ceil( fneed / ffirst);
						int target = (int)ftarget;
						need[r] += target*iter->first ;
						money[iter->first] = target;
						if (need[r] == 0) {
							break;
						}
					}
				}
				--iter;
			}
			if (need[r] > 0) {
				ans = "No";
				break;
			}
		}
		cout << ans << endl;

	}
}