//
//  BinarySearchInt.h
//  BinaryIntegerSearchTree
//
//  Created by Baris Kasikci on 15/12/13.
//  Copyright (c) 2013 Baris Kasikci. All rights reserved.
//
//  Since C++ does not have a tree, I roll my own
//

#ifndef __BinaryIntegerSearchTree__BinarySearchInt__
#define __BinaryIntegerSearchTree__BinarySearchInt__

#include <iostream>
#include <stack>

class BinaryIntSearchTree {
public:
    BinaryIntSearchTree() { root = NULL; }
    // The root needs to be empty for an empty tree
    bool isEmpty() const { return root==NULL; }
    bool contains(int value) const;
    // Iterative version of the contains method
    bool containsIter(int value) const;
    bool containsBruteForce(int value) const;
    void insert(int value);
    void remove(int value);
    bool isBalanced() const;
    // print functions
    void printPreOrder() const;
    void printInOrder() const;
    void printPostOrder() const;
    void printLevelOrder() const;
    
private:
    // Nobody needs to know that we are maintaining this Node abstraction
    struct TreeNode {
        TreeNode(int _value) {value = _value;}
        int value;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;
    
    void printPreOrder(const TreeNode* node) const;
    void printInOrder(const TreeNode* node) const;
    void printPostOrder(const TreeNode* node) const;
    void inorder(TreeNode* node) const;
    bool contains(int key, const TreeNode* node) const;
    bool containsBruteForce(int value, TreeNode* node) const;
    void insert(int value, TreeNode** node);
    void remove(int value, TreeNode** node);
    bool isBalanced(TreeNode* node) const;
};

#endif /* defined(__BinaryIntegerSearchTree__BinarySearchInt__) */
