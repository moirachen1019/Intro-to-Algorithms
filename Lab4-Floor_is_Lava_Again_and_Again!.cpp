#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

struct node {
	int num;
	bool flag = false;
};

vector<node> fur;
int n, t; //家俱數 , round數

int process(int cur) {
	if (fur[cur].flag == true || (cur > (t - 1) * n)) {
		return fur[cur].num;
	}
	else {
		int maxx;
		if (n == 1) {
			maxx = fur[cur].num + process(cur + n);
		}
		else if (cur % n == 1) { //左端點
			maxx = max((fur[cur].num + process(cur + n)), (fur[cur].num + process(cur + n + 1)));
		}
		else if (cur % n == 0) { //右端點
			maxx = max((fur[cur].num + process(cur + n)), (fur[cur].num + process(cur + n - 1)));
		}
		else { //其他，可左右移動
			maxx = max((fur[cur].num + process(cur + n)), (fur[cur].num + process(cur + n + 1)));
			maxx = max(maxx, (fur[cur].num + process(cur + n - 1)));
		}
		fur[cur].num = maxx;
		fur[cur].flag = true;
		return fur[cur].num;
	}
}

signed main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> t;
	fur.resize(n * t + 1);
	fur[0].num = -1;
	int value;
	for (int i = 1; i <= (t * n); i++) {
		cin >> value;
		fur[i].num = value;
	}
	int ans;
	for (int i = 1; i <= n; i++) { //不同起始點
		ans = process(i);
		cout << ans << ' ';
	}
}