#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <bitset>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;
#define int long long

map<string, int> mp_l;

struct MinHeapNode {
    string data;
    int freq;
    MinHeapNode* left, * right;
    MinHeapNode(string data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        if (l->freq == r->freq) {
            return (l->data > r->data);
        }
        return (l->freq > r->freq);
    }
};

void countCodes(struct MinHeapNode* root, int len)
{
    if (!root) {
        return;
    }
    mp_l[root->data] = len;
    len++;
    countCodes(root->left, len);
    countCodes(root->right, len);
}

void HuffmanCodes(map<string,int> mp_f)
{
    struct MinHeapNode* left, * right, * top; //宣告一個node
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; //用priority_queue，可以自己決定排序

    auto iter = mp_f.begin();
    while (iter != mp_f.end()) {
        minHeap.push(new MinHeapNode(iter->first, iter->second));
        ++iter;
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        if (left->data < right->data) {
            top = new MinHeapNode(left->data, left->freq + right->freq);
        }
        else {
            top = new MinHeapNode(right->data, left->freq + right->freq);
        }
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    countCodes(minHeap.top(), 0);
}

signed main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    int size;
    double ans = 0.0;
    double child = 0.0;
    double mother;
    string str;
    map<string, int > mp_f; //string, f
	cin >> n;
    vector<vector<string>> data(n + 1);

    for (int i = 0; i <= n; i++) {
        getline(cin, str); //先整行讀進來
        stringstream input(str); //整行讀到input內
        string temp; 
        while (input >> temp) { //temp即為用空格切開後的單字
            if (!mp_f.empty()) {
                if (mp_f.count(temp) == 0) { //temp不在，新增temp
                    mp_f[temp] = 1;
                }
                else {
                    mp_f[temp] += 1;
                }
            }
            else {
                mp_f[temp] = 1;
            }
            data[i].push_back(temp);
        }
    }

    HuffmanCodes(mp_f); //為了取得length

    size = mp_f.size();
    mother = ceil(log(size) / log(2));
    for (int i = 1; i <= n; i++) {
        child = 0;
        for (int j = 0; j < data[i].size(); j++) {
            child += mp_l[ (data[i]).at(j) ];
        }
        ans = child / (mother * data[i].size() );
        cout << fixed << setprecision(10) << ans << "\n";
    }

    return 0;
}