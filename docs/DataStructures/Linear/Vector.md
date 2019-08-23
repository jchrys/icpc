# Vector
> Vector is Dynamic array structure in c++

## Operations & time complexity

| Member Function |  Running Time  |
|:---------------:|:--------------:|
|   push_back()   |$O(1) amortized$|
|    pop_back()   |     $O(1)$     |
|     empty()     |     $O(1)$     |
|    reserve()    |     $O(n)$     |
|   operator []   |     $O(1)$     |


## Implementation

```cpp   

using size_t = unsigned long;

template<typename T>
class Vector {
    size_t _size;
    size_t _capacity;
    T* _buf;
    public:
    // constructors
    
    // Vector(SomeType); //"ordinary constructor"
    Vector(int k) {
       _size = k;
       _capacity = k;
       _buf = new T[_capacity];
    }
    // Vector(); //default constructor
    Vector() {
        _size = 0;
        _capacity = 0;
        _buf = new T[_capacity];
    }
    // Vector(const &X); // copy constructor
    // Vector(&&X); //move constructor
    // &Vector operator=(const Vector&); //copy assignment: cleanup target and copy
    // &Vector operator=(Vector&&); // move assignment: cleanup target and move
    //~Vector(); //destructor: cleanup
    ~Vector() {
        delete[] _buf;
    }
    
    // capacity: 
    size_t size() {
        return _size;
    }

    void resize(size_t n) {
        _size = n;
    }
    
    size_t capacity() {
        return _capacity;
    };
    bool empty() {
        return _size == 0;
    };
    // unsigned int max_size();
    void reserve(size_t n) {
        //Requests that the vector capacity be at least enough to contain n elements.
        if (_size >= n) return;
        T* _temp = new T[n];
        
        for (size_t i = 0; i < _size; i++) {
            _temp[i] = _buf[i];
        }
        _capacity = n;
        delete[] _buf;
        _buf = _temp;
    }
    // shrink_to_fit()
   

    //element access:
    T back();
    // operator[]()
    T& operator[](int idx) {
        return _buf[idx];
    }
    T operator[](int idx) const{
        return _buf[idx];
    }
    // at()
    // front()
    // data() 

    //Modifiers
    void clear() {
        resize(0);
    };
    void push_back(T const &val) {
        if (_size == _capacity) {
            if (_capacity) {
            reserve(_capacity << 1);
            } else {
                reserve(1);
            }
        }
        _buf[_size++] = val;
    };
    void pop_back() {
        _size--;
    };
    // assign()
    // insert()
    // erase()
    // emplace()
    // emplace_back
   
    
    //Iterators 
    T* begin() {
        return &_buf[0];
    }
    T* end() {
        return &_buf[0] + _size;
    };
    //T* rbegin();
    //T* rend();
    //T* const cbegin();
    //T* const cend();
    //T* const crbegin();
    //T* const crend();
};
```

## Related Problems
1. Letters Shop :star::star: [:link:](https://codeforces.com/problemset/problem/1187/B)


## Related Topics
[Stack](/DataStructures/Linear/Stack)

## Analysis (Later..)
You can add some mathematical things here using [KaTex](https://katex.org/docs/supported.html)

as a block tag
$$
    T(N) = O(N*M)
$$

or as a inline tag $T(N) = O(N) $

### Contributers
08.13.2019 :tada: [jchrys](https://github.com/jchrys)  
