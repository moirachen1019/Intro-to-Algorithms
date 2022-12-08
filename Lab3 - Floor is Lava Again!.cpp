#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
#define int long long

signed main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n, k;
	double cc, pp;
	double ccpp;
	double ans = 0;
	multiset<pair<double, int>> cp; //cp值,index
	cin >> n >> k;
	vector<double> c(n);
	vector<pair<double, double>> p(n); //index,<p值,人數>
	for (int i = 0; i < n; i++) {
		cin >> cc >> pp;
		++pp; //先加一個初始的人
		c[i] = cc;
		pair<double, double> temp;
		temp.first = pp;
		temp.second = 1;
		p[i] = temp; //存進p的map內
		ccpp = cc / pp;
		pair<double, int> temp2;
		temp.first = ccpp;
		temp.second = i;
		cp.insert(temp); //insert cp值，i是為了之後尋找方便
	}
	int target;
	for (int i = 0; i < k; i++) {
		ans += (*cp.rbegin()).first;
		target = (*cp.rbegin()).second; //找出index
		auto iter = cp.end();
		--iter;
		cp.erase(iter); //除掉已經算過的最大
		ccpp = c[target] * ((p[target].first - p[target].second) / ((p[target].first + 1) * (p[target].first)));
		++(p[target].second); //人數+1
		++(p[target].first);
		pair<double, int> temp;
		temp.first = ccpp;
		temp.second = target;
		cp.insert(temp);
	}
	cout << fixed << setprecision(6) << ans;
}