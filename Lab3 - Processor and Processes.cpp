#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;
#define int long long

signed main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n, c, q;
	cin >> n >> c >> q;

	vector<int> qorder(q); //task順序
	vector< vector<int> > check; //以process來分
	set<int> core; //紀錄core裡面有誰
	set<pair<int, int>> st; //index,process
	int ans = 0;

	for (int i = 0; i < n; i++) { //先建出n個空queue，每個queue代表一個process
		vector<int> deq;
		check.push_back(deq);
	}
	int k;
	for (int i = 0; i < q; i++) { //把qorder跟check資料都存好
		cin >> k;
		qorder[i] = k - 1;
		check[k - 1].push_back(i);
	}
	auto iter = check[qorder[0]].begin();
	check[qorder[0]].erase(iter); //第一次初始化
	if (check[qorder[0]].empty()) {
		check[qorder[0]].push_back(q);
	}
	pair<int, int> temp;
	temp.first = check[qorder[0]].front();
	temp.second = qorder[0];
	st.insert(temp);
	core.insert(qorder[0]);
	ans++;

	for (int i = 1; i < q; i++) { //每個task都跑過
		if ((core.size() < c) && (core.count(qorder[i]) == 0)) { //還沒有滿且沒重複
			ans++;
			core.insert(qorder[i]);
		}
		else if (core.count(qorder[i]) == 0) {
			ans++;
			int biggest = (*st.rbegin()).second;
			core.erase(biggest);
			core.insert(qorder[i]);
			st.erase(*st.rbegin());
		}
		auto iterr = check[qorder[i]].begin();
		check[qorder[i]].erase(iterr);
		if (check[qorder[i]].empty()) {
			check[qorder[i]].push_back(q);
		}
		pair<int, int> temp;
		temp.first = check[qorder[i]].front();
		temp.second = qorder[i];
		st.insert(temp);
	}
	cout << ans;
}