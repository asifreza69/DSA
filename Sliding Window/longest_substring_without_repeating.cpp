#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int i = 0, j = 0;
        int maxi = 0;

        while (j < s.size()) {
            mp[s[j]]++;

            // If duplicate exists, shrink window
            while (j - i + 1 > mp.size()) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }

            maxi = max(maxi, j - i + 1);
            j++;
        }

        return maxi;
    }
};

/*
Problem: Longest Substring Without Repeating Characters (LeetCode 3)

Approach:
Sliding Window + HashMap

Logic:
- Expand window using j
- If duplicate exists → shrink from i
- Maintain window where all characters are unique

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
Window size equals number of unique characters when no duplicates exist
*/
