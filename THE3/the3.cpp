#include "the3.h"

int find_min_cost(const std::vector<std::vector<int>>& costs, int N) {
    const int plant_types = 6; // flower1, flower2, bush1, bush2, tree1, tree2 given in the problem def'n
    const int sky_is_limit = 1e6 * 1e1 + 1; // large number given in problem def'n as infinity limit
    std::vector<std::vector<int>> dp(N - 1, std::vector<int>(plant_types, sky_is_limit));

    // Dynamic programming initialization
    for (int j = 0; j < plant_types; j++) { // O(1)
        dp[0][j] = costs[0][j];
    }

    // Dynamic Programming table (DP Table)
    for (int i = 1; i < N - 1; i++) { // O(N) we use N-1 due to statue in the island
        for (int j = 0; j < plant_types; j++) { // Curr plant type O(1)
            for (int k = 0; k < plant_types; k++) { // Prev plant type O(1)

                bool valid_cond = false;

                // Transition rules based on the plant types
                if (j == 0) { // flower type 0
                    valid_cond = (k == 0 || k >= 2); // Can follow itself or any bush/tree not flower type 1
                } else if (j == 1) { // flower type 1
                    valid_cond = (k == 1 || k >= 2); // Can follow itself or other types except flower type 0
                } else if (j == 2 || j == 3) { // bushes :)
                    valid_cond = (k != 2 && k != 3); // Only can follow other types except bushes
                } else if (j == 4 || j == 5) { // trees :)
                    valid_cond = (k != 4 && k != 5); // Only can follow other types except trees
                }

                if (valid_cond) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + costs[i][j]);
                }
            }
        }
    }

    // Minimum cost via bottom-up DP
    int min_cost = sky_is_limit;
    for (int j = 0; j < plant_types; j++) { // O(1)
        if (dp[N - 2][j] < min_cost) {
            min_cost = dp[N - 2][j]; // N-2 because last position is not -1 due to statue.
        }
    }
    // Total space complexity O((N−1)×6) = O(N) and Time Complexity O(N) since O(1) does not affect.
    return min_cost;
}
/*
I used 1e7 + 1 as limit because c at each step can be maximum at 10 and it is said that at maximum
we have 1e6 steps hence 1e6*1e1 = 1e7
*/
