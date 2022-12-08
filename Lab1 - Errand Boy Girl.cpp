#include <iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main()
{
	long long int n, l, k;
	long long int time = 0;
	cin >> n >> l >> k;
	deque<long long int> weight;
	for (long long int i = 0; i < n; i++) {
		long long int number;
		cin >> number;
		weight.push_back(number);
	}
	sort(weight.begin(), weight.end());
	while (weight.size() >= 2) {
		if (weight.back() + weight.front() <= l) { //最大跟最小可以一起搬
			time = time + k;
			weight.pop_back();
			weight.pop_front();
		}
		else { //爆掉，只搬大的
			time = time + k;
			weight.pop_back();
		}
	}
	if (weight.size() == 1) {
		time = time + k;
	}
	cout << time*2;
}