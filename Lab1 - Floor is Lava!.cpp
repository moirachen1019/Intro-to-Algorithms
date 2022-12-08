#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> p[i];
    }
    double l = 0.0;
    double r = 1000000000.0;
    double mid;
    long long sum;
    while (fabs(r - l) > 0.000001) {
        mid = (l + r) / 2;
        sum = 0;
        for (long long int i = 0; i < n; i++) {
            long long temp = (int)(c[i] / mid) - p[i];
            if (temp <= 0)
                continue;
            sum += temp;
        }
        if (k <= sum) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << setprecision(10) << (l + r) / 2;

    return 0;
}