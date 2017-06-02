#ifndef INCLUDE_RB_TREE_H_
#define INCLUDE_RB_TREE_H_

#include <stack>

#define BLACK 0
#define RED 1

using std::pair;
using std::stack;

template <typename T>
struct RB_node {
    T value;
    bool color;
    struct RB_node *left;
    struct RB_node *right;
    struct RB_node *parent;

    RB_node<T>(T v, bool c, RB_node<T>* l, RB_node<T>* r, RB_node<T>* p) {
        value = v;
        color = c;
        left = l;
        right = r;
        parent = p;
    }
};

extern RB_node<pair<int, int>> NIL_node;
#define NIL &NIL_node

template <typename T>
class RB_tree {
 private:
    void InsertFixup(RB_node<T> *x);
    void Rotate_Left(RB_node<T> *x);
    void Rotate_Right(RB_node<T> *x);
    void DeleteFixup(RB_node<T> *x);

 public:
    RB_node<T> *root;
    RB_tree();
    ~RB_tree();
    void Insert(T x);
    void Delete(T x);
    void Delete(RB_node<T> *x);
    void DeleteMin();
    RB_node<T>* Find(T x);
    T GetMin();

    bool IsEmpty() {
        if (root == reinterpret_cast<RB_node<T>*>(NIL) || root == nullptr)
            return true;
        else
            return false;
    }
};

template <typename T>
RB_tree<T>::RB_tree() {
    root = nullptr;
}

template <typename T>
RB_tree<T>::~RB_tree() {
    stack< RB_node <T>* > s;
    if (root != nullptr && root != reinterpret_cast<RB_node<T>*>(NIL)) {
        s.push(root);
    } else {
        if (root != reinterpret_cast<RB_node<T>*>(NIL))
            delete root;
    }
    while (!s.empty()) {
        RB_node<T>* node = s.top();
        s.pop();
        if (node->left != reinterpret_cast<RB_node<T>*>(NIL)) {
            s.push(node->left);
        }
        if (node->right != reinterpret_cast<RB_node<T>*>(NIL)) {
            s.push(node->right);
        }
        if (node != reinterpret_cast<RB_node<T>*>(NIL)) {
            delete node;
        }
    }
}

/******* INSERT *******/

