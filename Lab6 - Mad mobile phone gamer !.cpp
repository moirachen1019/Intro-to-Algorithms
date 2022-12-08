#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
#define int long long
#define maxx 1000000000000000000

struct edge {
	int node;
	int weight;
};

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector < vector<edge> > edges(n);
	vector < vector<int> > record;
	for (int i = 0; i < n; i++) {
		vector<int> temp(n, -1);
		record.push_back(temp);
	}
	
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		if (a != b) {
			struct edge temp;
			temp.node = b;
			temp.weight = w;
			edges[a].push_back(temp);
		}
	}

	for (int i = 0; i < n; i++) { //分別以不同node當起點
		vector<int> node(n, maxx); //一開始設很大
		vector<int> visit(n, 0); //有沒有尋訪過
		//第一次
		node[i] = 0;
		visit[i] = 1;
		for (int j = 0; j < edges[i].size(); j++) {
			if (edges[i][j].weight + node[i] < node[ edges[i][j].node ]) {
				node[ edges[i][j].node ] = edges[i][j].weight + node[i];
			}
		}
		//之後
		for (int k = 1; k < n; k++) { //要做完n-1個node
			int min = maxx;
			int target = -1;
			for (int r = 0; r < n; r++) { //找最小
				if (node[r] <= min && visit[r] == 0) {
					min = node[r];
					target = r;
				}
			}
			visit[target] = 1;
			for (int j = 0; j < edges[target].size(); j++) {
				if (edges[target][j].weight + node[target] < node[ edges[target][j].node ]) {
					node[ edges[target][j].node ] = edges[target][j].weight + node[target];
				}
			}
		}
		//紀錄
		for (int j = 0; j < n; j++) {
			record[i][j] = node[j];
		}
	}
	
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int s, t;
		cin >> s >> t;
		if (record[s][t] != maxx) {
			cout << record[s][t] << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
}