#include "the2.h"

int get_group_value(const std::string& str, int start, int group_size) {
    if(start < 0){
        group_size += start;
        start = 0;
    }
    int value = 0;
    for (int i = 0; i < group_size; i++) {
        int char_index = start + i;
        if (char_index < str.length()) {
            value = value * 27 + (str[char_index] - 'A' + 1);
        } else {
            value *= 27;  // Extend the base for missing characters (padding) as in receptive field dilution
        }
    }
    return value;
}


int counting_sort(std::string* arr, int size, int digit, int group_size, bool ascending, int max_length) {
    int base = std::pow(27, group_size);
    int* C = new int[base]{0};
    //std::vector<int> C(base, 0);
    std::vector<std::string> B(size);
    int iterations = 0;

    // Populating
    for (int i = 0; i < size; i++) {
        int index = get_group_value(arr[i], max_length - digit - group_size, group_size);
        C[index]++;
        iterations++;
    }

    // cum cout
    if (ascending) {
        for (int i = 1; i < base; i++) {
            C[i] += C[i - 1];
            iterations++;
        }
    } else {
        for (int i = base - 2; i >= 0; i--) {
            C[i] += C[i + 1];
            iterations++;
        }
    }

    // Sort based on counts
    for (int i = size - 1; i >= 0; i--) {
        int index = get_group_value(arr[i], max_length - digit - group_size, group_size);
        B[--C[index]] = arr[i];
        iterations++;
    }

    // Copy back to the original array
    for (int i = 0; i < size; i++) {
        arr[i] = B[i];
        iterations++;
    }

    return iterations;
}

// Radix sort implementation for multidigit
long multi_digit_string_radix_sort(std::string* arr, int size, bool ascending, int group_size) {
    int total_iterations = 0;
    int max_length = 0;
    int effective_group_size = 0;
    for (int i = 0; i < size; i++) {
        max_length = std::max(max_length, static_cast<int>(arr[i].length()));
    }

    for (int digit = 0; digit < max_length; digit += group_size) {
        effective_group_size = std::min(group_size, max_length - digit);
        total_iterations += counting_sort(arr, size, digit, effective_group_size, ascending, max_length);
    }

    return total_iterations;
}
