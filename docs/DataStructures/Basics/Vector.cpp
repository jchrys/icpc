template<typename T>
class Vector {
    unsigned int _size;
    unsigned int _capacity;
    T* _buf;
    public:
    // capacity: 
    unsigned int size() {
        return _size;
    }

    void resize(unsigned int size) {
        //TODO
        _size = size;
    }

    unsigned int capacity();
    bool empty();
    // unsigned int max_size();
    // reverse()
    // shrink_to_fit()
   

    //element access:
    T back();
    // operator[]()
    // at()
    // front()
    // data()
   

    //Modifiers
    void clear();
    void push_back(T val);
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
