#include <iostream>
#include <fstream>
#include <chrono>
#include "the2.h"

void file_input(std::string *&input_array,
                int &size,
                bool &ascending,
                int &group_size){
    std::string file_name = "inp01.txt"; // inp01-inp20 are available.
    std::ifstream infile (file_name);

    if(!infile.is_open()){
        std::cout << "Input file cannot be opened" << std::endl;
        std::cout << "File name: " << file_name << std::endl;
        return;
    }

    infile >> ascending;
    infile >> group_size;
    infile >> size;
    input_array = new std::string[size];
    for(int idx=0; idx < size; idx++)
        infile >> input_array[idx];
}

void test(){
    int size, group_size;
    long number_of_iteration;
    bool ascending;
    std::string *input_array;
    file_input(input_array, size, ascending, group_size);
    std::cout << "Size: " << size << std::endl <<
                 "Ascending: " << ascending << std::endl <<
                 "Group size: " << group_size << std::endl <<
                 "Array elements: {";
    for(int idx=0; idx < size; idx++)
        std::cout << input_array[idx] << (idx != size-1 ? ", "
                                                        : "}");
    std::cout << std::endl;

    auto begin = std::chrono::high_resolution_clock::now();
    number_of_iteration = multi_digit_string_radix_sort(input_array, size, ascending, group_size);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Number of iterations: " << number_of_iteration << std::endl
              << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl
              << "Sorted array: {";
    for(int idx=0; idx < size; idx++)
        std::cout << input_array[idx] << (idx != size-1 ? ", " : "}");
    std::cout << std::endl;

}

int main(){
    test();
    return 0;
}