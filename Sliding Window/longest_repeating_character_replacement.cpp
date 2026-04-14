#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;

        int l = 0, maxf = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            // shrink window if replacements needed > k
            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};

/*
Problem: Longest Repeating Character Replacement (LeetCode 424)

Approach:
Sliding Window + Frequency Map

Logic:
- Maintain window [l, r]
- Track most frequent character (maxf)
- If replacements needed > k → shrink window
- Keep updating max length

Time Complexity:
O(n)

Space Complexity:
O(1) (since max 26 characters)

Key Insight:
Window size - max frequency = replacements needed
*/
