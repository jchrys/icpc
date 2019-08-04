template<typename T>
class Vector {
    public:
        int _size;
        int capacity;
        T *arr;
        Vector() {
            _size = 0;
            capacity = 32;
            arr = new T[capacity];
        }
        Vector(int k) {
            _size = k;
            capacity = k;
            arr = new T[capacity];
        }
        ~Vector() {
            delete[] arr;
        }

        void clear() {
            delete[] arr;
            _size = 0;
            capacity = 32;
            arr = new T[capacity];
        }
        void resize(int k) { //TODO smaller!
            T *temp;
            temp = new T[k];
            for (int i = 0; i < _size; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
            capacity = k;
            _size = (_size < capacity ? _size: capacity); 
        }

        int size() const {
            return _size;
        }
        T* begin() const {
            return &arr[0];
        }
        T* end() const {
            return &arr[0] + _size;
        }

        void push_back(T val) {
            if (_size == capacity) {
                resize(_size*2);
            }
            arr[_size++] = val;
        }

        void pop_back() {
            _size--;
        }

        T& operator[](int index) {
            return arr[index];
        }

        T operator [] (int index) const {
            return arr[index];
        }
};
