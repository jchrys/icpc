---
 File              : KMP-Algorithm.md
 Author            : JCHRYS <jchrys@me.com>
 Date              : 17.11.2019
 Last Modified Date: 17.11.2019
 Last Modified By  : JCHRYS <jchrys@me.com>
---
# KMP Algorithm
WIP

## KMP Failure Function
WIP

```cpp
#include <bits/stdc++.h> 
using namespace std;

vector<int> get_failure(string s) {
    int n = s.size();
    vector<int> res(n);
    res[0] = 0;
    int k = 0;
    for (int i = 1; i < n; i++) {
        while (k > 0 && s[k] != s[i])
            k = res[k - 1];
        if (s[k] == s[i])
            k++;
        res[i] = k;
    }
    return res;
}

int main() {
    string s = "abcabcdasdabcabcabc";
    vector<int> failure = get_failure(s);
    for (auto x: failure)
        cout << x << ' ';
    cout << endl;
    return 0;
}

```
