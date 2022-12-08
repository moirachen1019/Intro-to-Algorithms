#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
#define int long long
vector<int> boss;

int find(int x){
	if (x == boss[x]) {
		return x;
	}
	else {
		boss[x] = find(boss[x]);
		return boss[x];
	}
}

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	boss.resize(n);

	set<pair<int, int>> edge;

	vector <vector <int> > test(q);
	for (int i = 0; i < q; i++) { //存要做的事
		test[i].resize(3);
	}

	for (int i = 0; i < n; i++) {
		boss[i] = i;
	}

	int a, b, c, d;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a > b) {
			edge.insert(make_pair(a, b));
		}
		else {
			edge.insert(make_pair(b, a));
		}
	}

	for (int i = 0; i < q; i++) {
		char type;
		cin >> type >> c >> d;
		test[i][1] = max(c, d);
		test[i][2] = min(c, d);
		if (type == 'A') {
			test[i][0] = 0;
		}
		else if (type == 'U') {
			test[i][0] = -1;
			auto iter = edge.find(make_pair(test[i][1], test[i][2]));
			edge.erase(iter);
		}
	}

	auto iterr = edge.begin();
	while (iterr != edge.end()) {
		int i, j;
		i = iterr->first;
		j = iterr->second;
		i = find(i);
		j = find(j);
		boss[i] = j;
		iterr++;
	}



	for (int i = q - 1; i >= 0; i--) {
		if (test[i][0] == -1) { //unfriend
			//cout << i << " " << test[i][1] << " " << test[i][2] << endl;
			test[i][1] = find(test[i][1]);
			test[i][2] = find(test[i][2]);
			boss[ test[i][1] ] = test[i][2];
		}
		else { //算答案
			if (find(test[i][1]) == find(test[i][2])) {
				test[i][0] = 1;
			}
		}
	}

	for (int i = 0; i < q; i++) {
		if (test[i][0] == 1) {
			cout << "YES" << '\n';
		}
		else if (test[i][0] == 0) {
			cout << "NO" << '\n';
		}
	}
}