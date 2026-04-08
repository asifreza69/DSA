#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool one = false;

        // Step 1: Check if 1 exists & clean array
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) one = true;

            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        if (!one) return 1;

        // Step 2: Mark presence using index
        for (int i = 0; i < n; i++) {
            int t = abs(nums[i]);
            if (t >= 1 && t <= n && nums[t - 1] > 0) {
                nums[t - 1] = -nums[t - 1];
            }
        }

        // Step 3: Find first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

/*
Problem: First Missing Positive (LeetCode 41)

Approach:
Used in-place hashing by marking indices.

Logic:
1. Replace invalid numbers (<=0 or >n) with 1
2. Use index marking:
   - For value x → mark nums[x-1] as negative
3. First positive index → missing number

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
We use array indices as a hash to track presence of numbers
*/
