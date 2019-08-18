title: Red Black Tree
hero: Red Black Tree
description: RedBlackTree implementation
author: jchrys
path: blob/master/docs/DataStructures/Trees
source: RedBlackTree.cpp

# Red Black Tree
> Red Black Tree is *balanced* binary search tree with one extra bit of storage per node: color
> Red Black Tree satisfies the Red-Black-Properties  

!!!note "Red-Black-Properties"
    1. Every node is black or red
    2. The root is black
    3. Every leaf(NIL) is black
    4. if a node is red, then both its children are black
    5. For each node, all simple paths from the node to descendant leaves contains the same number of black nodes.


## Operations & time complexity
> $N$ = number of elements in Tree 


|  Member Function  |  Running Time |
|:-----------------:|:-------------:|
|      insert()     | $\Omicron(\lg(N))$ |
|      erase()      | $\Omicron(\lg(N))$ |
| inorder_tree_walk |  $\Theta(N)$  |
|       find()      | $\Omicron(\lg(N))$ |
|     minimum()     | $\Omicron(\lg(N))$ |
|     maximum()     | $\Omicron(\lg(N))$ |
|    successor()    | $\Omicron(\lg(N))$ |
|   predecessor()   | $\Omicron(\lg(N))$ |

!!!note
    Red Black Tree is Balanced Binary Search Tree  
    It is guaranteed that height of the tree is $\Omicron(\lg(N))$ in worst case


## Implementation

