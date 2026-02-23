// LeetCode 1420: Build Array Where You Can Find The Maximum Exactly K Comparisons
//
// Approach: Top-Down Dynamic Programming (Memoization)
//
// Idea:
// - We need to build an array of length N using numbers from 1 to M.
// - "Cost" increases whenever we pick a number greater than the current maximum.
// - We must end with exactly K cost.
//
// - DP State:
//      solve(index, cost_so_far, current_max)
//
// - index       -> current position in array
// - cost_so_far -> number of times maximum changed
// - current_max -> current maximum value in array
//
// - At each index, try all values from 1 to M:
//      If chosen value > current_max → cost + 1
//      Otherwise → cost unchanged
//
// Time Complexity: O(N * K * M * M)
// Space Complexity: O(N * K * M)

class Solution {
public:
    int M, N, K;
    int t[51][51][101];
    int MOD = 1e9 + 7;

    int solve(int i, int cost, int maxi) {

        // Base case: array completed
        if (i == N) {
            return (cost == K) ? 1 : 0;
        }

        // If cost already exceeds K, no need to continue
        if (cost > K) {
            return 0;
        }

        // Memoization check
        if (t[i][cost][maxi] != -1) {
            return t[i][cost][maxi];
        }

        long long ways = 0;

        // Try all values from 1 to M
        for (int num = 1; num <= M; num++) {

            if (num > maxi) {
                // New maximum found → increase cost
                ways = (ways + solve(i + 1, cost + 1, num)) % MOD;
            } else {
                // Maximum remains same
                ways = (ways + solve(i + 1, cost, maxi)) % MOD;
            }
        }

        return t[i][cost][maxi] = ways;
    }

    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;

        memset(t, -1, sizeof(t));

        return solve(0, 0, 0);
    }
};
