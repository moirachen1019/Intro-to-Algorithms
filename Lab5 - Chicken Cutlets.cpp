#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
using namespace std;
#define int long long

vector<int> visit;
vector<int> scc;
vector<int> numberscc;
vector<int> table;
vector<int> finish;
int endcount = 0;
int scccount = 0;
int ans = 0;
int visit1 = 0;
int visit2 = 0;


void dfs(int index, vector<vector<int>> graph) {
	visit[index] = 1;
	visit1++;
	for (int i = 0; i < graph[index].size(); i++) {
		if (visit[graph[index][i]] == 0) {
			dfs(graph[index][i], graph);
			finish[endcount] = graph[index][i];
			endcount++;
		}
	}
	return;
}

void simpledfs(int index, vector<vector<int>> graph, int root) {
	visit[index] = 1;
	visit2++;
	for (int i = 0; i < graph[index].size(); i++) {
		if (visit[graph[index][i]] == 0) {
			scc[index] = root;
			numberscc[root]++;
			simpledfs(graph[index][i], graph, root);
		}
	}
	return;
}

void sccdfs(int index, vector<vector<int>> graph) {
	if (table[index] != numberscc[index]) {
		return;
	}
	int max = 0;
	for (int i = 0; i < graph[index].size(); i++) {
		sccdfs(graph[index][i], graph);
		if (table[graph[index][i]] > max) {
			max = table[graph[index][i]];
		}
	}
	table[index] += max;
	if (table[index] > ans) {
		ans = table[index];
	}
	return;
}

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	numberscc.push_back(0);
	vector<vector<int>> graph;
	vector<vector<int>> tgraph;
	vector<vector<int>> newgraph;
	vector<pair<int, int>> edge(m);
	graph.resize(n);
	tgraph.resize(n);
	newgraph.resize(n);
	finish.resize(n);
	visit.resize(n);
	scc.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		tgraph[b].push_back(a);
		edge[i] = (make_pair(a, b));
	}
	
	for (int i = 0; i < n; i++) {
		if (visit1 == n) {
			break;
		}
		if (visit[i] == 0) { //沒被visit過
			dfs(i, graph);
			finish[endcount] = i;
			endcount++;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	cout << finish[i] << " ";
	//}
	//cout << endl;

	for (int i = 0; i < n; i++) { //visit歸零
		visit[i] = 0;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (visit2 == n) {
			break;
		}
		if (visit[ finish[i] ] == 0) { //沒被visit過
			simpledfs(finish[i], tgraph, scccount);
			scccount++;
			numberscc.push_back(0);
		}
	}

	//for (int i = 0; i < n; i++) {
	//	cout << scc[i] << " ";
	//}
	//cout << endl;

	for (int i = 0; i < m; i++) {
		if (scc[edge[i].first] != scc[edge[i].second]) {
			newgraph[ scc[edge[i].first] ].push_back( scc[edge[i].second] );
		}
	}

	table.resize(numberscc.size() - 1);
	for (int i = 0; i < numberscc.size() - 1; i++) {
		table[i] = numberscc[i];
	}
	
	for (int i = 0; i < numberscc.size() - 1; i++) {
		sccdfs(i, newgraph);
	}
	cout << ans;
}