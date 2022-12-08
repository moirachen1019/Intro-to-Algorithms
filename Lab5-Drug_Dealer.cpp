#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
#define int long long
signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int t, n, m, s;
	cin >> t;
	int a, b, c, d;
	for (int ii = 0; ii < t; ii++) {
		cin >> n >> m >> s;
		s--;
		vector <vector <int> > graph(n);
		for (int i = 0; i < m; i++) { //建graph
			cin >> a >> b;
			a--;
			b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		int p;
		cin >> p;
		vector<int> police(p);
		for (int i = 0; i < p; i++) {
			cin >> c;
			c--;
			police[i] = c;
		}

		int target;
		cin >> target;
		vector<int> tt(n, 0);
		for (int i = 0; i < target; i++) {
			cin >> d;
			d--;
			tt[d] = 1; //有1就是終點
		}
		
		queue<int> q;
		vector<int> visit(n, -1);
		for (int i = 0; i < p; i++) {
			q.push(police[i]); //把所有警察丟進去
			visit[police[i]] = 0;
		}
		q.push(-1);
		int count = 1;
		while (!q.empty()) {
			if (q.front() == -1) {
				q.pop();
				count++;
				if (q.size() != 0) {
					q.push(-1);
				}
			}
			if (q.size() != 0) {
				for (int i = 0; i < graph[q.front()].size(); i++) { //每個相鄰點都走一次
					if (visit[graph[q.front()][i]] == -1) { //沒visit過
						visit[graph[q.front()][i]] = count;
						q.push(graph[q.front()][i]);
					}
				}
				q.pop();
			}
		}
		vector<int> badvisit(n, -1);
		q.push(s);
		q.push(-1);
		badvisit[s] = 0;
		int badcount = 1;
		int flag = 0;
		while (!q.empty()) {
			if (q.front() == -1) {
				q.pop();
				badcount++;
				if (q.size() != 0) {
					q.push(-1);
				}
			}
			if (q.size() != 0) {
				for (int i = 0; i < graph[q.front()].size(); i++) { //每個相鄰點都走一次
					if (badvisit[graph[q.front()][i]] == -1) { //沒visit過
						badvisit[graph[q.front()][i]] = badcount;
						if ((tt[graph[q.front()][i]] == 1) && (badvisit[graph[q.front()][i]] < visit[graph[q.front()][i]])) { //是終點且比歹徒快
							flag = 1;
							cout << "Yes" << '\n';
							break;
						}
						else {
							q.push(graph[q.front()][i]);
						}
					}
				}
				q.pop();
			}
			if (flag == 1) {
				break;
			}
		}
		if (flag != 1) {
			cout << "No" << '\n';
		}
	}
}