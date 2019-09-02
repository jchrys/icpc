# Trie
> A trie is a rooted tree that maintains a set of strings.

> Each string in the set is stored as a chain of characters that starts at the root.

> If two string have a common prefix, tey also have a common chain in the tree.

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
int trie[N][A];
```

> where $N$ is the maximum number of nodes(the maximum total length of the strings in the set) and $A$ is the size of the alphabet.

> The nodes of a trie are numbered 0, 1, 2, ... so that the number of the root is 0, and trie[s][c] is the next node in the chain when we move from node $s$ using character $c$.

```cpp
int trie[N][A]; //initially all the number in trie are -1;
int next = 1;

void add(string s) {
    int i = 0; v = 0;
    while(i < s.size()) {
        if (trie[v][s[i]]) == -1) {
            v = trie[v][s[i]] = next;
            ++i;++next;
        } else {
            v = trie[v][s[i]];
            ++i;
        }
    }
}


```

## Problems
1. [A Lot of Games](https://codeforces.com/contest/456/problem/D)

