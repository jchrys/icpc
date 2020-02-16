---
 File              : InsertionSort.md
 Author            : JCHRYS <jchrys@me.com>
 Date              : 16.02.2020
 Last Modified Date: 16.02.2020
 Last Modified By  : JCHRYS <jchrys@me.com>
---
# Insertion Sort
> Insertion Sort is very simple algorithm
> it works exactly like the way you sort a deck of card

## Time Complexity

|                 |  Worst case  |    Best case   |
|:---------------:|:------------:|:--------------:|
| Time complexity | $Omicron(N)$ | $Omicron(N^2)$ |

## C++
```cpp
template<typenme It> // Iterator
void insertionSort(It begin, It end) { //TODO add comparator
    if (begin == end) return; // return if container is empty
    for (It i = begin; i != end; i++) {
        for (It j = i; j != begin; j--) {
            if (*(j-1) < *j) break;
            swap(*(j-1), *j);
        }
    }
}
```

