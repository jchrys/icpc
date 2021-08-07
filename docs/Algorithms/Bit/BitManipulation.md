# Bit Manipulation

## Find Most Significant Bit
> Below implementation is using built-in function

```cpp
#include <bits/stdc++.h>
using namespace std;


int msb(int x) {
    return sizeof (int) * 8 - __builtin_clz(x);
}

int msb(long long x) {
    return sizeof(long long) * 8 - __builtin_clzll(x);
}


int main() {
    for (int x = 0; x < 10; ++x) {
        printf("x: %d, msb: %d\n", x, msb(x));
    }
    return 0;
}
```

```bash
x: 0, msb: 0
x: 1, msb: 1
x: 2, msb: 2
x: 3, msb: 2
x: 4, msb: 3
x: 5, msb: 3
x: 6, msb: 3
x: 7, msb: 3
x: 8, msb: 4
x: 9, msb: 4
```
