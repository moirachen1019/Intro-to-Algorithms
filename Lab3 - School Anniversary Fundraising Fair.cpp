#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define int long long

signed main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n, p, lt, rt;
	cin >> n >> p >> lt >> rt;
	map<int, int> section;

	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		section[l] = r;
	}

	int target = lt;
	int count = 0;

	do {
		int maxx = target;
		int temp = ( (-10 ^ 9) - 1);
		int flag = 0;
		auto iter = section.begin();
		while ( iter != section.end() && iter->first<=target ) {
			if (iter->second > target) { //有覆蓋到
				if (maxx < iter->second) {
					if (temp != ( (-10 ^ 9) - 1) ) {
						section.erase(temp);
					}
					temp = iter->first;
					maxx = iter->second;
				}
				flag = 1;
			}
			++iter;
		}
		section.erase(temp);
		if (flag) {
			count++;
		}
		else {
			count = 0;
			break;
		}
		target = maxx;
		
	} while (target < rt);
	cout << count * p;

}

