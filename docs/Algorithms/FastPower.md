title: Fast Power Algorithm
hero: Fast Power Algorithm
description: fastest Power Algorithm
author: jchrys

# Fast Power Algorithm
> FAST!   
> time complexity $\Omicron(pow)$





## Implementation

### Recursive
```cpp
int power(int  base, int pow) {
    if (!pow) 
        return 1;
    if (n & 1) // if n is odd
        return base * power(base, (pow - 1) >> 1) * power(base, (pow -1) >> 1);
    return power(base, pow >> 1) * power(base, pow >> 1);
}
```

### Iterative
```cpp
int power(int base, int pow) {
    if (!pow) 
        return 1;
    int result = 1;
    while (pow) {
        if (pow & 1) {
            result *= base;
            pow--; // not necessary
        }
        pow >>= 1;
        base *= base;
    }
    return result;
}
```
#### How it works?
<img width="698" alt="Screen Shot 2019-08-19 at 7 32 35 PM" src="https://user-images.githubusercontent.com/45776091/63258969-34f8c380-c2b8-11e9-9cfd-ca68248e2be4.png">
