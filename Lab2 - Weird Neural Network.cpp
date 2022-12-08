#include <iostream>
#include<vector>
using namespace std;

#define int long long

int m = 1000000007;

struct node {
    int weight;
    node* up;
    node* down;
};

int postorder(node* current) {
    int sum;
    int a;
    int b;
    if (current->up == NULL) {
        if (current->down == NULL) {
            return (current->weight) % m;
        }
        else if (current->down != NULL) {
            sum = ((current->weight % m) * (postorder(current->down))) % m;
            return sum;
        }
    }
    else if (current->down == NULL) {
        if (current->up != NULL) {
            sum = ((current->weight % m) * (postorder(current->up))) % m;
            return sum;
        }
    }
    else if (current->up != NULL && current->down != NULL) {
        a = postorder(current->up);
        b = postorder(current->down);
        sum = ((current->weight % m) * (a + b)) % m;
        return sum;
    }
}

signed main()
{
    int n;
    cin >> n;
    vector<struct node> network(n);
    
    int c;
    cin >> c;
    struct node neww;
    network[0].weight = c;
    network[0].up = NULL;
    network[0].down = NULL;

    struct node *pointer = &network[0];

    for (int i = 1; i < n; i++) {
        int cc;
        cin >> cc;
        struct node newww;
        network[i].weight = cc;
        network[i].up = NULL;
        network[i].down = NULL;
    }

    for (int i = 1; i < n; i++) {
        int o;
        cin >> o;
        if (network[o - 1].up == NULL) {
            network[o - 1].up = pointer + i;
        }
        else if (network[o - 1].down == NULL) {
            network[o - 1].down = pointer + i;
        }
    }
    cout << postorder(pointer);
}