#include <string>
using namespace std;

class Solution {
public:
    bool check(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                // Try skipping either left or right character
                return check(i + 1, j, s) || check(i, j - 1, s);
            }
        }
        return true;
    }
};

/*
Problem: Valid Palindrome II (LeetCode 680)

Approach:
Two-pointer technique with at most one deletion allowed.

Logic:
- Use two pointers (i, j)
- If characters match → move inward
- If mismatch:
   → Try skipping left character OR right character
   → Check if remaining substring is palindrome

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
At most one deletion allowed → only one mismatch handling needed
*/
