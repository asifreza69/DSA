#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        stack<pair<int,int>> st; // {temperature, index}

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= t[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top().second - i;
            }

            st.push({t[i], i});
        }

        return ans;
    }
};

/*
Problem: Daily Temperatures (LeetCode 739)

Approach:
Monotonic Stack (Next Greater Element)

Logic:
- Traverse from right
- Maintain decreasing stack
- Pop smaller/equal elements
- Top gives next warmer day

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
Stack stores next greater elements efficiently
*/
