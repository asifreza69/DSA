#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mini = INT_MAX;
        int ans = 0;

        for (int i = 0; i < p.size(); i++) {
            mini = min(mini, p[i]);        // track minimum price
            ans = max(ans, p[i] - mini);   // calculate max profit
        }

        return ans;
    }
};

/*
Problem: Best Time to Buy and Sell Stock (LeetCode 121)

Approach:
Greedy (Single Pass)

Logic:
- Keep track of minimum price so far
- At each step, calculate profit if sold today
- Update maximum profit

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Max profit depends on minimum price before current day
*/
