#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int n;
    int t[30001][2];

    int solve(int i, vector<int>& p, bool canBuy) {
        if (i >= n) return 0;

        if (t[i][canBuy] != -1) return t[i][canBuy];

        int profit = 0;

        if (canBuy) {
            int buy = -p[i] + solve(i + 1, p, false);
            int skip = solve(i + 1, p, true);
            profit = max(buy, skip);
        } else {
            int sell = p[i] + solve(i + 1, p, true);
            int skip = solve(i + 1, p, false);
            profit = max(sell, skip);
        }

        return t[i][canBuy] = profit;
    }

    int maxProfit(vector<int>& p) {
        n = p.size();
        memset(t, -1, sizeof(t));
        return solve(0, p, true);
    }
};

/*
Problem: Best Time to Buy and Sell Stock II (LeetCode 122)

Approach:
Used Dynamic Programming with recursion + memoization.

State:
- i → current day
- canBuy → whether we can buy or need to sell

Choices:
1. If canBuy:
   - Buy stock
   - Skip

2. If cannot buy:
   - Sell stock
   - Skip

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
At each step, maximize profit by choosing optimal decision (buy/sell/skip)
*/
