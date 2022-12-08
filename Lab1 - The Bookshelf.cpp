#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    long int a;
    long int b;
    cin >> a >> b;
    map<long int, long int>books;
    int height;
    for (int i = 0; i < a; i++) {
        cin >> height;
        books[height] = i;
    }
    for (long int i = 0; i < b; i++) {
        long int flag = 0, check;
        cin >> check;
        auto iter = books.find(check);
        if (iter == books.end()) {
            cout << "-1" << '\n';
        }
        else {
            cout << iter->second << '\n';
        }
    }
}