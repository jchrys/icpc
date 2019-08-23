# Heap Sort
> [Heap](/DataStructures/Linear/Heap) is a nearly complete binary tree. we can easily implement on basic array object.

> Heap Structure satisfies Heap Property

!!! note "Heap Property"
    max-heap-property: Parent's Key $\geq$ Children's key    
    min-heap-property: Parent's Key $\leq$ Children's key

## Implementation

```cpp
#include <iostream>
using namespace std;
int arr[1000000];
int heap_size;
template<typename T>
void _swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
} 
inline int parent(int i) {
    return (i - 1) >> 1;
}

inline int left(int i) {
    return (i << 1) + 1;
}

inline int right(int i) {
    return (i << 1) + 2;
}

void max_heapify(int i) {
    int largest;
    int l = left(i);
    int r = right(i);
    if (l < heap_size && arr[l] > arr[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r < heap_size && arr[r] > arr[largest]) 
        largest = r;
    if (largest != i) {
        _swap(arr[largest], arr[i]);
        max_heapify(largest);
    }
}

void build_maxheap() {
    for (int i = parent(heap_size-1); i >= 0; i--) {
        max_heapify(i);
    }
}

void heapsort() {
    build_maxheap();
    for (int i = (heap_size-1); i >= 0; i--) {
        _swap(arr[i], arr[0]);
        heap_size--; // reduce heap_size at here;
        max_heapify(0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 5000;
    //cin >> n;
    heap_size = n;
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%5000;
    }
    heapsort();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}
```


## Related Problems
1. [Sort](https://www.acmicpc.net/problem/2751) :star:
