#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define int long long
#define maxx 1000000000000000000

struct edge {
	int ss;
	int tt;
	int weight;
	bool operator<(const edge& y) const{
		return  weight < y.weight;
	}
};

int n, m, k;
vector<int> node;
vector<edge> edges;

int bellman_ford(vector<edge> edges) {
	int flag = 0;
	node[0] = 0;
	for (int i = 1; i < n; i++) {
		node[i] = maxx;
	}
	for (int i = 0; i < n; i++) {
		flag = 0;
		auto iter = edges.begin();
		while (iter != edges.end()) {
			if (node[iter->tt] > node[iter->ss] + iter->weight) {
				node[iter->tt] = node[iter->ss] + iter->weight;
				flag = 1;
			}
			iter++;
		}
		if (flag == 0) {
			return flag;
		}
	}
	return flag;
}

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	node.resize(n);
	edges.resize(m);
	for (int i = 0; i < m; i++) {
		int s, t, w;
		cin >> s >> t >> w;
		edge temp;
		temp.ss = s;
		temp.tt = t;
		temp.weight = w;
		edges[i]=temp;
	}
	sort(edges.begin(), edges.end());
	int goahead_test = bellman_ford(edges);
	if (goahead_test == 0) {
		cout << "GO AHEAD";
	}
	else { //有至少一個負環的情況
		int s, t, middle;
		s = 0;
		t = edges.size() - 1;
		middle = (s + t) / 2;
		vector<edge> v;
		v.assign(edges.begin() + middle, edges.end());
		int test = 0;
		while (true) {
			test = bellman_ford(v);
			if (test == 0) { //沒有負環，edge可以更小
				t = middle - 1;
				middle = (s + t) / 2;
				v.assign(edges.begin() + middle, edges.end());
			}
			else if (test == 1) { //有負環，edge要更大或已經找到答案
				if (s + 1 == t) {
					v.assign(edges.begin() + t, edges.end());
					test = bellman_ford(v);
					if (test == 1) { //真正的邊界
						middle = t;
						break;
					}
					else {
						middle = s;
						break;
					}
				}
				if (s == t) {
					break;
				}
				s = middle;
				middle = (s + t) / 2;
				v.assign(edges.begin() + middle, edges.end());
			}
		}
		int max_negative = -maxx;
		for (int i = 0; i < edges.size(); i++) {
			if (edges[i].weight > max_negative && edges[i].weight < 0) {
				max_negative = edges[i].weight;
			}
		}
		if (edges[middle].weight == max_negative ) {
			cout << "NO WAY BACK";
		}
		else {
			cout << edges[middle].weight;
		}
	}
}