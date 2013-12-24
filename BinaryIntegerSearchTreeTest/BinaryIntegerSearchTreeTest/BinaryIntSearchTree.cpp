//
//  BinarySearchInt.cpp
//  BinaryIntegerSearchTree
//
//  Created by Baris Kasikci on 15/12/13.
//  Copyright (c) 2013 Baris Kasikci. All rights reserved.
//

#include "BinaryIntSearchTree.h"

bool BinaryIntSearchTree::contains(int value) const {
    return contains(value, root);
}

// the private version of the contains method that takes a Node pointer
bool BinaryIntSearchTree::contains(int value, const TreeNode* node) const {
    if(!node)
        return false;
    else if(node->value == value)
        return true;
    
    if(value < node->value)
        return contains(value, node->left); // smaller key values are to the left
    else
        return contains(value, node->right); // larger key values are to the right
}

bool BinaryIntSearchTree::containsIter(int value) const {
    if(!root)
        return false;
    TreeNode*  current = root;
    
    std::stack<TreeNode*> stack;
    bool done = false;
    
    while (!done && current) {
        if(current->value == value)
            return true;
        
        if(current->left) {
            stack.push(current);
            current = current->left;
        } else if (current->right) {
            current = current->right;
        } else {
            // no left or right kiddos, see if we have something
            // to pick the exploration up from in the stack
            if(!stack.empty()) {
                current = stack.top();
                stack.pop ();
                current = current->right;
            } else {
                done = true;
            }
        }
    }
    
    return false;
}

// this is more appropriate for a potential super class like binary tree
// this method does not leverage the binary search tree property
bool BinaryIntSearchTree::containsBruteForce(int value) const {
    return containsBruteForce(value, root);
}

bool BinaryIntSearchTree::containsBruteForce(int value, TreeNode* node) const {
    if(!node)
        return false;
    // A more clear version:
    /*
    if(node->value == value)
        return true;
    if(containsBruteForce(value, node->left))
        return true;
    if(containsBruteForce(value, node->right))
        return true;
    return false;
    */
    // A more comapct version that takes the complement of the first version
    if(node->value != value &&
       !containsBruteForce(value, node->left)  &&
       !containsBruteForce(value, node->right))
        return false;
    
    return true;
}

void BinaryIntSearchTree::insert(int value) {
    insert(value, &root);
}

// Insertion is going to change the root pointer, becareful to pass the
// pointer to the root pointer! Just like in a linked list head!
void BinaryIntSearchTree::insert(int value, TreeNode** node) {
    if(!(*node)) {
        //if the root is null, insert
        *node = new TreeNode(value);
    } else {
        // node is not null here
        if(value <= (*node)->value) { // "equal to" case covered by the left child
            insert(value, &((*node)->left));
        } else
            insert(value, &((*node)->right));
        }
}

void BinaryIntSearchTree::printPreOrder() const{
    printPreOrder(root);
}

void BinaryIntSearchTree::printPreOrder(const TreeNode* node) const {
    if(node){
        std::cout << node->value << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    } // else is the base case; we make no more recursive calls
}


void BinaryIntSearchTree::printInOrder() const{
    printInOrder(root);
}

void BinaryIntSearchTree::printInOrder(const TreeNode* node) const {
    if(node){
        printPreOrder(node->left);
        std::cout << node->value << " ";
        printPreOrder(node->right);
    } // else is the base case; we make no more recursive calls
}

void BinaryIntSearchTree::printPostOrder() const {
    printPostOrder(root);
}

void BinaryIntSearchTree::printPostOrder(const TreeNode* node) const {
    if(node) {
        printPostOrder(node->left);
        printPreOrder(node->right);
        std::cout << node->value << " ";
    }
}

void BinaryIntSearchTree::remove(int value) {
    remove(value, &root);
}

// Need adouble pointer here just in case we
// need to modify the head
void BinaryIntSearchTree::remove(int value, TreeNode** node) {
    
}
