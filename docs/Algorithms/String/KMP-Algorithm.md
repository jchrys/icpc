---
 File              : KMP-Algorithm.md
 Author            : JCHRYS <jchrys@me.com>
 Date              : 17.11.2019
 Last Modified Date: 16.02.2020
 Last Modified By  : JCHRYS <jchrys@me.com>
---
# KMP Algorithm
WIP

## KMP Failure Function
WIP


## Implementation

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

vector<pair<int, int>> find(string text, string pattern) {
    vector<pair<int, int>> res; 
    vector<int> failure = get_failure(pattern);
    int n = text.size();
    int m = failure.size();
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j])
            i++,j++;
        if (j == m) {
            res.push_back({i - j, i - 1});
            j = failure[j - 1];
        }
        while (j > 0 && pattern[j] != text[i])
            j = failure[j - 1];
        if (j == 0)
            i++;
    }
    return res;
}

int main() {
    string pattern = "ABABAC";
    string text = "ABABACABAABAABABABABAC";
    vector<pair<int, int>> found = find(text, pattern);
    for (auto x: found) {
        cout << x.first << ' ' << x.second << '\n';
    }
}

```
