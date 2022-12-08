#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <iomanip>

using std::cout; using std::endl;
using std::vector; using std::copy;
using std::setw;


using namespace std;

#define int long long


int EvaluateMedian(vector<int>a)
{

	vector<int>::iterator iter = a.begin();
	if (a.size() % 2 != 0) {
		nth_element(iter, iter + (a.size() / 2), iter + a.size());
		return *(iter + (a.size() / 2));
	}
	else {
		nth_element(iter, iter + (a.size() / 2), iter + a.size());
		//nth_element(iter, iter + (a.size() / 2 - 1), iter + a.size());
		return *(iter + a.size() / 2);
	}
}



int isgood(vector<int>seq) {
	if (seq.size() <= 2) return 0;

	int pivot;
	int min = 0;
	if (seq.size() % 2 == 0) {
		pivot = seq.size() / 2; //右邊第一個
	}
	else {
		pivot = seq.size() / 2 + 1;
	}
	vector<int>left(seq.begin(), seq.begin() + pivot);
	/*for (int i = 0; i < left.size(); i++) {
		cout << left[i]<<" ";
	}
	cout << endl;*/
	vector<int>right(seq.begin() + pivot, seq.end());

	int leftnumber = 0;
	int leftmedian = EvaluateMedian(left);
	//cout << leftmedian;
	for (int i = 0; i < left.size(); i++) {
		leftnumber = leftnumber + abs(leftmedian - left[i]);
	}
	//if (right.size() <= 2) return leftnumber;
	leftnumber = leftnumber + isgood(right);

	int rightnumber = 0;
	int rightmedian = EvaluateMedian(right);
	for (int i = 0; i < right.size(); i++) {
		rightnumber = rightnumber + abs(rightmedian - right[i]);
	}
	//if (left.size() <= 2) return rightnumber;
	rightnumber = rightnumber + isgood(left);

	if (leftnumber >= rightnumber) {
		min = rightnumber;
	}
	else {
		min = leftnumber;
	}
	return min;



}



signed main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int>seq;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		seq.push_back(a);
	}

	int ans = isgood(seq);
	cout << ans << endl;

}