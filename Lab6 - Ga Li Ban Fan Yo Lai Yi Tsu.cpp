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

int f, n, m;
vector < vector<edge> > c_edges;

int BFS(int s, int t, vector<int>& path, vector<int>& flow) {
	queue<int> q;   // BFS queue
	vector<int> visit(f + n + n + m + 3, 0);
	flow[s] = 1000000000000000000;
	q.push(s);
	visit[s] = 1;
	path[s] = s;
	while (!q.empty()) {
		int top = q.front();
		for (int i = 0; i < c_edges[top].size(); i++) {	// 一邊找最短路徑，一邊計算流量瓶頸。
			if (c_edges[top][i].weight > 0 && visit[c_edges[top][i].node] == 0) {
				visit[c_edges[top][i].node] = 1;
				path[c_edges[top][i].node] = top;
				flow[c_edges[top][i].node] = min(flow[top], c_edges[top][i].weight);
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
	cin >> f >> n >> m; //農夫、工廠、商店

	c_edges.resize(f + n + n + m + 3);


	//建立capacity graph，之後會變成residual
	for (int i = 1; i <= f; i++) {
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
	for (int i = f + 1; i <= f + n; i++) {
		int a;
		cin >> a;
		struct edge temp;
		temp.node = i + n;
		temp.weight = a;
		c_edges[i].push_back(temp);
		temp.node = i;
		temp.weight = 0;
		c_edges[i + n].push_back(temp);
	}
	for (int i = f + n + n + 1; i <= f + n + n + m; i++) {
		int a;
		cin >> a;
		struct edge temp;
		temp.node = f + n + n + m + 1;
		temp.weight = a;
		c_edges[i].push_back(temp);
		temp.node = i;
		temp.weight = 0;
		c_edges[f + n + n + m + 1].push_back(temp);
	}
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		int flag = 1;
		for (int j = 0; j < c_edges[a].size(); j++) {
			if (c_edges[a][j].node == f + b) { //node已經存在
				c_edges[a][j].weight += w;
				flag = 0;
				break;
			}
		}
		if (flag) {
			struct edge temp;
			temp.node = f + b;
			temp.weight = w;
			c_edges[a].push_back(temp);
			temp.node = a;
			temp.weight = 0;
			c_edges[f + b].push_back(temp);
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		int flag = 1;
		for (int j = 0; j < c_edges[a + f + n].size(); j++) {
			if (c_edges[a + f + n][j].node == f + n + n + b) { //node已經存在
				c_edges[a + f + n][j].weight += w;
				flag = 0;
				break;
			}
		}
		if (flag) {
			struct edge temp;
			temp.node = f + n + n + b;
			temp.weight = w;
			c_edges[a + f + n].push_back(temp);
			temp.node = a + f + n;
			temp.weight = 0;
			c_edges[f + n + n + b].push_back(temp);
		}
	}
	int k;
	cin >> k;
	struct edge temp;
	temp.node = f + n + n + m + 2;
	temp.weight = k;
	c_edges[f + n + n + m + 1].push_back(temp);
	temp.node = f + n + n + m + 1;
	temp.weight = 0;
	c_edges[f + n + n + m + 2].push_back(temp);
	//capacity graph完成

	while (true) {
		vector<int> path;
		vector<int> flow;
		path.resize(f + n + n + m + 3);
		flow.resize(f + n + n + m + 3);
		int temp_min = BFS(0, f + n + n + m + 2, path, flow);
		if (temp_min == 0) { //沒有擴充路徑了，結束
			break;
		}
		int tt = f + n + n + m + 2;
		int ss = path[f + n + n + m + 2];
		while (ss != tt) {
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
	cout << c_edges[f + n + n + m + 2][0].weight;
}