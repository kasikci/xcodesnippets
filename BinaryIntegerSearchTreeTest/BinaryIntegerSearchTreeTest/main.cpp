//
//  main.cpp
//  BinaryIntegerSearchTreeTest
//
//  Created by Baris Kasikci on 15/12/13.
//  Copyright (c) 2013 Baris Kasikci. All rights reserved.
//

#include <iostream>
#include "BinaryIntSearchTree.h"


int main(int argc, const char * argv[])
{
    BinaryIntSearchTree tree;
    
    // Test insertions
    tree.insert(7);
    tree.insert(5);
    tree.insert(9);
    tree.insert(6);
    
    // Test traversals
    std::cout << "Preorder: \n";
    tree.printPreOrder();
    std::cout << "\nInorder: \n";
    tree.printInOrder();
    std::cout << "\nPostorder: \n";
    tree.printPostOrder();
    std::cout << std::endl;
    
    // Test containment
    std::cout << "tree.contains(7):" << tree.contains(7) << std::endl;
    std::cout << "tree.contains(5):" << tree.contains(5) << std::endl;
    std::cout << "tree.contains(9):" << tree.contains(9) << std::endl;
    std::cout << "tree.contains(6):" << tree.contains(6) << std::endl;
    std::cout << "tree.contains(0):" << tree.contains(0) << std::endl;
    
    std::cout << "containsIter(7):" << tree.containsIter(7) << std::endl;
    std::cout << "containsIter(5):" << tree.containsIter(5) << std::endl;
    std::cout << "containsIter(9):" << tree.containsIter(9) << std::endl;
    std::cout << "containsIter(6):" << tree.containsIter(6) << std::endl;
    std::cout << "containsIter(0):" << tree.containsIter(0) << std::endl;

    std::cout << "containsBruteForce(7):" << tree.containsBruteForce(7) << std::endl;
    std::cout << "containsBruteForce(5):" << tree.containsBruteForce(5) << std::endl;
    std::cout << "containsBruteForce(9):" << tree.containsBruteForce(9) << std::endl;
    std::cout << "containsBruteForce(6):" << tree.containsBruteForce(6) << std::endl;
    std::cout << "containsBruteForce(0):" << tree.containsBruteForce(0) << std::endl;
    
    return 0;
}

