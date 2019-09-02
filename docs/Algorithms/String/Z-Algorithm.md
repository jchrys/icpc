# Z-algorithm
> The Z-array $z$ of a string $s$ of length $n$ contains for each $k=0,1,\dots,n-1$ the length of longest substring of s that begins at position $k$ and is a prefix of $s$.

> Thus, $z[k] = p$ tells us that $s[0\dots p-1]$ equals $s[k\dots k + p -1]$.

> Many string processing problems can be efficiently solved using Z-array.

## Algorithm description
> Next we describe an algorithm, called the Z-algorithm, that efficiently constructs the Z-array in $\Omicron(n)$ time.

> The algorithm calculates the Z-array values from left to right by both using information already stored in the Z-array and comparing substrings character by character.

> To efficiently calculate the Z-array values, the algorithm maintains a range $[x, y]$ such that $s[x \dots y]$ are equal, we can use this information when calculating Z-values for positions $x + 1, x + 2, \dots, y$.

> At each poisition $k$, we first check the value of $z[k-x]$.

> if $k + z[k - x] < y$, we know that $z[k] = z[k - x]$.

> However, if $k + z[k - x] >= y, s[0\dots y-k]$ equals $s[k \dots y],$ and to determine the value of $z[k]$ we need to compare the substring character by character.

> Still, the algorithm works in $\Omicron(n)$ time, because we start comparing at positions $y - k + 1$ and $y + 1$.

## Using Z-array
> It if often a matter of taste whether to use [string hashing](/Algorithms/String/StringHashing) or the Z-algorithm.

> Unlike hashing, the Z-algorithm always works and there is no risk for collisions.

> On the other hand, Z-algorithm is more difficult to implement and some problems can only be solved using hashing.


## Implementation
> Here is a short impelmentation of the Z-algorithm that returns a vector that corresponds to the Z-array.

```cpp
vector<int> z(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
        x = i;
        y = i + z[i];
        z[i]++;
        }
    }
    return z;
}
```
