#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define int long long

//map<int, int> table; //錢錢 , 最少用幾個coins
vector<int> table(100001, 0);
vector<int> value;
int total;

int process(int total) { //金額數, 從哪開始切
	if (table[total] != 0 || total == 0 ) { //這個金額存在
		return table[total];
	}
	else {
		int min = pow(10, 5) + 1;
		for (int i = 0; i < value.size(); i++) {
			if (total >= value[i]) {
				int temp = process(total - value[i]);
				if ((1 + temp) < min) { //rod cutting 的概念，一次只取一個某特定幣值
					min = 1 + temp;
				}
			}
		}
		table[total] = min;
		return min;
	}
}

signed main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	value.resize(n);
	for (int i = 0; i < n; i++) { //幣值
		int v;
		cin >> v;
		value[i] = v;
	}
	int count;
	int q;
	cin >> q;
	for (int j = 0; j < q; j++) { //幾個室友跑幾次
		cin >> total; //每個室友個別要付的錢
		for (int i = 0; i < n; i++) { //每個室友支付的幣值
			cin >> count;
			if (count != 0) {
				total -= count * value[i];
			}
		}
		total = -total;
;		int ans = 0;
		if (total != 0 || total!= -0) {
			ans = process(total);
			cout << ans << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}
}