#include <iostream>
#include <set>
#include <algorithm>
#include <iomanip>
#define float double
using namespace std;

signed main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	float number;
	int flag = 1;
	float q1 = 0, q3 = 0;
	float temp = 0;
	float temp2 = 0;
	float ans;

	multiset<float> s;
	cin >> number; //整體初始化
	s.insert(number);
	auto iter_left = s.begin();
	auto iter_right = s.begin();
	cout << 0 << '\n';
	if (number == 0) {
		flag = 0;
	}
	else {
		cin >> number;
	}

	if (number != 0 && flag) {
		s.insert(number);
		if (number >= *iter_right) {
			iter_right++;
		}
		else {
			iter_left--;
		}
		q3 = *iter_right;
		q1 = *iter_left;
		ans = q3 - q1;
		if (int(ans) == ans) {
			cout << int(ans) << '\n';
		}
		else {
			cout << fixed << setprecision(1) << ans << '\n';
		}		cin >> number;
	}
	else if (number == 0 && flag) {
		flag = 0;
	}

	while (number != 0 && flag) {
		s.insert(number);
		if (s.size() % 4 == 0) { //整體偶數、前半後半偶數
			if (number < *iter_left) {
				iter_right--;
			}
			else if (number >= *iter_left && number < *iter_right) {
				iter_right--;
				iter_left++;
			}
			else {
				iter_left++;
			}
		}
		else {
			if (number < *iter_left) {
				iter_left--;
			}
			else if (number >= *iter_right) {
				iter_right++;
			}
		}

		if (((s.size() % 4) == 3) || ((s.size() % 4) == 2)) { //前半後半奇數
			q3 = *iter_right;
			q1 = *iter_left;
		}
		else { //前半後半偶數
			iter_right++;
			auto iter_right2 = iter_right;
			iter_right--;

			iter_left--;
			auto iter_left2 = iter_left;
			iter_left++;
			q3 = (*iter_right + *iter_right2) / 2.0;
			q1 = (*iter_left + *iter_left2) / 2.0;
		}
		//cout << "q3: " << q3 << " q1: " << q1 << " ans: ";
		ans = q3 - q1;
		if (int(ans) == ans) {
			cout << int(ans) << '\n';
		}
		else {
			cout << fixed << setprecision(1) << ans << '\n';
		}
		cin >> number;
	}
}