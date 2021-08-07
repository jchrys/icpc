# Binary indexed tree
> A binary index tree or a Fenwick tree can be seen as a dynamic variant of a prefix sum array.

> It supports two $\Omicron(lgn)$ time operations on an array: processing a range sum query and updating a value

> ==The advantage of binary indexed tree is that it allows us to efficiently update array values between sum queries.==

> This would not be possible using a [prefix sum array], because after each update, it would be neccessary to build the whole prefix sum array again in $\Omicron(n)$ time.


## Time complexity

|   operation  | time complexity |
|:------------:|:---------------:|
|   sum(a, b)  | $\Omicron(lgn)$ |
| update(i, x) | $\Omicron(lgn)$ |


## Structure
> Even if the name of the structure is a binary indexed _tree_, it is usually represented as an array.

> ==we assume that all arrays are one-indexed, because it makes the implement easier==

> ==Let $p(k)$ denote the largest power of two that divides $k$.(or right most 1 in it's binary representation)==

> We store a binary indexed tree as an array tree such that

$$
\text{tree}[k] = \text{sum}(k-p(k) + 1, k)
$$


> each position $k$ contains the sum of values in a range of the original array whose length is $p(k)$ and that ends at position $k$.


> Using a binary indexed tree, any value of $\text{sum}(1, k)$ can be calculated in $\Omicron(lgn)$ time, because a range $[1, k]$ can always be divded into $\Omicron(lgn)$ ranges whose sums are stored in the tree.

### Range sum query
> To calculate the value of $\text{sum}(a, b)$ where a > 1:
$$
\text{sum}(a, b) = \text{sum}(1, b) - \text{sum}(1, a - 1)
$$

> Since we can calculate both $\text{sum}(1, b)$ and $\text{sum}(1, a-1)$ in $\Omicron(lgn)$ time, the total time complexity is $\Omicron(lgn)$.

### Updating
> After updating a value in the original array, several values in the binary indexed tree should be updated.

> Since each array element belong to $\Omicron(lgn)$ ranges in the binary indexed tree, it suffices to update $\Omicron(lgn)$ values in the tree.


## Implementation
> The key fact needed is that we can calculate anyvalue of $p(k)$ using the formula

$$
p(k)=k\&-k
$$

> The following function calculates the value of $sum(1, k)$

```cpp
int sum(int k) {
    int s = 0;
    while (s >= 1) {
    s += tree[k];
    k -= k&-k;
    }
    return s;
}
```

> The following function increases the array value at position $k$ by $x$. 

```cpp
void add(int k, int x) {
    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}
```


## Implementation (0-indexed)
```cpp
#include <bits/stdc++.h>
int N = 10000;
int f[N]{};

void upd(int k, int x) {
    for (; k < N; k |= k + 1)
        f[k] += x;
}

int get(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        res += f[pos];
    return res;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}



```

## Problems
1. [구간 합 구하기](https://www.acmicpc.net/problem/2042) :star::star::star:
