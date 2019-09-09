#Lower&Upper Bound 
> The C++ standard library contains the following functions that are based on binary search and work in logarithmic time.

- lower_bound: returns a pointer to the first array element whose value is at least $x$.

- upper_bound: returns a pointer to the first array element whose value is larger than $x$.

- equal_range: returns both above pointers

> The functions assume that the array is sorted.

> If there is no such element, the pointer points to the element after the last array element.

> For example, the following code finds out whether an array contains an element with vlaue $x$.

```cpp
auto k = lower_bound(array, array + n, x) - array;
if (k < n && array[k] == x) {
    // x found at index k
}
```

> Then, the following code counts th enumber o f elements whose value is $x$

```cpp
auto a = lower_bound(array, array + n, x);
auto b = upper_bound(array, array + n, x);
cout << b - a << '\n';
```

Using `equal_range`, the code becomes shorter:

```cpp
auto r = equal_range(array, array + n, x);
cout << r.second - r.first << '\n';
```


## Finding the smallest solution
> An important use for binary search is to find the position where the value of a function change.

> Suppose that we wish to find the smallest vlaue $k$ that is a valid solution for a problem.

> We are given a function `ok(x)` that returns `true` if $x$ is valid solution and false otherwise.

> In addition, we know that `ok(x)` is `false` when $x < k$ and `true` when $x \geq k$.

> Now, the value of $k$ can be found using binary search.

```cpp
int x = - 1;
for (int b = z; b >= 1; b /= 2) {
    while (!ok(x + b)) x += b;
}
int k = x + 1;
```

> The search finds the largest value of $x$ for which `ok(x)` is `false`.

> Thus, the next value `k = x + 1` is the smallest possible value for which `ok(k)` is `true`.

> The initial jump length $z$ has to be lar enough, for exmaple some vlaue for which we know beforehand that `ok(z)` is `true`.

> The algorithm calls the function `ok` $\Omicron(lgz)$ times, so the total time complexity depends on the function `ok`. 

> For example, if the function works in works in $\Omicron(n)$ time, the total time complexity is $Omicron(nlgz)$.


## Finding the maximum value
> Binary search can also be used to find the maximum value for a function that is first increasing and then decreasing. Our task is to find a poisition $k$ such that

- $f(x) < f(x + 1 )$ when $x < k $, and 
- $f(x) > f(x + 1)$ when $ x \geq k$

> The idea is to use binary search for finding the largest value of $x$ for which $f(x) < f(x + 1)$.

> This implies that $ k = x + 1$ because $f(x+1) > f(x + 2).

```cpp
int x = -1;
for (int b = z; b >= 1; b /= 2) {
    while (f(x + b) < f(x + b + 1)) x += b;
}
int k = x + 1;
```
> ==Note that unlike in the ordinary binary search, here it is not allowed that consecutive values of the function are equal.==

> In this case it would not be possible to know how to continue the search.
