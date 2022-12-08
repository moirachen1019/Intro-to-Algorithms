
#include <iostream>
#include <cmath>

using namespace std;
#define int long long
int m = 1000000007;

signed main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int a, b, n;
    cin >> a >> b >> n;
    for (int j = 0; j < n; j++) {
        int aa = a;
        int i;
        cin >> i;
        i--;
        if (i != 0) {
            int sum = 1;
            while (i > 0){
                if (i % 2 == 1){
                    sum = (sum * aa) % m;
                    i--;
                }
                i = i / 2;
                aa = (aa * aa) % m;
            }

            int ans = (b % m * (sum % m - 1) / (a - 1) % m) % m + sum % m;

            if (ans < 0) {
                ans = ans + m;
            }
            ans = ans % m;
            cout << ans << '\n';
        }
        else {
            cout << "1" << '\n';
        }
    }
}
