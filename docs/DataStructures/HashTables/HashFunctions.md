# Hash Function
A hash function is any function that can be used to map data of arbitrary size onto data of a fixed size.

## Hash Functions

### 1. DJB2 [:bug:](http://www.cse.yorku.ca/~oz/hash.html)
>this algorithm (k=33) was first reported by dan bernstein many years ago in comp.lang.c. another version of this algorithm (now favored by bernstein) uses xor: hash(i) = hash(i-1) * 33 ^ str[i]; the magic of number 33 (why it works better than many other constants, prime or not) has never adequately explained

```cpp
    #define ll unsigned long long

    unsigned long long djb2(char *str) {
        unsigned long long hash = 5381;
        int c;
        while ((c = *(str++))) {
            hash = (hash << 5) + hash + c; //equivalent to hash = hash * 33 + c;
        }
        return hash;
    }
```

### 2. sdbm [:bug:](http://www.cse.yorku.ca/~oz/hash.html) 
>this algorithm was created for sdbm (a public-domain reimplementation of ndbm) database library. it was found to do well in scrambling bits, causing better distribution of the keys and fewer splits. it also happens to be a good general hashing function with good distribution. the actual function is hash(i) = hash(i - 1) * 65599 + str[i];; what is included below is faster version used in gawk. (there iseven a faster, duff's device version) the magic constant 65599 was picked out of thin air while experimenting with different constants, and turns out to be a prime. this is one of the algorithms used in berkeley db (see sleepy cat) and else where

```cpp
#define ll unsigned long long

unsigned long long djb2(char *str) {
    unsigned long long hash = 0;
    int c;

    while ((c = *(str++))) {
        hash = c + (hash << 6) + (hash << 16) - hash; 
    }

    return hash;
}
```

### 3. lose lose [:bug:](http://www.cse.yorku.ca/~oz/hash.html)
>This hash function appeared in K&R (1st ed) but at least the reader was warned: "This is not the best possible algorithm, but it has the merit of extreme simplicity". This is an understatement; It is a terrible hashing algorithm, and it could have been much better without scarificing its "extreme simplicity." Many C programmers use this function without actually testing it, or checking something like Knuth's Sorting and searching, so it stuck. It is now found mixed with other respectable code, eg.cnews.

!!! warning 
    Don't use this algorithm, it's terrible.

```cpp
#define ll unsigned long long

ll loseLose(char *str) {
    ll hash = 0;
    int c;

    while (c = *str++) {
        hash += c;
    }

    return hash
}

```
