//
//  main.cpp
//  QuickSort
//
//  Created by Baris Kasikci on 16/01/14.
//  Copyright (c) 2014 Baris Kasikci. All rights reserved.
//

#include <iostream>

//my version
void quickSort(int array[], int start, int end) {
    if(start >= end)
        return;
    
    int pivotIndex = (start + end)/2;
    int pivot = array[pivotIndex];
    int i = start;
    int j = end;
    
    while(j > i) {
        while(array[i] < pivot)
            ++i;
        while(array[j] > pivot)
            --j;
        if(j > i) {
            // keep track of where you move the pivot if you move it
            if(i == pivotIndex)
                pivotIndex = j;
            else if(j == pivotIndex)
                pivotIndex = i;
            
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            --j;
            ++i;
        }
    }
    
    quickSort(array, start, pivotIndex-1);
    quickSort(array, pivotIndex+1, end);
}

// textbook version, pay attentiaon to the equalities in the partitioning phase
void quickSort2(int array[], int left, int right) {
    int pivot = array[(left+right)/2];
    int i = left;
    int j = right;
    
    while(j >= i) {
        // even if i==j, this is needed, because perhaps we have not
        // compared the pivot with the value at that index where i == j
        while(array[i] < pivot)
            ++i;
        while(array[j] > pivot)
            --j;
        
        // The equality in the below case is needed to advance i and regress j
        // in the case where i == j but array[i] >= pivot and array[j] <= pivot
        // and break out of the loop.
        if(i <= j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            --j;
            ++i;
        }
    }
    
    if(j > left)
        quickSort2(array, left, j);
    if(right > i)
        quickSort2(array, i, right);
}

int main(int argc, const char * argv[])
{
    int arrayToSort[] = {3, 8, 2, 5, 1, 4, 7, 6};
    quickSort2(arrayToSort, 0, 7);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}