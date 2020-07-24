#include "findLargestSum.hpp"

void find_largest_sum(const uint32_t T, const std::vector<uint32_t>& I,
                      std::vector<uint32_t>& M, uint32_t& S) {
    if (I.empty()) {
        return;
    }

    // Dynamic programming will be helpful to solve the problem.
    // I checked the knapsack problem to gather logic and information.
    // Subproblems will be considered first to reach the solution for the whole problem.
    // Meaning that the problems will be solved considering :
    //    - elements i, where 0 <= i <= I.size()
    //    - sum j, where 0 <= j <= T

    auto n = I.size()+1; // +1 because of element 0 considered if none.
    auto m = T+1;        // +1 because of sum equal to 0.

    // dp[i][j] is true if sum j is possible with vector elements from 0 to i.
    // else dp[i][j] is false
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(m, false));

    // canReach[i][j] is the maximum value that can be reached with the sum of items
    // up to i and less than or equal to j
    // The dynamic programming algorithm will be as follows :
    //    - canReach[0][j] = 0
    //    - canReach[i][j] = (I[i-1] > j) ? canReach[i-1][j]
    //                                : max(canReach[i-1][j], canReach[i-1][j] + I[i - 1]
    std::vector<std::vector<uint32_t>> canReach(n, std::vector<uint32_t>(m, 0));

    for (auto i=1; i<n; ++i) {
        for (auto j=T; j>0; --j) {
            if (I[i-1]>j) {
                canReach[i][j] = canReach[i-1][j];
            } else {
                if ((canReach[i-1][j-I[i-1]] + I[i-1]) > canReach[i-1][j]) {
                    canReach[i][j] = canReach[i-1][j-I[i-1]] + I[i-1];
                    dp[i][j] = true;
                } else {
                    canReach[i][j] = canReach[i-1][j];
                }
            }
        }
    }

    // Retrieving of the values making the sum possible from top to bottom
    // regarding dp[i][j]
    auto j = T;
    for (auto i=I.size(); i>0; --i) {
        if (dp[i][j]) {
            M.emplace_back(I[i-1]);
            j -= I[i-1];
            S += I[i-1];
        }
    }
}
