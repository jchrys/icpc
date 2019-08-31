# QuickSort
> Quicksort is often the best practical choice for sorting because it is remarkably efficient on the average: its expected running time is $\Theta(n\text{lg}n)$.
> and the constant factors hidden in the $\Theta(n\text{lg}n)$ notation are quite small.
> It also has the advantage of sorting in place and it works well even in virtual-memory environments.

!!!warning "unstable"
    quicksort is unstable sort algorithm

!!!note "stable in sorting algorithm"
    A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in the sorted output as they appear in the unsorted input.

    Whereas a sorting algorithm is said to be unstable if there are two or more objects with equal keys which don’t appear in same order before and after sorting.

## Timecomplexity

|  Average-Case  |    Worst-Case   |
|:--------------:|:---------------:|
| $\Theta(nlgn)$ | $\Omicron(n^2)$ |

## Description
> Quicksort, like merge sort, applies the divide-and-conquer paradigm.

> Here is the three-step divide-and-conquer process for sorting a typical subarray $A[p..r]$.

### 1. Divide
> Partition (rearrange) the array $A[p..r]$ into two (possibly empty) subarrays $A[p..q-1]$ and $A[q + 1..r]$  such that each element of $A[p.. q - 1]$ is less than or equal to $A[q]$, which is, in turn, less than or equal to each element of $A[q + 1..r]. 
> Compute the index $q$ as part of this partitioning procedure.

### 2. Conquer
> Sort the two subarrays $A[p..q - 1]$ and $A[q + 1..r] by recursive calls to quicksort

### 3. Combine
> Because the subarrays are already sorted, no work is needed to combine them: the entire array $A[p..r]$ is now sorted

## Implementations

### CLRS version
> SLOW!

```cpp
/**
 * File              : 2571-qSort-clrs.cpp
 * Author            : JCHRYS <jchrys@me.com>
 * Date              : 31.08.2019
 * Last Modified Date: 31.08.2019
 * Last Modified By  : JCHRYS <jchrys@me.com>
 */

#include <iostream>
using namespace std;

template<typename T>
void _swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int partition(T &A, int p, int r) {
    auto pivot = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= pivot) {
            i++;
            _swap(A[i], A[j]);
        } 
    }
    _swap(A[i+1], A[r]);
    return i + 1;
}


template<typename T>
void qSort(T &A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        qSort(A, p, q - 1);
        qSort(A, q + 1, r);
    }
}


int arr[1000000];
int main() {
    int n = 100;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < n; i++)
        arr[i] = rand()%100;
    qSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}

```

### FAST version

```cpp
/**
 * File              : 2571-qSort-fast.cpp
 * Author            : JCHRYS <jchrys@me.com>
 * Date              : 31.08.2019
 * Last Modified Date: 31.08.2019
 * Last Modified By  : JCHRYS <jchrys@me.com>
 */

#include <iostream>
using namespace std;



template<typename T>
void _swap(T &lh, T &rh) {
    T temp = lh;
    lh = rh;
    rh = temp;
}
template<typename It, typename Comp>
void qSort(It begin, It end, Comp comp) {
    if (begin == end) return; //corner case
    //pick pivot randomly
    _swap(*(begin), *((end - begin)/ 2 + begin));
    It pivot = begin;
    It left = begin + 1;
    It right = end - 1;
    while (left <= right) {
        while (left <= right && !comp(*right, *pivot))
            right--;
        while (left <= right && !comp(*pivot, *left))
            left++;
        if (left <= right)
            _swap(*left, *right);
    }
    _swap(*right, *pivot);
    qSort(begin, right, comp);
    qSort(right + 1, end, comp);
} 

bool comp(int const &lh, int const &rh) {
    return lh < rh;
}



int n = 100;
int A[10000000];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < n; i++)
        A[i] = rand()%100;
    qSort(A, A + n, comp);
    for (int i = 0; i < n; i++)
        cout << A[i] << ' ';
    return 0;
}
```
 

