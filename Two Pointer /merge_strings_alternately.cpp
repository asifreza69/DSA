#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string ans;
        ans.reserve(word1.size() + word2.size());

        // Merge alternately
        while (i < word1.size() && j < word2.size()) {
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
        }

        // Add remaining characters
        while (i < word1.size()) {
            ans.push_back(word1[i]);
            i++;
        }

        while (j < word2.size()) {
            ans.push_back(word2[j]);
            j++;
        }

        return ans;
    }
};

/*
Problem: Merge Strings Alternately (LeetCode 1768)

Approach:
Two-pointer technique

Logic:
- Traverse both strings simultaneously
- Add characters alternately
- Append remaining characters from longer string

Time Complexity:
O(n + m)

Space Complexity:
O(n + m)

Key Insight:
Simple pointer traversal ensures efficient merging
*/
