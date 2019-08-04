# Stack 
> Element deleted from the set is the one most recently inserted;  
> Stack implements *last-in, first out* or *LIFO* policy  
> You can use array to implement Stack

## supported operations
insert, delete, empty, top, size

```cpp
template<typename T>
class Stack {
    public:
        struct Node {
            T val;
            Node *next;
            Node() {};
            Node(T val) : val(val), next(0){};
        };
        Node *head;
        int _size;
        Stack() {
            head = 0;
            _size = 0;
        }
        void push(T val) {
            Node* temp = new Node(val);
            if (head == 0) {
                head = temp;
            } else {
                temp->next = head;
                head = temp;
            }
            _size++;
        }
        void pop() {
            if (empty()) return;
            Node* temp = head;
            head = head->next;
            delete temp;
            _size--;
        }

        bool empty() const {
            return _size == 0;
        }
        T top() const {
            return head->val;
        }
        int size() const {
            return _size;
        }
};
```
