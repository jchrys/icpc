# Range Queries
> In a range query, our task is to calculate a value based on a subarray of an array.

> Typical range queries are

- $sum_q(a, b)$: calculate the sum of values in range $[a, b]$
- $min_q(a, b)$: find the minimum value in range $[a, b]$
- $max_q(a, b)$: find the maximum value in range $[a, b]$

> A simple way to process range queries is to use a loop that goes through all array values in the range.

```cpp
int sum(int a, int b) {
    int s = 0;
    for (int i = a; i < b; i++) {
        s += array[i];
    }
    return s;
}
```
> This function works in $\Omicron(n)$ time, where $n$ is the size of the array.

> Thus, we can process $q$ queries in $\Omicron(nq)$ time using the function.

> However, if both $n$ and $q$ are large, this approach is slow.

> Fortunately, it turns out that there are ways to process range queries much more efficiently.


## Table of contents

### Static array queries
- Sum queries
- Minimum queries

### Binary indexed tree(== Fenwick tree)

### Segment tree

### Other queries

### Additional techniques
- Index compression
- Range updates
