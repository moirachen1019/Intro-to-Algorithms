#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define maxx 1000000000000000000
#define P pair<int,int>

int n, m;

priority_queue<P, vector<P>, greater<P> > node; //一開始設很大 weight, node
vector<int> nodeindex; //最後的答案

struct edge {
	int node;
	int weight;
};
struct redge {
	int first;
	int second;
	int third;
};

void dijkstra(vector< vector<edge> >& e, int flag) {
	while (!node.empty()) {
		node.pop();
	}
	for (int i = 0; i < n; i++) { //初始化
		if (i == flag) {
			node.push(make_pair(0, i));
			nodeindex[i] = 0;
		}
		else {
			node.push(make_pair(maxx, i));
			nodeindex[i] = maxx;
		}
	}
	vector<int> visit(n, 0); //有沒有尋訪過
	for (int k = 0; k < n; k++) { //要做完n個node
		int target = -1;
		while (!node.empty()) {
			target = node.top().second;
			node.pop();
			if (visit[target] == 0) { //沒被visit過
				visit[target] = 1;
				break;
			}
		}
		for (int j = 0; j < e[target].size(); j++) {
			if (e[target][j].weight + nodeindex[target] < nodeindex[e[target][j].node]) {
				nodeindex[e[target][j].node] = e[target][j].weight + nodeindex[target];
				node.push(make_pair(nodeindex[e[target][j].node], e[target][j].node));
			}
		}
	}
}

void printvector(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	vector< vector<edge> > edges;
	vector< vector<edge> > antiedges;
	vector< redge > record(m);
	edges.resize(n);
	antiedges.resize(n);
	nodeindex.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		struct edge temp;
		temp.node = b;
		temp.weight = w;
		edges[a].push_back(temp);
		temp.node = a;
		antiedges[b].push_back(temp);
		struct redge temp2;
		temp2.first = a;
		temp2.second = b;
		temp2.third = w;
		record[i] = temp2;
	}

	dijkstra(edges, 0);
	vector<int> positive;
	positive.assign(nodeindex.begin(), nodeindex.end());
	dijkstra(antiedges, n - 1);
	vector<int> negative;
	negative.assign(nodeindex.begin(), nodeindex.end());
	int shortest = positive[n - 1];
	for (int i = 0; i < m; i++) {
		int want = shortest - positive[record[i].first] - negative[record[i].second];
		if (record[i].third - want >= 0 && want >= 0) {
			cout << record[i].third - want << '\n';
		}
		else {
			cout << "-1" << '\n';
		}
	}
}