#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i = 0, j = 0, sum = 0;

        while (j < nums.size()) {
            sum += nums[j];

            // Shrink window while condition is satisfied
            while (sum >= target) {
                ans = min(ans, j - i + 1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

/*
Problem: Minimum Size Subarray Sum (LeetCode 209)

Approach:
Sliding Window (Variable Size)

Logic:
- Expand window by adding nums[j]
- When sum >= target → shrink from left
- Track minimum window size

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Use sliding window to maintain valid subarray and minimize length
*/
