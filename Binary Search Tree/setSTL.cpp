#include <bits/stdc++.h>
using namespace std;

int main() {
    set<pair<int, int>> s;

    s.insert(make_pair(10, 20));
    s.insert(make_pair(10, 30));
    s.insert(make_pair(10, 100));
    s.insert(make_pair(20, 10));
    s.insert(make_pair(30, 40));
    s.insert(make_pair(50, 90));

    //s.erase(make_pair(10,30));

    auto it = s.upper_bound(make_pair(10, 100));
    cout << it -> first << " " << it-> second << endl;

    //first element of a pair should be greater than 20
    auto it1 = s.upper_bound(make_pair(20, INT_MAX));
    cout << it1 -> first << " " << it1-> second << endl;

    cout << "SET: " << endl;
    for (auto p : s) {
        cout << p.first << " " << p.second;
        cout << endl;
    }
}
