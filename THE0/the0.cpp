#include "the0.h"

void insertionSort(int* arr, long &comparison, long &swap, int size)
{
    comparison = 0; swap = 0;
    
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        
        comparison++;
        while (j >= 0)
        {
            
            if(arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
                swap++;
                comparison++;
            } else{ break;}
        }
        arr[j + 1] = key;
    }
}
