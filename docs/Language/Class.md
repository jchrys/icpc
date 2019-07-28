# Class
> C++ classes are a tool for creating new types that can be used conveniently  as builtin types
> The Fundamental idea in defining a new type is to separate the details of the implementation from the properties essential to the correc use of it


### Brief Summary of classes
- A class is user-defined type
- A class consists of a set of members. The most common kinds of members are data members and member functions.
- Member functions can define the meaning of initialization, copy, move, and cleanup
- Members are accessed using `.`(dot) for objects and `->` (arrow) for pointers.
- Operators, such as, `+`, `!`, and `[]`, can be defined for a class
- A class is a namespace containing its members
- The `public` members provide the class's interface and the `private` members provide implementation details
- A `struct` is a `class` where members are by default `public`



## Class Basics
### class example
```cpp
class X {
    private: // the representation (implementation) is private
        int m;
    public: // the user interface is public
        X(int i = 0): m{i} {} //a constructor (initialize the data member m)

        int mf(int i) { // a member function
            int old = m;
            m = i; //set a new value
            return old; // return the old value
        }
};
X var {7}; // a variable of type X, initialized to 7
int user(X var, X* ptr) {
    int x = var.mf(7); // access using .
    int y = ptr->mf(9); // access using ->
    int z = var.m; // error: cannot acces private member
}
```

### 1. Member functions
> Functions declared within a class definition are called *member functions*

### 2. Default copying
> a class object can be initialized with a copy of an obejct of its class
```cpp
UserClass c1 = c0; // initialization by copy
UserClass c2 {d1}; // initialization by copy
```

### 3. Access Control
> class is consist of two parts
> `private` part: can be used only by *member functions*, `public` part : interface to objects of class

### 4. `class` and `struct`
> a `struct` is a class in which members are by default `public`
> `struct S{};` is simply short hand for `class S{public: };`


### 5. Constructors
> a `constructor` is recognized by having the same name as the class it self.
> programmers can declare a function with the explicit purpose of initializing objects.
```cpp
class Date {
    int d, m, y;
    public:
    Date(int dd, int mm, int yy); // constructor
}

Date today = Date(23, 6, 1983); // OK
Date xmas(25, 12, 1990); // OK -> abbreviated form
Date my_birthday; //error: initializer missing
Date release1_0(10, 12) //error: third argument missing

Date today = Date{23, 6, 1982} // good!
```
I recommend the `{}` notation over the () notation for initializing, because it is explicit about what is being done

> we could use default values directly as default arguments
```cpp
class Date {
    int d, m, y;
    public:
    Date(int dd = today.d, int mm = today.m, int yy = today.y); // constructor
}
```



