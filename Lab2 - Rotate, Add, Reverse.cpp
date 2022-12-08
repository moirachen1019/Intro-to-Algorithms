#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define int long long


signed main(){
	int n;
	cin >> n;
    vector<int> rar;
    rar.push_back(1);
    for (int i = 1; i <= n; i++) {
        int add;
        add = pow(2, i - 1);
        int size = rar.size();
        for (int j = 0; j < size; j++) {
            rar.push_back( rar[j] + add );
        }
        reverse(rar.begin(), rar.begin() + size);
        rotate(rar.begin(), rar.begin() + rar.size() - add, rar.end());
    }
    for (int i = 0; i < rar.size(); i++) {
        cout << rar[i] << " ";
    }
}
