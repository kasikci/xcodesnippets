//
//  main.cpp
//  SingleDimensionalArrayRotator
//
//  Created by Baris Kasikci on 14/12/13.
//  Copyright (c) 2013 Baris Kasikci. All rights reserved.
//
// The idea is to rotate the entire array first
// then to 

#include <iostream>

using namespace std;

void reverseArray (int array[], int length) {
    int begin = 0;
    int end = length-1;
    
    while (end > begin) {
        int temp = array[begin];
        array[begin] = array[end];
        array[end] = temp;
        --end;
        ++begin;
    }
}

void rotateArrayRight(int array[], int length, int rotCount) {
    rotCount = rotCount % length;
    // 1,2,3,4,5 -> 5,4,3,2,1 -> 4,5,3,2,1 -> 4,5,1,2,3
    reverseArray(array, length);
    reverseArray(array, rotCount);
    reverseArray(array + rotCount, length - rotCount);
}


int main(int argc, const char * argv[])
{
    int array[] = {1, 2, 3, 4, 5};
    cout << "Rotating {1,2,3,4,5} by 2: ";
    rotateArrayRight(array, 5, 2);
    for (int i = 0; i < 5; ++i)
        cout << array[i] << " ";
    return 0;
}

