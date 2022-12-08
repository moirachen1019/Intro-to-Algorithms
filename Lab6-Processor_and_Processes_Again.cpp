#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define int long long

struct edge {
	int node;
	int weight;
};

int n, m;
vector < vector<edge> > c_edges;

int BFS(int s, int t, vector<int>& path, vector<int>& flow) {
	queue<int> q;   // BFS queue
	vector<int> visit(n + 2, 0);
	flow[s] = 1000000000000000000;
	q.push(s);
	visit[s] = 1;
	path[s] = s;
	while (!q.empty()) {
		int top = q.front();
		//cout <<"top " << top << " " << endl;
		for (int i = 0; i < c_edges[top].size(); i++) {	// 一邊找最短路徑，一邊計算流量瓶頸。
			if (c_edges[top][i].weight > 0 && visit[c_edges[top][i].node] == 0) {
				visit[c_edges[top][i].node] = 1;
				path[c_edges[top][i].node] = top;
				flow[c_edges[top][i].node] = min(flow[top], c_edges[top][i].weight);
				//cout <<"flow " << flow[c_edges[top][i].node];
				q.push(c_edges[top][i].node);
				if (c_edges[top][i].node == t) {
					return flow[t];
				}
			}
		}
		q.pop();
	}
	return 0; // 找不到擴充路徑了，流量為零。
}

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n;
	c_edges.resize(n + 2);

	//建立capacity graph，之後會變成residual
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		struct edge temp;
		temp.node = i;
		temp.weight = a;
		c_edges[0].push_back(temp);
		temp.node = 0;
		temp.weight = 0;
		c_edges[i].push_back(temp);
	}
	for (int i = 1; i <= n; i++) {
		int b;
		cin >> b;
		struct edge temp;
		temp.node = n + 1;
		temp.weight = b;
		c_edges[i].push_back(temp);
		temp.node = i;
		temp.weight = 0;
		c_edges[n + 1].push_back(temp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		struct edge temp;
		temp.node = a;
		temp.weight = w;
		c_edges[b].push_back(temp);
		temp.node = b;
		temp.weight = w;
		c_edges[a].push_back(temp);

	}
	//capacity graph完成

	while (true) {
		vector<int> path;
		vector<int> flow;
		path.resize(n + 2);
		flow.resize(n + 2);
		int temp_min = BFS(0, n + 1, path, flow);
		//cout << endl << "tempmax " << temp_max << endl;
		if (temp_min == 0) { //沒有擴充路徑了，結束
			break;
		}
		int tt = n + 1;
		int ss = path[n + 1];
		while (ss != tt) {
			//cout << ss << " " << tt;
			for (int i = 0; i < c_edges[ss].size(); i++) {
				if (c_edges[ss][i].node == tt) {
					c_edges[ss][i].weight -= temp_min;
				}
			}
			for (int i = 0; i < c_edges[tt].size(); i++) {
				if (c_edges[tt][i].node == ss) {
					c_edges[tt][i].weight += temp_min;
				}
			}
			tt = ss;
			ss = path[ss];
		}
	}

	//算答案，用residual的反向看
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += c_edges[n + 1][i].weight;
	}
	cout << ans;
}