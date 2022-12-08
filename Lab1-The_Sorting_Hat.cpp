#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>ranking;

typedef struct _student {
    string name;
    int grade[4];
}student;

int check(char c) {
    switch (c) {
    case 'G':
        return 0;
        break;
    case 'H':
        return 1;
        break;
    case 'R':
        return 2;
        break;
    case 'S':
        return 3;
        break;
    }
}

bool cmp0(student a, student b) {
    int c1 = check(ranking[0][0]), c2 = check(ranking[0][1]), c3 = check(ranking[0][2]), c4 = check(ranking[0][3]);
    if (a.grade[c1] != b.grade[c1]) {
        return a.grade[c1] > b.grade[c1];
    }
    else if (a.grade[c2] != b.grade[c2]) {
        return a.grade[c2] > b.grade[c2];
    }
    else if (a.grade[c3] != b.grade[c3]) {
        return a.grade[c3] > b.grade[c3];
    }
    else if (a.grade[c4] != b.grade[c4]) {
        return a.grade[c4] > b.grade[c4];
    }
    else {
        for (int i = 0;; i++) {
            if (a.name[i] != b.name[i]) {
                return (int)a.name[i] < (int)b.name[i];
                break;
            }
        }
    }
}

bool cmp1(student a, student b) {
    int c0 = check(ranking[1][0]), c1 = check(ranking[1][1]), c2 = check(ranking[1][2]), c3 = check(ranking[1][3]);
    if (a.grade[c0] != b.grade[c0]) {
        return a.grade[c0] > b.grade[c0];
    }
    else if (a.grade[c1] != b.grade[c1]) {
        return a.grade[c1] > b.grade[c1];
    }
    else if (a.grade[c2] != b.grade[c2]) {
        return a.grade[c2] > b.grade[c2];
    }
    else if (a.grade[c3] != b.grade[c3]) {
        return a.grade[c3] > b.grade[c3];
    }
    else {
        for (int i = 0;; i++) {
            if (a.name[i] != b.name[i]) {
                return (int)a.name[i] < (int)b.name[i];
                break;
            }
        }
    }
}

bool cmp2(student a, student b) {
    int c0 = check(ranking[2][0]), c1 = check(ranking[2][1]), c2 = check(ranking[2][2]), c3 = check(ranking[2][3]);
    if (a.grade[c0] != b.grade[c0]) {
        return a.grade[c0] > b.grade[c0];
    }
    else if (a.grade[c1] != b.grade[c1]) {
        return a.grade[c1] > b.grade[c1];
    }
    else if (a.grade[c2] != b.grade[c2]) {
        return a.grade[c2] > b.grade[c2];
    }
    else if (a.grade[c3] != b.grade[c3]) {
        return a.grade[c3] > b.grade[c3];
    }
    else {
        for (int i = 0;; i++) {
            if (a.name[i] != b.name[i]) {
                return (int)a.name[i] < (int)b.name[i];
                break;
            }
        }
    }
}

bool cmp3(student a, student b) {
    int c0 = check(ranking[3][0]), c1 = check(ranking[3][1]), c2 = check(ranking[3][2]), c3 = check(ranking[3][3]);
    if (a.grade[c0] != b.grade[c0]) {
        return a.grade[c0] > b.grade[c0];
    }
    else if (a.grade[c1] != b.grade[c1]) {
        return a.grade[c1] > b.grade[c1];
    }
    else if (a.grade[c2] != b.grade[c2]) {
        return a.grade[c2] > b.grade[c2];
    }
    else if (a.grade[c3] != b.grade[c3]) {
        return a.grade[c3] > b.grade[c3];
    }
    else {
        for (int i = 0;; i++) {
            if (a.name[i] != b.name[i]) {
                return (int)a.name[i] < (int)b.name[i];
                break;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    vector<vector<student>>document;
    document.resize(4);
    cin >> n;
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        ranking.push_back(s);

    }
    for (int i = 0; i < n; i++) {
        student student;
        int a, max = 1, index;
        cin >> student.name;
        for (int j = 0; j < 4; j++) {
            cin >> student.grade[j];
            if (max < student.grade[j]) {
                max = student.grade[j];
                index = j;
            }
        }
        document[index].push_back(student);
    }
    sort(document[0].begin(), document[0].end(), cmp0);
    sort(document[1].begin(), document[1].end(), cmp1);
    sort(document[2].begin(), document[2].end(), cmp2);
    sort(document[3].begin(), document[3].end(), cmp3);

    if (!document[0].size()) {
        cout << "GRYFFINDOR: NO NEW STUDENTS" << '\n';
    }
    else {
        cout << "GRYFFINDOR:" << '\n';
        for (int i = 0; i < document[0].size(); i++) {
            cout << document[0][i].name << '\n';
        }
    }

    if (!document[1].size()) {
        cout << "HUFFLEPUFF: NO NEW STUDENTS" << '\n';
    }
    else {
        cout << "HUFFLEPUFF:" << '\n';
        for (int i = 0; i < document[1].size(); i++) {
            cout << document[1][i].name << '\n';
        }
    }

    if (!document[2].size()) {
        cout << "RAVENCLAW: NO NEW STUDENTS" << '\n';
    }
    else {
        cout << "RAVENCLAW:" << '\n';
        for (int i = 0; i < document[2].size(); i++) {
            cout << document[2][i].name << '\n';
        }
    }

    if (!document[3].size()) {
        cout << "SLYTHERIN: NO NEW STUDENTS" << '\n';
    }
    else {
        cout << "SLYTHERIN:" << '\n';
        for (int i = 0; i < document[3].size(); i++) {
            cout << document[3][i].name << '\n';
        }
    }

}