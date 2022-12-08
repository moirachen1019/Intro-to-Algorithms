//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//signed main() {
//    cin.tie(0);
//    cin.sync_with_stdio(0);
//    vector <int> s;
//    s.clear();
//    s.resize(0);
//    int n; //義大利麵的麵條數
//    int k; //最多可以被切幾次（次數要小於）
//    int q; //q種不同限制條件
//    cin >> n >> k;
//    int number;
//    for (int i = 0; i < n; i++) {
//        cin >> number;
//        s.push_back(number);
//    }
//    sort(s.begin(), s.end());
//
//    cin >> q;
//    vector <pair<int, int>> unit_maxl;
//    unit_maxl.resize(0);
//    int unit, maxl;
//    for (int i = 0; i < q; i++) {
//        cin >> unit >> maxl;
//        unit_maxl.push_back({ unit,maxl });
//    }
//
//    vector <int> ::iterator l_bound, u_bound;
//    for (int i = 0; i < q; i++) {
//        int count = 0;
//        int limit;
//        for (int j = 1; j < k; j++) {
//            limit = ( unit_maxl[i].first * (j + 1) - 1 < unit_maxl[i].second ) ? unit_maxl[i].first * (j + 1) - 1 : unit_maxl[i].second;
//            l_bound = lower_bound(s.begin(), s.end(), unit_maxl[i].first * j);
//            u_bound = upper_bound(s.begin(), s.end(), limit);
//            if (u_bound - l_bound >= 0) {
//                count = count + (u_bound - l_bound) * j;
//            }
//        }
//
//        limit = unit_maxl[i].first * k < unit_maxl[i].second ? unit_maxl[i].first * k : unit_maxl[i].second;
//        l_bound = lower_bound(s.begin(), s.end(), unit_maxl[i].first * k);
//        u_bound = upper_bound(s.begin(), s.end(), limit);
//        if (u_bound - l_bound >= 0) {
//            count = count + (u_bound - l_bound) * k;
//        }
//        cout << count << "\n";
//    }
//}



#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
#define int long long 

signed main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n; //義大利麵的麵條數
	int k; //最多可以被切幾次（次數要小於）
	int q; //q種不同限制條件
	int ans;
	int x; //unit
	int l; //max length
	int limit;
	int count;
	cin >> n >> k;
	multiset<int> s; //麵條長度們，會自動排列
	for (int i = 0; i < n; i++) { 
		int number;
		cin >> number;
		s.insert(number);
	}

	cin >> q;
	for (int i = 0; i < q; i++) { //q種不同限制條件
		ans = 0;
		cin >> x >> l;
		for (int j = 1; j < k; j++) {
			auto l_iter = lower_bound(s.begin(), s.end(), j * x);
			auto u_iter = lower_bound(s.begin(), s.end(), (j + 1) * x);
			--u_iter;
			int count = (distance(l_iter, u_iter)) + 1;
			cout << j << " " << count << "\n";
			ans += count * j;
		}
		cout <<"ans: " << ans << '\n';
	}
}