

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        for (char c : t) {
            mp[c]++;
        }

        int i = 0, j = 0;
        int count = mp.size();
        int start = -1, ans = INT_MAX;

        while (j < s.size()) {
            char c = s[j];

            if (mp.find(c) != mp.end()) {
                mp[c]--;
                if (mp[c] == 0) {
                    count--;
                }
            }

            while (count == 0) {
                if (j - i + 1 < ans) {
                    ans = j - i + 1;
                    start = i;
                }

                if (mp.find(s[i]) != mp.end()) {
                    if (mp[s[i]] == 0) {
                        count++;
                    }
                    mp[s[i]]++;
                }
                i++;
            }

            j++;
        }

        return ans == INT_MAX ? "" : s.substr(start, ans);
    }
};

/*
Problem: Minimum Window Substring (LeetCode 76)

Approach:
Sliding Window + HashMap

Logic:
- Track frequency of required characters
- Expand window until all chars matched
- Shrink window to get minimum length

Time Complexity:
O(n)

Space Complexity:
O(1) (max 128 chars)

Key Insight:
Use count of unique chars to track valid window
*/
