/**
 * File              : heap.cpp
 * Author            : JCHRYS <jchrys@me.com>
 * Date              : 23.08.2019
 * Last Modified Date: 23.08.2019
 * Last Modified By  : JCHRYS <jchrys@me.com>
 */
#include <iostream>
using namespace std;

template<typename T>
void _swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
class heap {
    int _size;
    int _capacity;
    T* _buf;
    inline int parent(int i) {
        return (i - 1) >> 1;
    }
    inline int left(int i) {
        return (i << 1) + 1;
    }
    inline int right(int i) {
        return (i << 1) + 2;
    }

    void max_heapify(int i) {
        int largest;
        int l = left(i);
        int r = right(i);
        if (l < _size && _buf[l] > _buf[i]) {
            largest = l;
        } else {
            largest = i;
        }
        if (r < _size && _buf[r] > _buf[largest]) {
            largest = r;
        }
        if (largest != i) {
            _swap(_buf[largest], _buf[i]);
            max_heapify(largest);
        }
    }

    void reserve(int n) {
        if (n <= _size) return;
        T* temp = new T[n];
        for (int i = 0; i < _size; i++) {
            temp[i] = _buf[i];
        }
        _capacity = n;
        delete[] _buf;
        _buf = temp;
    }
    public:
    heap(): _size(0), _capacity(0), _buf(0){}
    heap(int n) {
        _size = n;
        _capacity = n;
        _buf = new T[n];
        for (int i = 0; i < n; i++) {
            _buf[i] = rand()%400;
        }
    }

    void build_max_heap() {
        for (int i = parent(_size -1); i >= 0; i--) 
            max_heapify(i);
    }
    void heapsort() {
        build_max_heap();
        int original_size = _size;
        for (int i = _size-1; i > 0; i--) {
            swap(_buf[0], _buf[i]);
            _size--; 
            max_heapify(0);
        }
        _size = original_size;
    }

    // priority queue;
    T maximum() {
        return _buf[0];
    }
    T extract_max() {
        if (_size == 0) {
            cout << "underflow";
            return -1;
        }
        int max = _buf[0];
        _buf[0] = _buf[--_size];
        max_heapify(0);
        return max;
    }
    
    void increase_key(int i, T key) {
        if (key < _buf[i]) {
            cout << "new key is smaller than current key" << endl;
            return;
        }
        _buf[i] = key;
        while(i > 0 && _buf[parent(i)] < _buf[i]) {
            _swap(_buf[i], _buf[parent(i)]);
            i = parent(i);
        }
    }

    void insert(T key) {
        if (_size == 0) {
            reserve(1);
        }
        else if (_size == _capacity) {
            reserve(_size << 1);
        } 
        _buf[_size] = key-1;
        increase_key(_size++, key);
    }



    void print() {
        for (int i = 0; i < _size; i++) {
            cout << _buf[i] << ' ';
        }
        cout << endl;
    }
};

int main() {
    heap<int> q(30); // make random heap;
    cout << "================= random ===============" << endl;
    q.print();
    cout << "========== after build-max-heap=========" << endl;
    q.build_max_heap();
    q.print();
    cout << "============ after heapsort ============" << endl;
    q.heapsort(); 
    q.print();
    cout << "============ priority queue ===========" << endl;
    heap<int> pq;
    for (int i = 0; i < 1000; i++) {
        pq.insert(rand()%100);
    }
    for (int i = 0; i < 1000; i++) {
        cout << pq.extract_max() << ' ';
    }
    //pq.print();
    return 0;
}
