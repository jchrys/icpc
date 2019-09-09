# Pair
This class couples together a pair of values, which may be of different types (T1 and T2). The individual values can be accessed through its public members first and second.

## Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B>
struct _pair{
    A first;
    B second;
    _pair(A a, B b): first(a), second(b) {}
    bool operator(_pair const &rh) const {
        if (this.first == rh.first) {
            return this->second < rh.second;
        }
        return this->first < rh.first;
    }
};

int main() {
    vector<_pair<int, _pair<int, int>>> v;
    for (int i = 0; i < 20; i++) {
        v.push_back({1, {rand()%10, i}});
    }
    sort(v.begin(), v.end());
    for (auto x: v) {
        cout << x.first << ' ' << x.second.first 
        << ' ' << x.second.second << endl;
    }
    return 0;
}

```
