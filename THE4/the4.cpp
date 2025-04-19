#include "the4.h"

// DO NOT CHANGE ABOVE THIS LINE!
// You may implement helper functions below


unsigned int alice_cutting_cake(const unsigned short cake_width,
                                const unsigned short cake_height,
                                bool **perfect_cuts) {
    // DP table for storing minimum wasted area
    unsigned int dp[cake_width +1][cake_height + 1];
    std::vector<unsigned int> perfect_heights;
    std::vector<unsigned int> perfect_widths;

    // DP TABLE
    for (unsigned int i = 1; i <= cake_width; i++) {
        for (unsigned int j = 1; j <= cake_height; j++) {
            // Base case
            if (perfect_cuts[i][j]) {
                dp[i][j] = 0;
                perfect_heights.push_back(j);
                perfect_widths.push_back(i);
                continue;
            } else{
                dp[i][j] = i*j;
            }

            // Perfect Cuts
            for (unsigned int i1 = 0; i1 < perfect_widths.size(); i1++) {
                unsigned int cut_width = perfect_widths[i1];
                unsigned int cut_height = perfect_heights[i1];
                if(cut_width > i || cut_height > j){
                    continue;
                } else{
                    dp[i][j] = std::min(std::min(dp[i][j], dp[cut_width][j] + dp[i - cut_width][j]), dp[i][cut_height] + dp[i][j - cut_height]);
                }
                
            }
        }
    }

    // Minimum tasty
    unsigned int min_taste = dp[cake_width][cake_height];
    return min_taste;
}
