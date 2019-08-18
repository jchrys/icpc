/**
 * File              : LinkedList.cpp
 * Author            : JCHRYS <jchrys@me.com>
 * Date              : 15.08.2019
 * Last Modified Date: 15.08.2019
 * Last Modified By  : JCHRYS <jchrys@me.com>
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class LinkedList{
    struct Node {
        Node* before;
        Node* next;
        T data;
        Node(T data): before(0), next(0), data(data){} 
        ~Node() {
            delete before;
            delete next;
            delete data;
        } 
    };
    Node* tail;
    unsigned int _size;
    public:
    Node* head;
    LinkedList(): head(0), tail(0) {}
    void insert_front(T val) {
            Node* temp = new Node(val);
        if (head == 0) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head->before = temp;
            head = temp;
        }
    }
    void insert_back(T val) {
        Node* temp = new Node(val);
        if (tail == 0) {
            head = temp;
            tail = temp;
        } else {
            temp->before = tail;
            tail->next = temp;
            tail = temp;
        }
    }
    void insert_after(Node* node, T val) {
        Node* temp = new Node(val);
        if (temp->next == 0) {
            tail = temp;
        }
        temp->next = node->next;
        temp->next->before = temp;
        node->next = temp;
        temp->before = node;
    }
    Node* search(T val) { //search_from head
        Node* it = head;
        while (it != 0 && it->data != val)
            it = it->next;
        return it;
    }
    void erase(Node* node) {
        if (node == 0) return;
        if (node->next == 0) {
            tail = node->before;
            tail->next = 0;
        } else if (node->before == 0) {
            head = node->next;
            head->before = 0;
        } else {
            node->before->next = node->next;
            node->next = node->before;
        }
        delete node;
    }
    void print() {
        Node* it = head;
        while (it != 0) {
            cout << it->data << ' ';
            it = it->next;
        }
    }
};

int main() {
    LinkedList<int> list;
    for (int i = 0; i < 100; i++) {
        list.insert_front(i);
    }
    for (int i = 0; i < 100; i++) {
        list.insert_back(i);
    }
    for (int i = 0; i < 100; i++) {
        list.insert_after(list.head->next, i);
    }
    list.print();

    return 0;
}
