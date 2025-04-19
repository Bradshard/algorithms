#include <iostream>
#include <fstream>
#include <chrono>
#include "the3.h"

void file_input(int &N,  
                std::vector<std::vector<int>>& costs){
    std::string file_name = "inp01.txt"; // inp01-inp10 are available.
    std::ifstream infile (file_name);

    if(!infile.is_open()){
        std::cout << "Input file cannot be opened" << std::endl;
        std::cout << "File name: " << file_name << std::endl;
        return;
    }

    infile >> N;
    costs.resize(N-1);
    for(int idx=0; idx < N-1; idx++){
        for(int idy=0; idy < 6; idy++){
            int cost;
            infile >> cost;
            costs[idx].push_back(cost);
        }
    }
}

void test(){
    int N;
    int min_cost;
    std::vector< std::vector<int> > costs;
    file_input(N, costs);
    std::cout << "N: " << N << std::endl <<
                 "Costs array (at most 9 rows are shown): " << std::endl;
    int max = 9;
    if (N < 10) max = N-1;
    for(int idx=0; idx < max; idx++){
        for(int idy=0; idy < 6; idy++){
            std::cout << costs[idx][idy] << " ";
        }
        std::cout << std::endl;
    }
    if (N > 10) std::cout << "..." << std::endl;

    auto begin = std::chrono::high_resolution_clock::now();
    min_cost = find_min_cost(costs, N);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Found min_cost: " << min_cost << std::endl
              << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;

}

int main(){
    test();
    return 0;
}