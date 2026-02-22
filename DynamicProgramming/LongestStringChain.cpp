// LeetCode 1048: Longest String Chain
//
// Approach: Top-Down Dynamic Programming (Memoization)
//
// Idea:
// - First sort words by length (ascending).
// - For two words to form a chain:
//      word1 → word2
//      word2 length must be word1 length + 1
//      and word1 should be a predecessor of word2
//
// - At each index we decide:
//      1. Take current word (if valid chain)
//      2. Skip current word
//
// - DP State:
//      solve(prev_index, current_index)
//
// Time Complexity: O(n^2 * L)
//      n = number of words
//      L = average word length
//
// Space Complexity: O(n^2)

class Solution {
public:
    int t[1001][1001];  // Memoization table

    // Comparator to sort words by length
    static bool comp(string& s1, string& s2) {
        return s1.size() < s2.size();
    }

    // Check if s1 is predecessor of s2
    bool check(string s1, string s2) {
        // Length difference must be exactly 1
        if (s2.size() - s1.size() != 1) {
            return false;
        }

        int i = 0, j = 0;

        // Try matching characters with at most one extra char in s2
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                j++;  // Skip one character in longer string
            }
        }

        return i == s1.size();
    }

    int solve(int prev, int curr, vector<string>& words) {

        // Base case
        if (curr >= words.size()) {
            return 0;
        }

        // Memo check (only when prev != -1)
        if (prev != -1 && t[prev][curr] != -1) {
            return t[prev][curr];
        }

        int take = 0;

        // Take current word if valid
        if (prev == -1 || check(words[prev], words[curr])) {
            take = 1 + solve(curr, curr + 1, words);
        }

        // Skip current word
        int skip = solve(prev, curr + 1, words);

        // Store result
        if (prev != -1) {
            t[prev][curr] = max(skip, take);
        }

        return max(skip, take);
    }

    int longestStrChain(vector<string>& words) {
        // Sort words by length
        sort(words.begin(), words.end(), comp);

        // Initialize memo table
        memset(t, -1, sizeof(t));

        return solve(-1, 0, words);
    }
};