```cpp

#include <bits/stdc++.h>
using namespace std;


template<typename K, typename V>
class Map {
    struct Node {
        K key;
        V val;
        bool color; // 0: red, 1:black
        Node* p;
        Node* left;
        Node* right;
        Node(Map &out):
            key(), val(), color(1),
            p(out.NIL), left(out.NIL), right(out.NIL){}
        Node(Map &out, K key, V val): 
            key(key), val(val), color(0),
            p(out.NIL), left(out.NIL), right(out.NIL){}
    };
    Node* root;
    void left_rotate(Node* x) {
        Node* y = x->right; // y is x's right child
        x->right = y->left; // set y's left child to x's right child;
        x->right->p = x;    // set parent
        y->p = x->p;        
                                    //set x's parent pointing to y;
        if (x->p == NIL) {    // if x is root 
            this->root = y;
        } else if(x == x->p->left) { //if x is left child
            x->p->left = y;
        } else {
            x->p->right = y;
        }
        x->p = y;               // y is x's parent
        y->left = x;            // x is y's left child
    }

    void right_rotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        x->left->p = x;
        y->p = x->p;
        if (x->p == NIL) {
            this->root = y;
        } else if(x == x->p->left) {
            x->p->left = y;
        } else {
            x->p->right = y;
        }
        x->p = y;
        y->right = x;
    }

    void transplant(Node* u, Node* v) {
        // gives u's parent relations to v
        if (u->p == NIL) {
            root = v;
        } else if (u == u->p->right) {
            u->p->right = v;
        } else {
            u->p->left = v;
        }
        v->p = u->p; // unconditionally because NIL can have parent also;
    }

    public:
    Node* NIL;
    Map() {
        NIL = new Node(*this);
        root = NIL;
    }

    void insert_fixup(Node* &z) {
        while (z->p->color == 0) {
            Node* y; // z's uncle
            if (z->p == z->p->p->left) { // when z's parent is left child
                y = z->p->p->right;  
                if (y->color == 0) { // if uncle is red, uncles parent should be black
                    z->p->color = 1; // recoloring and goes up
                    y->color = 1;
                    z->p->p->color = 0;
                    z = z->p->p;
                } else {
                    if (z == z->p->right) { // if uncle is black and z is right child
                        z = z->p;
                        left_rotate(z);
                    }                       // if uncle is black and z is right child
                    z->p->color = 1;
                    z->p->p->color = 0;
                    right_rotate(z->p->p);
                }
            } else { // when z's parent is right child
                y = z->p->p->left; 
                if (y->color == 0) {
                    z->p->color = 1;
                    y->color = 1;
                    z->p->p->color = 0;
                    z = z->p->p;
                } else { // if uncle's color is black
                    if (z == z->p->left) { //when z is right child
                        z = z->p;
                        right_rotate(z);
                    }
                    z->p->color = 1;
                    z->p->p->color = 0;
                    left_rotate(z->p->p);
                }
            }
        }
        this->root->color = 1;
    }

    void insert(K key, V val) {
        Node* z = new Node(*this, key, val);  
        Node* y = NIL;
        Node* x = this->root;
        while (x != NIL) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x= x->right;
            }
        }
        z->p = y;
        if (y == NIL) {
            this->root = z;
        } else if (z->key < y->key) {
            y->left = z; 
        } else {
            y->right = z;
        }
        // z->left = NIL;
        // z->right = ZIL;
        // z->color = 0;
        insert_fixup(z); 
    }

    
    Node* find(K key) {
        Node* x = root;
        while (x!= NIL && x->key != key) {
            if (key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        } 
        return x;
    }
    
    
    Node* minimum(Node* x) {
        while (x->left != NIL) {
            x = x->left;
        }
        return x;
    }


    void erase_fixup(Node* x) {
        Node * w; // sibling of x;
        while (x != this->root && x->color == 1) { //only if x is black and not root
            if (x == x->p->left) {
                w = x->p->right; 
                if (w->color == 0) { // turns to case2, 3 or 4;
                    w->color = 1;
                    x->p->color = 0;
                    left_rotate(x->p);
                    w = x->p->right;
                }
                
                if (w->left->color == 1 && w->right->color == 1) { // case2
                    w->color = 0;
                    x = x->p;
                } else {
                    if (w->right->color == 1) { //case3 -> turns to case4
                        w->left->color = 1;
                        w->color = 0;
                        right_rotate(w);
                        w = x->p->right;
                    }
                    w->color = x->p->color; // case4 -> we can make legit red-black tree
                    x->p->color = 1;
                    w->right->color = 1;
                    left_rotate(x->p);
                    x = root;
                }
            } else { // x == x->p->right
                w = x->p->left;
                if (w->color == 0) {
                    w->color = 1;
                    x->p->color = 0;
                    right_rotate(x->p);
                    w = x->p->left;
                }
                if (w->left->color == 1 && w->right->color == 1) {
                    w->color = 0;
                    x = x->p;
                } else {
                    if (w->left->color == 1) {
                        w->color = 0;
                        w->right->color = 1;
                        left_rotate(w);
                        w = x->p->left;
                    }
                    w->color = w->p->color;
                    w->p->color = 1;
                    w->left->color = 1;
                    right_rotate(x->p);
                    x = root;
                }
            }
        }
        x->color = 1;
    }

    void erase(Node* z) {
        Node* y = z;
        bool y_original_color = y->color;
        Node* x;

        if (z->left == NIL) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == NIL) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->p == z) {
                x->p = y; // incase of x is NIL!! we need to find it's parent!
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->p = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->p = y;
            y->color = z->color;
        }
        if (y_original_color == 1) {
            erase_fixup(x);
        }
    }



    void rb_printer(Node* node, int indent) {
        //prints red & black tree
        int count = 4;
        if (node == NIL) return;
        indent += count;
        rb_printer(node->right, indent);
        cout << endl;
        for (int i = count; i < indent; i++) {
            cout << " ";
        }
        cout << (node->color == 0 ? "\033[1;31m":"") << (node == node->p->left ? "l":"r") << node->key << (node->color == 0 ? "\033[0m":"") << endl;
        rb_printer(node->left, indent);
    }
    void print() {
        rb_printer(this->root, 0);
    }

};

int main() {
    Map<int, int> m;
    for (int i = 0; i < 20; i++) {
        m.insert(rand()%20, 1);
    }
    m.print();

    cout << "deleting ---" << endl;;
    for (int i = 0; i < 20; i++) {
        int key = rand()%20;
        auto it = m.find(key);
        cout << "delete: " << key << endl;
        if (it != m.NIL) {
            cout << "key exist... deleting...";
            m.erase(it);
            m.print();
        } else {
            cout << "key not exist" << endl;
        }
    }
    

    return 0;
}

```

## Related Problems
1. NOT ADDED YET :star: [:link:](https://codeforces.com/problemset/problem/1199/A)

## Related Topics
[BinarySearchTree](https://icpc.ninja)

## Analysis (Optional)
You can add some mathematical things here using [KaTex](https://katex.org/docs/supported.html)

as a block tag
$$
    T(N) = O(N*M)
$$

or as a inline tag $T(N) = O(N) $

### Contributers (Optional)
08.18.2019 :tada: [JCHRYS](https://github.com/jchrys)  
