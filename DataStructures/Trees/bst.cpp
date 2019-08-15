/** File              : bst.cpp
 * Author            : JCHRYS <jchrys@me.com>
 * Date              : 14.08.2019
 * Last Modified Date: 15.08.2019
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

    Set(): root(0), _size(0) { //default constructor
    }

    void insert(T key) {
        _insert(new Node(key)); //insert a key in to set (helper function)
    }

    void _insert(Node* &&node) { // 
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

    Node* _minimum(Node* x) {
        while (x->left != 0) {
            x = x -> left;
        }
        return x;
    }

    Node* maximum() { //returns Node* that with maximum key
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
    void transplant(Node* u, Node* v) {
        if (u->parent == 0) {
            this->root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != 0) {
            v->parent = u->parent;
        }
    }

    void erase(T key) {
        _erase(find(key)); 
    }

    void _erase(Node* target) {
        if (target == 0) return;
        if (target->left == 0) 
            transplant(target, target->right);
        else if (target->right == 0)
            transplant(target, target->left);
        else {
            Node* y = _minimum(target->right);
            if (y->parent != target) {
                transplant(y, y->right);
                y->right = target->right;
                y->right->parent = y;
            }
            transplant(target, y);
            y->left = target->left;
            y->left->parent = y;
        }
        delete target;
        _size--;
    }

    unsigned int height(Node* node) {
        if (node == 0)
            return 0;
        unsigned int lDepth = height(node->left);
        unsigned int rDepth = height(node->right);

        if (lDepth > rDepth)
            return lDepth + 1;
        return rDepth +1;
    }
    unsigned int tree_height() {
        return height(this->root);
    }
};



int main() {
    Set<int> s;
    // if input's are random;
    cout << "Naive Binary Search Tree implementation" << endl;
    cout << "-------BEST-CASE(random inputs)--------" << endl;
    cout << "input: 10,000 random integers" << endl;
    for (int i = 0; i < 10000; i++) {
        s.insert(rand()%1000000);
    }
    cout << "-----------------results----------------" << endl;
    cout << "tree_height: " << s.tree_height() << endl;
    cout << endl << endl <<endl;
    cout << "------WORST-CASE(sorted_inputs)---------" << endl;
    cout << "input: [1, 2, 3, ..., 10000]" << endl;
    Set<int> worst;
    for (int i = 1; i <= 10000; i++) {
        worst.insert(i);
    }
    cout << "-----------------results----------------" << endl;
    cout << "tree_height: " << worst.tree_height() <<endl;
    return 0;
}
