/**
 * File              : binarysearchtree.cpp
 * Author            : JCHRYS <jchrys@me.com>
 * Date              : 14.08.2019
 * Last Modified Date: 14.08.2019
 * Last Modified By  : JCHRYS <jchrys@me.com>
 */


#include <iostream>
using namespace std;

template<typename T>
class Set{
    struct Node {
        T key;
        Node* parent;
        Node* left;
        Node* right;
        Node(T key) {
            this->key = key;
            this->parent = 0;
            this->left = 0;
            this->right = 0;
        }
    };
    Node* root;
    unsigned int _size;
    public:
    Set(): root(0), _size(0) {
    }

    void insert(T key) {
        _insert(new Node(key));
    }

    void _insert(Node* &&node) {
        Node* y = 0;
        Node* x = this->root;
        while (x != 0) {
            y = x;
            if (node->key < x->key) {
                x = x->left;
            } else if (node->key == x->key) {
                return;
            } else {
                x = x->right;
            }
        }
        node->parent = y;
        if (y == 0)  // when tree is empty -> you could check with _size;
            this->root = node;
        else if(node->key < y->key) {
            y->left = node;
            node->parent = y;
        } else {
            y->right = node;
            node->parent = y;
        }
        this->_size++;
    }
    
    Node* find(T key) {
        Node* x = this->root;
        while (x != 0 && x->key != key) {
            if (x->key > key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        return x;
    }

    Node* minimum() {
        _minimum(this->root);
    }

    Node* _minimum(Node* &x) {
        while (x->left != 0) {
            x = x -> left;
        }
        return x;
    }

    Node* maximum() {
        return _maximum(this->root);

    }
    Node* _maximum(Node* &x) {
        while (x->right != 0) {
            x = x -> right;
        }
        return x;
    }
    
    Node* successor(Node* x) {
        if (x->right != 0) {
            return _minimum(x->right);
        }
        Node* y = x->parent;
        while (y != 0 && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    Node* predecessor(Node* x) {
        if (x->left != 0) {
            return _maximum(x->left);
        }
        Node* y = x->parent;
        while (y != 0 && x == y->left) {
            x = y;
            y = y->parent;
        }
        return y;
    }



    unsigned int size() {
        return _size;
    }



    void _inorder_tree_travel(Node*const &node) {
        if (node == 0) return;
        _inorder_tree_travel(node->left);
        cout << node->key << ' ';
        _inorder_tree_travel(node->right);
    }

    void inorder_tree_travel() {
        _inorder_tree_travel(this->root);
    }

};



int main() {
    Set<int> s;
    for (int i = 0; i < 1000; i++) {
        s.insert(rand()%100000);
    }
    s.inorder_tree_travel();
    cout << endl;
    cout << s.predecessor(s.find(97972))->key << endl;
    cout << s.successor(s.find(99505))->key << endl;
    return 0;
}
