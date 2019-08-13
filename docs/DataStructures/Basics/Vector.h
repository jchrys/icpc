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
