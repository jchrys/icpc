# Bubble Sort
> Bubble Sort

## C++
```
template<typename It>
void BubbleSort(It begin, It end) {
    if (begin == end) return; //return if container is empty
    for (It i = end - 1; i != begin; i--) {
        for (It j = begin; j != i; j++) {
            if (*j > *(j + 1)) swap(*j, *(j+1));
        }
    }
}

```
