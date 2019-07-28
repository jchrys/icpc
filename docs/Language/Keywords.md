
#Aliases
Aliases are used when we want to insulate our code from details of the underlying machine.
- note that naming a type after its representation than its purpose is not neccessarily a good idea.

## 1. typedef 
```
cpp
typedef double decimal_places; // is equivalent to "using decimal_places = double;"
```


## 2. using
the using keyword can also be used to introduce a template alias.
```cpp
template<typename T>
    using Vector = std::vector<T, my_allocator<T>>
```
but we cannot apply type specifiers, such as unsigned, to an alias.
```cpp
using Char = char;
using Uchar = unsigned Char;  //error
using Uchar = unsigned char; // ok
```
