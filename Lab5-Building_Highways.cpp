#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
#define int long long

int n, m, k, f, s;

int find(int x, vector<int>& boss) {
	if (x == boss[x]) {
		return x;
	}
	else {
		boss[x] = find(boss[x], boss);
		return boss[x];
	}
}

int mst(vector<pair<int,int>>& edge, vector<int>& boss) {
	auto iter = edge.begin();
	int count = 0;
	while ((iter != edge.end()) && (count <= n - 1)) {
		int node1, node2;
		node1 = find(iter->first, boss);
		node2 = find(iter->second, boss);
		if (node1 != node2) {
			boss[node2] = node1;
			count++;
		}
		iter++;
	}
	return count;
}


signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		cin >> n >> m >> k >> f >> s;
		vector<int> fboss(n);
		vector<int> sboss(n);
		vector<int> allboss(n);
		vector< pair<int, int> >  fedge; // (node1,node2)
		vector< pair<int, int> >  sedge; // (node1,node2)
		vector< pair<int, int> >  edge; // (node1,node2)

		for (int i = 0; i < m; i++) { //edge初始化
			int a, b;
			char type;
			cin >> a >> b >> type;
			if (type == 'F') {
				fedge.push_back(make_pair(a, b));
			}
			else if (type == 'S'){
				sedge.push_back(make_pair(a, b));
			}
			edge.push_back(make_pair(a, b));
		}

		for (int i = 0; i < n; i++) { //boss初始化
			fboss[i] = i;
			sboss[i] = i;
			allboss[i] = i;
		}

		int tree = 1;
		int tt = mst(edge, allboss);
		if (tt != (n - 1)) {
			tree = 0;
		}

		int flag = 0;
		if (tree == 1) {
			int fmax = mst(fedge, fboss);
			int smin = mst(sedge, fboss);
			int smax = mst(sedge, sboss);
			int fmin = mst(fedge, sboss);
			//cout << fmax << " " << smax;
			if (fmax + smin < (n - 1) || smax + fmin < (n - 1)) {
				flag = 0;
				cout << "No" << '\n';
			}
			else {
				int test = fmax;
				while (test >= fmin) {
					if ((n - 1 - test) >= smin && (n - 1 - test) <= smax) {
						if (test * f + (n - 1 - test) * s == k) {
							flag = 1;
							cout << "Yes" << '\n';
							break;
						}
					}
					test--;
				}
			}
		}

		if (flag == 0 || tree == 0) {
			cout << "No" << '\n';
		}

	}
}