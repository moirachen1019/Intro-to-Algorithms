#include <iostream>
#include <vector>
#define int long long
using namespace std;

int ans = 0;
int ipost = 0;
vector<int>age;
vector<int>in;
vector<int>index;
vector<int>post;

void tree(int root, int inbegin, int inend) {
    if (inbegin > inend) return;
    ipost--;
    if (ipost < 0) return;
    int end = post[ipost];
    int position = index[end];
    if (root < age[in[position]]) {
        ans++;
    }

    if (inbegin == inend) return;
    tree(age[in[position]], position + 1, inend);
    tree(age[in[position]], inbegin, position - 1);
    return;
}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        age.push_back(a);
    }

    index.resize(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        in.push_back(a - 1);
        index[a - 1] = i;
    }




    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        post.push_back(a - 1);
    }

    ipost = post.size();
    tree(10000000000, 0, n - 1);
    cout << ans << '\n';

}