// LeetCode 131: Palindrome Partitioning
//
// Approach: Backtracking + Dynamic Programming
//
// Idea:
// - First precompute a DP table where:
//      dp[i][j] = true if substring s[i..j] is a palindrome.
//
// - Then use backtracking to generate all partitions.
// - At each index i, try all possible substrings s[i..j].
// - If s[i..j] is palindrome, include it in the current partition
//   and continue recursion from j+1.
//
// Time Complexity: O(n * 2^n)
// Space Complexity: O(n^2) for DP table

class Solution {
public:

    // Backtracking function to build partitions
    void solve(string& s, int i,
               vector<string>& curpartition,
               vector<vector<string>>& result,
               vector<vector<bool>>& t) {

        // If we reached the end of string, store partition
        if (i == s.size()) {
            result.push_back(curpartition);
            return;
        }

        // Try all substrings starting at index i
        for (int j = i; j < s.size(); j++) {

            if (t[i][j]) {
                // Choose substring
                curpartition.push_back(s.substr(i, j - i + 1));

                // Recurse for remaining string
                solve(s, j + 1, curpartition, result, t);

                // Backtrack
                curpartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        int n = s.size();

        // DP table to check palindromes
        vector<vector<bool>> t(n, vector<bool>(n, false));

        // Single characters are palindromes
        for (int i = 0; i < n; i++) {
            t[i][i] = true;
        }

        // Fill DP table
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {

                int j = i + l - 1;

                if (s[i] == s[j]) {
                    if (l == 2) {
                        t[i][j] = true;
                    } else {
                        t[i][j] = t[i + 1][j - 1];
                    }
                }
            }
        }

        vector<vector<string>> result;
        vector<string> curpartition;

        // Start backtracking
        solve(s, 0, curpartition, result, t);

        return result;
    }
};
