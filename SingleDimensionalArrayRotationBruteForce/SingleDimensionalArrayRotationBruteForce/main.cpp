//
//  main.cpp
//  SingleDimensionalArrayRotationBruteForce
//
//  Created by Baris Kasikci on 15/12/13.
//  Copyright (c) 2013 Baris Kasikci. All rights reserved.
//

#include <iostream>

int rotateArray (int array[], int length, int rotcount) {
    rotcount = rotcount % length;
    
    int * firstArray = (int*) malloc(sizeof(int) * (length - rotcount));
    if(!firstArray)
        return -1;
    
    int * secondArray = (int*) malloc(sizeof(int) * rotcount);
    if(!secondArray)
        return -1;
    
    // get the copy of the arrays into memory
    memcpy(firstArray, array, sizeof(int) * (length - rotcount));
    memcpy(secondArray, (array + length - rotcount), sizeof(int) * rotcount);
    
    // put them back in
    memcpy(array, secondArray, sizeof(int) * rotcount);
    memcpy(array + rotcount, firstArray, sizeof(int) * (length - rotcount));
    
    free (firstArray);
    free (secondArray);
  
    return 1;
}

int main(int argc, const char * argv[])
{
    int array[] = {1, 2, 3, 4, 5};
    std::cout << "Rotation of (1,2,3,4,5) by 2" << std::endl;
    
    if(rotateArray(array, 5, 2)) {
        for(int i = 0; i < 5; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cerr << "Memory allocation failure!" << std::endl;
        return -1;
    }
    
    return 0;
}

