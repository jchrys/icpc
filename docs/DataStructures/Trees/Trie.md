# Trie
> A trie is a rooted tree that maintains a set of strings.

> Each string in the set is stored as a chain of characters that starts at the root.

> If two string have a common prefix, they also have a common chain in the tree.

> Using a trie, we can find the longest prefix of a given string such that the prefix belongs to the set.

> ==Moreover, by storing additional information in each node, we can calculate the number of strings that belong to the set and have a given string as a prefix.==

> it's advantage is, LCP(Longest Common Prefix) of two of these strings is the LCA(Lowest Common Ancestor) of their node in the trie(a node that we can build the string by writing down the characters in the path from the root to that node).

## Time Complexity
|     operation    |      time complexity      |
|:----------------:|:-------------------------:|
| contains(string) | $\Omicron(string.size())$ |
|    add(string)   | $\Omicron(string.size())$ |



## Implementation
> A trie can be stored in an array
```cpp
int const N = 1e6+99; // where maximum number of nodes 
int const AL = 27; // size of the alphabet + TERMINATION character
int const TERM = 26; // TERMIANTION character. (indicates end of string)
int trie[N][A];
```

> where $N$ is the maximum number of nodes(the maximum total length of the strings in the set) and $A$ is the size of the alphabet.

> The nodes of a trie are numbered 0, 1, 2, ... so that the number of the root node is 0, and `trie[s][c]` is the next node in the chain when we move from node `s` using character `c`.

```cpp

int const N = 1e6+99; // where maximum number of nodes 
int const AL = 27; // size of the alphabet + TERMINATION character
int const TERM = 26; // TERMIANTION character. (indicates end of string)
int const ROOT = 0;
int trie[N][AL]; //initially all the number in trie are -1;
int nxt = 1;

void build() {
    memset(trie, -1, sizeof trie);
    nxt = 1;
}

void insert(string s) {
    int curNode = ROOT;
    for (int i = 0; i < s.size(); ++i) {
        int c = s[i] - 'a';
        if (~trie[curNode][c]) { // equivalent to (-1 != trie[curNode][c])
            curNode = trie[curNode][c];
        } else {
            curNode = trie[curNode][c] = nxt++;
        }
    }
    ++trie[curNode][TERM];
}

bool contains(string s) {
    int cur = ROOT;
    for (int i = 0; i < s.size(); ++i) {
        int c = s[i] - 'a';
        if (~trie[cur][c]) {
            cur = trie[cur][c];
        } else {
            return false;
        }
    }
    return ~trie[cur][TERM];
}

int count(string s) {
    int cur = ROOT;
    for (int i = 0; i < s.size(); ++i) {
        int c = s[i] - 'a';
        if (~trie[cur][c]) {
            cur = trie[cur][c];
        } else {
            return 0;
        }
    }
    return trie[cur][TERM] + 1;
}

int main() {
    build();
    insert("hello");
    cout << contains("world") << endl;
    insert("world");
    cout << contains("world") << endl;
    insert("hello");
    cout << count("hello") << endl;
    return 0;
}

```

## Problems
1. [A Lot of Games](https://codeforces.com/contest/456/problem/D)

