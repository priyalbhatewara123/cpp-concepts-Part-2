#include <iostream>
#include <set>
using namespace std;

typedef multiset<int>::iterator It;

int main() {

    int arr[] = {10, 20, 30, 20, 10, 10, 20, 40, 30, 40};
    int n = sizeof(arr) / sizeof(int);
    multiset<int> m(arr, arr + n);

    //1. Iterator
    for (int x : m) {
        cout << x << ",";
    }
    cout << endl;
    //2. Erase an element from set - It will erase all occurrences of that element
    m.erase(20);

    //3. Insert an element in set
    m.insert(78);
    for (int x : m) {
        cout << x << ",";
    }

    cout << endl;
    //4. Count the number of occurrences of any element
    cout << m.count(10) << endl;

    //5. Find iterator to an element
    auto it = m.find(30);
    cout << (*it) << endl;

    //6. Equal Range
    pair<It, It> range = m.equal_range(40);
    for (auto it = range.first; it != range.second; it++) {
        cout << *it << endl;
    }


    //7. Lower Bound and Upper Bound
    for (auto it = m.lower_bound(20); it != m.upper_bound(77); it++) {
        cout << *it << ",";
    }

    return 0;
}