template < typename T >
void RB_tree<T>::Insert(T key) {
    if (root == nullptr) {
        root = new RB_node<T>(key, BLACK, reinterpret_cast<RB_node<T>*>(NIL),
            reinterpret_cast<RB_node<T>*>(NIL), nullptr);
    } else {
        RB_node<T> *current = root;
        RB_node<T> *parent = nullptr;

        while (current != reinterpret_cast<RB_node<T>*>(NIL)) {
            parent = current;
            if (key < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        RB_node<T> *newnode = new RB_node<T>(key, RED, reinterpret_cast<RB_node<T>*>(NIL),
            reinterpret_cast<RB_node<T>*>(NIL), parent);
        if (parent == nullptr) {
            root = newnode;
        } else {
            if (newnode->value < parent->value) {
                parent->left = newnode;
            } else {
                parent->right = newnode;
            }
            InsertFixup(newnode);
        }
    }
}

/******* INSERT FIXUP *******/

template <typename T>
void RB_tree<T>::InsertFixup(RB_node<T> *x) {
    while (x != root && x->parent->color == RED && x->parent->parent != nullptr) {
        if (x->parent == x->parent->parent->left) {
            RB_node<T> *uncle = x->parent->parent->right;
            if (uncle->color == RED) {
                x->parent->color = uncle->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } else {
                if (x == x->parent->right) {
                    x = x->parent;
                    Rotate_Left(x);
                }
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                Rotate_Right(x->parent->parent);
            }
        } else {
            RB_node<T> *uncle = x->parent->parent->left;
            if (uncle->color == RED) {
                x->parent->color = uncle->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } else {
                if (x == x->parent->left) {
                    x = x->parent;
                    Rotate_Right(x);
                }
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                Rotate_Left(x->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

/******* TREE ROTATIONS *******/

template <typename T>
void RB_tree<T>::Rotate_Right(RB_node<T> *x) {
    RB_node<T> *y = x->left;
    x->left = y->right;
    if (y->right != reinterpret_cast<RB_node<T>*>(NIL)) {
        y->right->parent = x;
    }
    if (y != reinterpret_cast<RB_node<T>*>(NIL))
        y->parent = x->parent;
    if (x->parent != nullptr) {
        if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
    } else {
        root = y;
    }
    y->right = x;
    if (x != reinterpret_cast<RB_node<T>*>(NIL))
        x->parent = y;
}

template <typename T>
void RB_tree<T>::Rotate_Left(RB_node<T> *x) {
    RB_node<T> *y = x->right;
    x->right = y->left;
    if (y->left != reinterpret_cast<RB_node<T>*>(NIL))
        y->left->parent = x;
    if (y != reinterpret_cast<RB_node<T>*>(NIL))
        y->parent = x->parent;
    if (x->parent != nullptr) {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    } else {
        root = y;
    }
    y->left = x;
    if (x != reinterpret_cast<RB_node<T>*>(NIL))
        x->parent = y;
}

/******* DELETE(key) *******/

template < typename T >
void RB_tree<T>::Delete(T key) {
    if (root != nullptr) {
        RB_node<T> *x = Find(key);
        Delete(x);
    } else {
        throw 1;
    }
}

/******* DELETE MIN *******/

template < typename T >
void RB_tree<T>::DeleteMin() {
    RB_node<T>* rootcopy = root;
    if (rootcopy != nullptr) {
        while (rootcopy->left != reinterpret_cast<RB_node<T>*>(NIL))
            rootcopy = rootcopy->left;
        Delete(rootcopy);
    }
}

/******* DELETE(*node) *******/

template < typename T >
void RB_tree<T>::Delete(RB_node<T> *node) {
    if (root != nullptr) {
        RB_node<T> *x, *y;
        if (node == nullptr || node == reinterpret_cast<RB_node<T>*>(NIL))
            return;
        if (node->left == reinterpret_cast<RB_node<T>*>(NIL) ||
            node->right == reinterpret_cast<RB_node<T>*>(NIL)) {
            y = node;
        } else {
            y = node->right;
            while (y->left != reinterpret_cast<RB_node<T>*>(NIL)) {
                y = y->left;
            }
        }

        if (y->left != reinterpret_cast<RB_node<T>*>(NIL))
            x = y->left;
        else
            x = y->right;
        x->parent = y->parent;

        if (y->parent != nullptr) {
            if (y == y->parent->left)
                y->parent->left = x;
            else
                y->parent->right = x;

        } else {
            root = x;
        }

        if (y != node) {
            node->value = y->value;
        }

        if (y->color == BLACK) {
            DeleteFixup(x);
        }

        if (y == root)
            root = nullptr;
        else
            delete y;

    } else {
        throw 1;
    }
}

/******* DELETE FIXUP *******/

template < typename T >
void RB_tree<T>::DeleteFixup(RB_node<T>* x) {
    while (x != reinterpret_cast<RB_node<T>*>(NIL) && x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            RB_node<T> *brother = x->parent->right;
            if (brother->color == RED) {
                brother->color = BLACK;
                x->parent->color = RED;
                Rotate_Left(x->parent);
                brother = x->parent->right;
            }
            if (brother->left->color == BLACK && brother->right->color == BLACK) {
                brother->color = RED;
                x = x->parent;
            } else {
                if (brother->right->color == BLACK) {
                    brother->left->color = BLACK;
                    brother->color = RED;
                    Rotate_Right(brother);
                    brother = x->parent->right;
                }
                brother->color = x->parent->color;
                x->parent->color = BLACK;
                brother->right->color = BLACK;
                Rotate_Left(x->parent);
                x = root;
            }
        } else {
            RB_node<T> *brother = x->parent->left;
            if (brother != nullptr) {
                if (brother->color == RED) {
                    brother->color = BLACK;
                    x->parent->color = RED;
                    Rotate_Right(x->parent);
                    brother = x->parent->left;
                }
                if (brother->right->color == BLACK && brother->left->color == BLACK) {
                    brother->color = RED;
                    x = x->parent;
                } else {
                    if (brother->left->color == BLACK) {
                        brother->right->color = BLACK;
                        brother->color = RED;
                        Rotate_Left(brother);
                        brother = x->parent->left;
                    }
                    brother->color = x->parent->color;
                    x->parent->color = BLACK;
                    brother->left->color = RED;
                    Rotate_Right(x->parent);
                    x = root;
                }
            }
        }
    }
    x->color = BLACK;
}

/******* FIND *******/

template < typename T >
RB_node<T>* RB_tree<T>::Find(T key) {
    if (root != nullptr && root != reinterpret_cast<RB_node<T>*>(NIL)) {
        RB_node<T> *current = root;
        while (true) {
            if (current == reinterpret_cast<RB_node<T>*>(NIL))
                return nullptr;

            if (current->value == key)
                return current;

            if (key < current->value) {
                if (current->left != nullptr)
                    current = current->left;
            } else {
                if (current->right != nullptr)
                    current = current->right;
            }
        }
    } else {
        throw 1;
    }
}

/******* GET MIN *******/

template < typename T >
T RB_tree<T>::GetMin() {
    RB_node<T>* rootcopy = root;

    if (rootcopy != nullptr) {
        while (rootcopy->left != reinterpret_cast<RB_node<T>*>(NIL))
            rootcopy = rootcopy->left;
        return rootcopy->value;
    } else {
        throw 1;
    }
}

#endif  // INCLUDE_RB_TREE_H_
