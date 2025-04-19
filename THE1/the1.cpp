#include "the1.h"

// DO NOT CHANGE ABOVE THIS LINE!
// you may implement helper functions below


std::pair<unsigned int, unsigned int> partition3(unsigned short *arr, unsigned int low, unsigned int high, long &swap) {
    unsigned short pivot = arr[low];
    int i = low + 1, j = low + 1, k = high;

    while (j <= k) {
        if (arr[j] == pivot) {
            j++;
        } else if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            i++;
            swap++;
            j++;
        } else if (arr[j] > pivot){
            std::swap(arr[j], arr[k]);
            k--;
            swap++;
        }
    }
    std::swap(arr[i-1], arr[low]);
    swap++;
    return std::make_pair(i-1, j);
}


//quick-sort3
std::pair<unsigned short, unsigned int> select_k_with_quick_sort3(unsigned short *arr,
                                                                  const unsigned int size,
                                                                  const unsigned int index,
                                                                  long &swap) {
    
    std::vector<unsigned int> lows = {0};
    std::vector<unsigned int> highs = {size -1 };
    int count = 1; int i = 0;
    
    while (i < count){
        int low = lows[i];
        int high = highs[i];
        std::pair<unsigned int, unsigned int>  Values = partition3(arr,low, high, swap);
        int right = Values.second;
        int left = Values.first - 1;
        
        if(left > low){
            lows.push_back(low);
            highs.push_back(left);
            count++;
        }
        if(right < high){
            lows.push_back(right);
            highs.push_back(high);
            count++;
        }
        /*
        if (left + 1 < right - 1){
            lows.push_back(left + 1);
            highs.push_back(right - 1);
            count++;
        }
        */
        i++;
    }
    count = 2* count + 1; // for counting all recursions.
    
    
    return std::make_pair(arr[index], count);
}


// 3-way Quick Select
std::pair<unsigned short, unsigned int> quick_select3(unsigned short *arr,
                                                      const unsigned int size,
                                                      const unsigned int index,
                                                      long &swap) {
    std::vector<unsigned int> lows = {0};
    std::vector<unsigned int> highs = {size -1 };
    int count = 1; int i = 0;
    
    while (i < count){
        int low = lows[i];
        int high = highs[i];
        std::pair<unsigned int, unsigned int>  Values = partition3(arr,low, high, swap);
        int right = Values.second;
        int left = Values.first - 1;
        
        if(left > low && index <= left){
            lows.push_back(low);
            highs.push_back(left);
            count++;
        }
        if(right < high && index >= right){
            lows.push_back(right);
            highs.push_back(high);
            count++;
        }
        
        i++;
    }

    
    return std::make_pair(arr[index], count);
}

