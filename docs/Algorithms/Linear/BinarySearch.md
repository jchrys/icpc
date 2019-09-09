# Binary search
> A general method for search for an element in an array is to use `for` loop that iterates through the elements of the array.

> For example, the following code searches for an element $x$ in an array

```cpp
for (int i = 0; i < n; i++) {
    if (array[i] == x) {
        //x found at index i;
    }
}
```

> The time complexity of this approach is $\Omicron(n)$, because in the worst case, it is necessary to check all elements of the array.

> If the order of the elements is arbitrary, this is also the best possible approach, because there is no additional information available where in the array we should search for the element $x$.

> However, If the array is sorted, the situation is different.

> In this case it is possible to perform the search much faster, because the order of the elements in the array guides the search.

> The following binary search algorithm efficiently search for an element in a sorted array in $\Omicron(lgn)$ time.


## Time Compelxity
| Algorithm | time complexity |
|:---------:|:---------------:|
|  Method1  | $\Omicron(lgn)$ |
|  Method2  | $\Omicron(lgn)$ |

## Implementation

### Method 1
> The usual way to implement binary search resembles looking for a word in a dictionary. 

> The search maintains an active region in the array, which initially contains all array elements.

> Then, a number of steps is performed, each of which havles the size of the region.

> At each step, the search checks to middle element of the active region.

> If the middle elemnt is the target element, the search terminates.

> Otherwise, the search recursively continues to the left or right half of the region, depending on the value of the middle element.

```cpp
int a = 0, b = n - 1;
while (a <= b) {
    int k = (a + b) / 2;
    if (array[k] == x) {
        // x found at index k;
    }
    if (array[k] > x) b = k - 1;
    else a = k + 1;
}
```
> In this implementation, the active region is $a\dots b$, and initially the region is $0\dots n - 1$ .

> The algorithm havles the size of the region at each step, so the time complexity is $\Omicron(lgn)$.


### Method 2
> An alternative method to implement binary search is based on an efficient way to itertate through the elmetns of the array.

> The idea is to make umps and slow the speed when we get closer to the target element.

> The search goes through the array from left to right, and the initial jump length is $n/2$.

> At each step, the jump length will be havled: first $n/4$, then $n/8$, $n/16$, etc., until finally the length is 1.

> After the jumps, either the target element has been found or we know the it does not appear in the array.

```cpp
int k = 0;
for (int b = n / 2; b >= 1; b /= 2) {
    while( k+b < n && array[k + b] <= x) k += b;
}
if (array[k] == x) {
    // x found at index k
}
```


> During the search, the variable $b$ contains the current jump length.

> The time complexity of the algorithm is $\Omicron(lgn)$, because the code in the `while` loop is performed at most twice for each jump length. 


