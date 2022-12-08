#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>

#define int long long

using namespace std;

bool isupper(char c) {
    if ((int)c >= 65 && (int)c <= 90) return true;
    else return false;
}

bool islower(char c) {
    if ((int)c >= 97 && (int)c <= 122) return true;
    else return false;
}

bool isnumber(char c) {
    if ((int)c >= 48 && (int)c <= 57) return true;
    else return false;
}

bool isparameter(char c) {
    if ((int)c == 41) return true;
    else return false;
}

void process(stack<char>& s, map<char, int>& single, map<string, int>& doublee, int i) { //i為元素數量
    while (!s.empty()) {
        int init = i;
        char top = s.top();
        s.pop();
        if (top == '(') {
            return;
        }
        else {
            if (isnumber(top)) {
                int topnumber = ((int)top - 48);
                char top2 = s.top();
                s.pop();
                int count = 1;
                while (isnumber(top2)) { //數字不只一個
                    topnumber += ((int)top2 - 48) * pow(10, count);
                    top2 = s.top();
                    s.pop();
                    count++;
                }
                int temp = init;
                init = init * topnumber; //更新init

                if (isparameter(top2)) {
                    process(s, single, doublee, init);
                    i = temp;
                }
                else if (isupper(top2)) {
                    if (!single.empty()) {
                        if (!single.count(top2)) { //不存在
                            single[top2] = init;
                        }
                        else {
                            single[top2] += init;
                        }
                    }
                    else {
                        single[top2] = init;
                    }
                }
                else if (islower(top2)) {
                    char top3 = s.top();
                    s.pop();
                    string newstr;
                    newstr.push_back(top3);
                    newstr.push_back(top2);
                    if (!doublee.empty()) {
                        if (!doublee.count(newstr)) { //不存在
                            doublee[newstr] = init;
                        }
                        else {
                            doublee[newstr] += init;
                        }
                    }
                    else {
                        doublee[newstr] = init;
                    }
                }
            }
            else if (isupper(top)) {
                if (!single.empty()) {
                    if (!single.count(top)) { //不存在
                        single[top] = init;
                    }
                    else {
                        single[top] += init;
                    }
                }
                else {
                    single[top] = init;
                }

            }
            else if (islower(top)) {
                char top2 = s.top();
                s.pop();
                string newstr;
                newstr.push_back(top2);
                newstr.push_back(top);
                if (!doublee.empty()) {
                    if (!doublee.count(newstr)) { //不存在
                        doublee[newstr] = init;
                    }
                    else {
                        doublee[newstr] += init;
                    }
                }
                else {
                    doublee[newstr] = init;
                }

            }
        }
    }
    return;
}

signed main()
{
    stack<char>s;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]); //一個一個char放進stack
    }

    map<char, int>single;
    map<string, int>doublee;
    process(s, single, doublee, 1);
    cout << single.size() << endl;
    if (!single.empty()) {
        auto iter = single.begin();
        while (iter != single.end()) {
            cout << iter->first << ":" << iter->second << endl;
            ++iter;
        }
    }

    cout << doublee.size() << endl;
    if (!doublee.empty()) {
        auto iter = doublee.begin();
        while (iter != doublee.end()) {
            cout << iter->first << ":" << iter->second << endl;
            ++iter;
        }
    }
}