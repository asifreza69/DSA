#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;

        // Frequency map of s1
        for (char c : s1) {
            mp[c]++;
        }

        int k = s1.size();
        int i = 0, j = 0;

        unordered_map<char, int> mp2;

        while (j < s2.size()) {
            mp2[s2[j]]++;

            // Maintain window size = k
            while (j - i + 1 > k) {
                mp2[s2[i]]--;
                if (mp2[s2[i]] == 0) {
                    mp2.erase(s2[i]);
                }
                i++;
            }

            // Check if both maps are equal
            if (mp == mp2) {
                return true;
            }

            j++;
        }

        return false;
    }
};

/*
Problem: Permutation in String (LeetCode 567)

Approach:
Sliding Window + HashMap

Logic:
- Create frequency map of s1
- Maintain a window of size k in s2
- Store frequency of current window in another map
- Compare both maps → if equal, permutation exists

Time Complexity:
O(n * k)  // due to map comparison

Space Complexity:
O(k)

Key Insight:
We compare frequency maps of window and target string
*/
