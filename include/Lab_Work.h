#ifndef INCLUDE_LAB_WORK_H_
#define INCLUDE_LAB_WORK_H_

#include <stdio.h>
#include <iostream>

#define RED 0
#define BLACK 1

using std::cin;
using std::cout;
using std::pair;

template <typename T>
struct RB_node {
    int value;
    bool color;
    struct RB_node *left;
    struct RB_node *right;
    struct RB_node *parent;

    RB_node<T>(T v, bool c, RB_node<T>* l, RB_node<T>* r, RB_node<T>* p) {
        value = v;
        color = c;
        left = l;
        right = r;
        parent = a;
    }
};

extern RB_node<pair<int, int>> NILnode;
#define NIL &NILnode

template <typename T>
class RB_tree {
private:
    void Rotate_Left(RB_node<T> *x);
    void Rotate_Right(RB_node<T> *x);
    void InsertFixup(RB_node<T> *x);
    void DeleteFixup(RB_node<T> *x);

public:
    RB_node<T>* root;
    RB_tree();
    ~RB_tree();
    void InsertNode(RB_node<T> *x);
    void DeleteNode(RB_node<T> *x);
};

template <typename T>
RB_tree<T>::RB_tree() {
    root = nullptr;
}

/*template <typename T>
RB_tree<T>::~RB_tree() {
    stack< RB_node <T>* > a;
    if (root != nullptr && root != reinterpret_cast<RB_node<T>*>(NIL)) {
        a.push(root);
    } else {
        if (root != reinterpret_cast<RB_node<T>*>(NIL))
            delete root;
    }
    while (!a.empty()) {
        RB_node<T>* node = a.top();
        a.pop();
        if (node->left != reinterpret_cast<RB_node<T>*>(NIL)) {
            a.push(node->left);
        }
        if (node->right != reinterpret_cast<RB_node<T>*>(NIL)) {
            a.push(node->right);
        }
        if (node != reinterpret_cast<RB_node<T>*>(NIL)) {
            delete node;
        }
    }
}*/

/******* Tree Rotations *******/

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

/******* Insert FixUp *******/

template < typename T >
void RB_tree<T>::InsertFixup(RB_node<T> *x) {

    while (x != root && x->parent->color == 1 && x->parent->parent != nullptr) {
        if (x->parent == x->parent->parent->left) {
            RB_node<T> *uncle = x->parent->parent->right;
            if (uncle->color == 1) {
                x->parent->color = uncle->color = 0;
                x->parent->parent->color = 1;
                x = x->parent->parent;

            } else {

                if (x == x->parent->right) {
                    x = x->parent;
                    Rotate_Left(x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                Rotate_Right(x->parent->parent);
            }

        } else {

            RB_node<T> *uncle = x->parent->parent->left;
            if (uncle->color == 1) {
                x->parent->color = uncle->color = 0;
                x->parent->parent->color = 1;
                x = x->parent->parent;

            } else {

                if (x == x->parent->left) {
                    x = x->parent;
                    Rotate_Right(x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                Rotate_Left(x->parent->parent);
            }
        }
    }
    root->color = 0;
}

/******* Delete FixUp *******/

template < typename T >
void RB_tree<T>::DeleteFixup(RB_node<T>* x) {

    while (x != reinterpret_cast<RB_node<T>*>(NIL) && x != root && x->color == 0) {
        if (x == x->parent->left) {
            RB_node<T> *brother = x->parent->right;
            if (brother->color == 1) {
                brother->color = 0;
                x->parent->color = 1;
                Rotate_Left(x->parent);
                brother = x->parent->right;
            }

            if (brother->left->color == 0 && brother->right->color == 0) {
                brother->color = 1;
                x = x->parent;
            } else {

                if (brother->right->color == 0) {
                    brother->left->color = 0;
                    brother->color = 1;
                    Rotate_Right(brother);
                    brother = x->parent->right;
                }

                brother->color = x->parent->color;
                x->parent->color = 0;
                brother->right->color = 0;
                Rotate_Left(x->parent);
                x = root;
            }

        } else {

            RB_node<T> *brother = x->parent->left;
            if (brother != nullptr) {
                if (brother->color == 1) {
                    brother->color = 0;
                    x->parent->color = 1;
                    Rotate_Right(x->parent);
                    brother = x->parent->left;
                }

                if (brother->right->color == 0 && brother->left->color == 0) {
                    brother->color = 1;
                    x = x->parent;

                } else {

                    if (brother->left->color == 0) {
                        brother->right->color = 0;
                        brother->color = 1;
                        Rotate_Left(brother);
                        brother = x->parent->left;
                    }

                    brother->color = x->parent->color;
                    x->parent->color = 0;
                    brother->left->color = 1;
                    Rotate_Right(x->parent);
                    x = root;
                }
            }
        }
    }
    x->color = 0;
}

/******* Insert FixUp *******/



/******* Insert FixUp *******/

#endif  // INCLUDE_LAB_WORK_H_
