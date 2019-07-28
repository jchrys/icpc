# Why C++?

## What You Should Know Before..
> you should be able to write C++ programs using components such as IOstreams and containers from C++ STL.
> You Should be also be familiar with the basic features of "Modern c++", such as auto, decltype, move semantics, and lambdas.
> c++17



## modern c++
> We will use number of these new features in this site.
### 1. c++11
- Variadic templates
- Alias templates
- Move semantics, rvalue references, and perfect forwarding
- Standard type traits

### 2. c++14
- Variable templates
- Generic Lambdas

### 3. c++17
- Class template argument deduction
- Compile-time `if`
- Fold expressions


## Style Guide

### 1. the order of constant qualifier.
> What is in front of `const` qualifier is always a constant

:+1:
```cpp
int const MAX_SIZE = 100; // the int is constant
int* const P; // the pointer cannot change, but int value can;
```

:-1:
```cpp
const int MAX_SIZE = 100; 
const int* P; // you can not find what's constant value;
```

reason1. easy to know what's constant.
it's always what is in front of the `const` qualifier
reason2. syntatical substitution principle.
consider following example
```
typedef char* CHARS;
typedef CHARS const CPTR; // constant pointer to chars
// => typedef char* const CPTR;

using CHARS = char*:
using CPTR = CHARS const; // constant pointer to chars
// => using CPTR = char* const;

```
The meaning of the second declaration is preseved when we textually replace CHARS with what it stands for;
How ever if you write `const` before the type it qualifies.
textually 
```cpp
typedef char* CHARS;
typedef const CHARS CTPR; //const pointer to chars;
// => typedef const char* CTPR // pointer to constant chars;
```
- footnote: note that `typedef` defines a "type alias" rather than a new type
```cpp
typedef int newInt;
int i = 29;
newInt j = 1999;
i = j; // OK
```

### 2. put the space between the `&` and the parameter name;
by doing this, we emphasize the separation between the parameter type and the parameter name.
```cpp
void foo (int const& x);
```
### 3. avoid declaring multiple entities in this way!.
:-1:
```cpp
char* a, b;
```
according to the rules inherited from C, `a` is a pointer but `b` is an ordinary `char`;
