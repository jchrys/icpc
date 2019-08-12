using size_t = unsigned int;

template<typename T>
class Vector {
    size_t _size;
    size_t _capacity;
    T* _buf;
    public:
    // constructors
    // TODO 
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
    // at()
    // front()
    // data() 

    //Modifiers
    void clear() {
        resize(0);
    };
    void push_back(T const &val) {
        if (_size == _capacity) {
            reserve(_capacity << 1);
        }
        _buf[_size++] = val;
    };
    void pop_back();
    // assign()
    // insert()
    // erase()
    // emplace()
    // emplace_back
   
    
    //Iterators 
    T* begin();
    T* end();
    //T* rbegin();
    //T* rend();
    //T* const cbegin();
    //T* const cend();
    //T* const crbegin();
    //T* const crend();
};
