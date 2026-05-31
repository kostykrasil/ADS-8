// Copyright 2023
#pragma once
#include <algorithm>

template<typename T>
class BST {
 public:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;

    explicit Node(T val) : value(val), count(1),
                           left(nullptr), right(nullptr) {}
  };

 private:
  Node* root;

  Node* insertNode(Node* node, T val) {
    if (node == nullptr) {
      return new Node(val);
    }
    if (val < node->value) {
      node->left = insertNode(node->left, val);
    } else if (val > node->value) {
      node->right = insertNode(node->right, val);
    } else {
      node->count++;
    }
    return node;
  }

  int depthNode(Node* node) {
    if (node == nullptr) {
      return -1; // Чтобы при прибавлении 1 для листьев получался 0
    }
    return 1 + std::max(depthNode(node->left), depthNode(node->right));
  }

  int searchNode(Node* node, T val) {
    if (node == nullptr) {
      return 0;
    }
    if (val == node->value) {
      return node->count;
    }
    if (val < node->value) {
      return searchNode(node->left, val);
    }
    return searchNode(node->right, val);
  }

  void destroyTree(Node* node) {
    if (node != nullptr) {
      destroyTree(node->left);
      destroyTree(node->right);
      delete node;
    }
  }

 public:
  BST() : root(nullptr) {}
  ~BST() { destroyTree(root); }

  void insert(T val) { root = insertNode(root, val); }

  int depth() {
    if (root == nullptr) return 0;
    return depthNode(root);
  }

  int search(T val) { return searchNode(root, val); }

  Node* getRoot() const { return root; }
};
