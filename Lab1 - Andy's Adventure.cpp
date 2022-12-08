#include <iostream>
#include<map>
using namespace std;

int main()
{
	int n, t;
	int count = 0;
	cin >> n >> t;
	map<int, int> number;
	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		if ( !number.count(weight) ) {
			number[weight] = 0;
		}
		number[weight] = number[weight] + 1;
	}
	auto iter = number.begin();
	auto iter2 = number.begin();
	while (iter != number.end()) {
		int sum;
		sum = iter->first;
		if (iter->second == 2) { //同個數字有2個
			if (number.count(t - sum*2) && ( (t - sum*2) > (iter->first) ) ) {
				count++;
			}
		}
		else if(iter->second >= 3){ //同個數字有3個或以上
			if (t == sum*3) {
				count++;
			}
		}
		++iter;
		iter2 = iter;
		while (iter2 != number.end()) {
			if ( (iter2->second) >= 2) { //同個數字有2個或以上
				if (t == sum + (iter2->first) * 2) {
					count++;
				}
			}
			sum = sum + iter2->first;
			if (number.count(t - sum) && ( (t-sum) > (iter2->first) ) ) {
				count++;
			}
			sum = sum - iter2->first;
			++iter2;
		}
	}

	if (count == 0) {
		cout << "FeiDooDoo_Zuo_Wei_Men";
	}
	else {
		cout << count;
	}
}
