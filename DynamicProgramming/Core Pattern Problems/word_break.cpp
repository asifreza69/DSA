#include <cstring>
#include <unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<string> st;
    int n;
    int t[301];

    bool solve(int i, string& s) {

        // Entire string successfully segmented
        if(i >= n) {
            return true;
        }

        // Memoized result
        if(t[i] != -1) {
            return t[i];
        }

        // Try all possible substring lengths
        // starting from index i
        for(int len = 1; len <= n - i; len++) {

            string word = s.substr(i, len);

            // If word exists in dictionary,
            // recursively solve remaining string
            if(st.find(word) != st.end() &&
               solve(i + len, s)) {

                return t[i] = true;
            }
        }

        return t[i] = false;
    }

    bool wordBreak(string s,
                   vector<string>& wordDict) {

        n = s.size();

        memset(t, -1, sizeof(t));

        // Store dictionary in hash set
        for(auto& word : wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};

/*
==========================
🔥 WORD BREAK
==========================

Goal:
Determine whether the string can
be segmented into valid words
from the dictionary.

--------------------------------

🧠 Core Idea:

At each index i, try every
possible substring s[i...j].

If a substring is present in the
dictionary, recursively check
whether the remaining suffix can
also be segmented.

--------------------------------

State:

solve(i)

= Can substring s[i...end]
be segmented into dictionary
words?

--------------------------------

Recurrence:

For every len from 1 to n-i:

word = s.substr(i, len)

If word exists in dictionary
and solve(i + len) is true,
return true.

If no valid split works,
return false.

--------------------------------

Base Case:

i == n
→ Entire string segmented
→ return true

--------------------------------

Example:

s = "leetcode"
dict = ["leet", "code"]

"leet" + "code"
Answer = true

--------------------------------

⏱️ Time Complexity:
O(n³) in worst case
- n states
- O(n) substrings per state
- substring creation O(n)

(With optimized substring
handling, often treated as O(n²))

--------------------------------

🧠 Space Complexity:
O(n + dictionary size)

Memo array + recursion stack.

--------------------------------

🧩 Pattern:
Partition DP

--------------------------------

🎯 Category:
Dynamic Programming → String Segmentation

--------------------------------

🧠 Interview One-Liner:

At each index, try every valid
dictionary word as a prefix and
recursively check the remaining
suffix.

*/
