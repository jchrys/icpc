# Segment Tree
> A segment tree is a data structure that supports two operations: processing a range query and updating an array value.

> Segment trees can support sum queries, minimum and maximum queries and many other queries so that both operations work in $\Omicron(lgn)$ time.

|    DataStructure    |               Operations              |
|:-------------------:|:-------------------------------------:|
| Binary indexed tree |              sum queries              |
|     Segment tree    | sum, minimum, maximum and many others |


## Structure
> A segment tree is a binary tree such that the nodes on the bottom level of the tree corresponds to the array elements, and the other nodes contain information needed for processing range queries.

## Time complexity
|    Operation   | Time complexity |
|:--------------:|:---------------:|
|     build()    |  $\Omicron(n)$  |
|   query(l, r)  | $\Omicron(\log(n))$ |
| update(pos, x) | $\Omicron(\log(n))$ |


## Implementation
> Following implementation support single array element update
```cpp
const int N = 1e5; // limit for array size
int n; // array size
int t[2 * N];

void build() { // build the tree
    for (int i = n - 1; i > 0; i--)
        t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(int p, int value) { // set value at position p;
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}

int query(int l, int r) { // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1)
            res += t[l++];
        if (r&1)
            res += t[--r];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", t + n + i);
    build();
    modify(0, 1);
    printf("%d\n", query(3, 11));
    return 0;
}
```

## Implementation






## Problems
1. [구간 곱 구하기](https://www.acmicpc.net/problem/11505)
2. [구간 합 구하기](https://www.acmicpc.net/problem/2042)
3. [최솟값](https://www.acmicpc.net/problem/10868)
4. [최솟값과 최댓값](https://www.acmicpc.net/problem/2357)
