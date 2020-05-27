#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BSTNode.h"

#include <iostream>

template <typename T>

class BSTree
{
private:
    size_t count_;
    BSTNode<T>* root_;
    void Add(const T& data, BSTNode<T>* node) {
        if (data < node->data) {
            if(node->left) {
                Add(data, node->left);
            }
            else {
                node->left = new BSTNode<T>(data);
            }
        }
        if (data > node->data) {
            if (node->right) {
                Add(data, node->right);
            }
            else {
                node->right = new BSTNode<T>(data);
            }
        }
    }

    void Remove(const T& data, BSTNode<T>* node) {

        if (node->left) {
            if (node->left->data == data) {
                BSTNode<T>* to_delete = node->left;
                if (to_delete->left == nullptr && to_delete->right == nullptr) {
                    delete to_delete;
                    node->left = nullptr;
                    --count_;
                    return;
                }
                if (to_delete->left == nullptr) {
                    node->left = to_delete->right;
                    delete to_delete;
                    --count_;
                    return;
                }
                if (to_delete->right == nullptr) {
                    node->left = to_delete->left;
                    delete to_delete;
                    --count_;
                    return;
                }
                BSTNode<T>* biggest_element = to_delete->left;
                while (biggest_element->right) {
                    biggest_element = biggest_element->right;
                }
                ++count_;
                biggest_element = new BSTNode<T>(biggest_element->data);
                remove(biggest_element->data);
                biggest_element->left = to_delete->left;
                biggest_element->right = to_delete->right;
                node->left = biggest_element;
                delete to_delete;
                --count_;
                return;
            }
        }
        if (node->right) {
            if (node->right->data == data) {
                BSTNode<T>* to_delete = node->right;
                if (to_delete->left == nullptr && to_delete->right == nullptr) {
                    delete to_delete;
                    node->right = nullptr;
                    --count_;
                    return;
                }
                if (to_delete->left == nullptr) {
                    node->right = to_delete->right;
                    delete to_delete;
                    --count_;
                    return;
                }
                if (to_delete->right == nullptr) {
                    node->right = to_delete->left;
                    delete to_delete;
                    --count_;
                    return;
                }
                BSTNode<T>* biggest_element = to_delete->left;
                while (biggest_element->right) {
                    biggest_element = biggest_element->right;
                }
                ++count_;
                biggest_element = new BSTNode<T>(biggest_element->data);
                remove(biggest_element->data);
                biggest_element->left = to_delete->left;
                biggest_element->right = to_delete->right;

                node->right = biggest_element;
                delete to_delete;
                --count_;
                return;
            }
        }
        if (data < node->data) {
            if (node->left) {
                Remove(data, node->left);
            }
        }
        if (data > node->data) {
            if (node->right) {
                Remove(data, node->right);
            }
        }
    }

    bool Search(const T& data, BSTNode<T>* node) const{
        if (data == node->data) {
            return true;
        }
        if (data < node->data) {
            if (node->left) {
                return Search(data, node->left);
            }
        }
        if (data > node->data) {
            if (node->right) {
                return Search(data, node->right);
            }
        }
    }

public:

    BSTree() {
        count_ = 0;
        root_ = nullptr;
    }

    void add(const T& data) {
        if (root_) {
            Add(data, root_);
        }
        else {
            root_ = new BSTNode<T>(data);
        }
        ++count_;
    }

    void remove(const T& data) {
        if (root_->data == data) {
            if (root_->left == nullptr && root_->right == nullptr) {
                delete root_;
                root_ = nullptr;
                --count_;
                return;
            }
            if (root_->left == nullptr) {
                BSTNode<T>* new_root = root_->right;
                delete root_;
                root_ = new_root;
                --count_;
                return;
            }
            if (root_->right == nullptr) {
                BSTNode<T>* new_root = root_->left;
                delete root_;
                root_ = new_root;
                --count_;
                return;
            }
            BSTNode<T>* biggest_element = root_->left;
            while (biggest_element->right) {
                biggest_element = biggest_element->right;
            }
            ++count_;
            biggest_element = new BSTNode<T>(biggest_element->data);
            remove(biggest_element->data);
            biggest_element->left = root_->left;
            biggest_element->right = root_->right;
            delete root_;
            --count_;
            root_ = biggest_element;
            return;
        }
        else {
            Remove(data, root_);
        }
    }
    void removeAll() {
        while (root_) {
            remove(root_->data);
        }
    }
    bool search(const T& data) const { return root_ ?  Search(data, root_) : false; }
    const size_t& size() const { return count_; }
};

#endif // BINARYTREE_H
