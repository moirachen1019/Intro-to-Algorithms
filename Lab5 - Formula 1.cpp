#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
#define int long long
#define mod 1000000007

vector<int> boss;

int find(int x) {
	if (x == boss[x]) {
		return x;
	}
	else {
		boss[x] = find(boss[x]);
		return boss[x];
	}
}

bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	return a.first < b.first;
}

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	boss.resize(n + 1);
	vector< pair<int, pair<int, int> > > edge; // w , (node1,node2)
	map< pair<int, int>, int > weight; // (node小,node大) , w

	for (int i = 0; i < m; i++) {
		int node1, node2, w;
		cin >> node1 >> node2 >> w;
		edge.push_back(make_pair(w, make_pair(node1, node2)));
	}
	sort(edge.begin(), edge.end(), compare);

	for (int i = 0; i <= n; i++) {
		boss[i] = i;
	}

	int cost = 0;
	vector < set <int> > graph(n + 1);
	auto iter = edge.begin();
	int newm = 0;
	int flag = 1;
	while (iter != edge.end()) {
		if (find((iter->second).first) != find((iter->second).second)) {
			int node1, node2;
			node1 = find((iter->second).first);
			node2 = find((iter->second).second);
			boss[node1] = node2;
			cost = (cost + iter->first) % mod;
			graph[(iter->second).first].insert((iter->second).second);
			graph[(iter->second).second].insert((iter->second).first);
			weight[make_pair(min((iter->second).first, (iter->second).second), max((iter->second).first, (iter->second).second))] = iter->first;
			newm++;
		}
		if (newm == n - 1) {
			break; //提早結束迴圈
		}
		iter++;
	}
	if (newm != n - 1) {
		flag = 0;
	}

	if (flag == 0) {
		cout << -1;
	}
	else {
		cost = (cost * 2) % mod;
		cout << cost << " ";
		vector<int> record(n + 1, 1);
		int count = 0;
		int ans = 0;
		while (count < newm) {
			for (int i = 1; i <= n; i++) {
				if (graph[i].size() == 1) {
					count++;
					int w = weight[make_pair(min(*graph[i].begin(), i), max(*graph[i].begin(), i))];
					record[*graph[i].begin()] += record[i];
					ans = (ans + (((w * (n - record[i]) % mod) * record[i] % mod) * 2) % mod) % mod;
					graph[*graph[i].begin()].erase(i); //清掉另一個對應的pair
					graph[i].erase(*graph[i].begin()); //清掉
				}
				if (count == newm) {
					break;
				}
			}
		}
		ans = ans % mod;
		cout << ans;
	}
}