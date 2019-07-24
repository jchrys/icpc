# Hash Function
A hash function is any function that can be used to map data of arbitrary size onto data of a fixed size.

## Hash Functions

1. DJB2

- C++
```cpp
unsigned long long djb2(char *str) {
    unsigned long long hash = 5381;
    int c;
    while ((c = *(str++))) {
        hash = (hash << 5) + hash + c;
    }
    return hash;
}
```
- JavaScript
```javascript
function djb2() {

    return hash;
}
```

