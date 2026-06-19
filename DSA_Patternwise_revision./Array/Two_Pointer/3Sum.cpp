# 0015_3Sum.cpp

```cpp
/*
    Problem: 3Sum
    Pattern: Two Pointers

    Approach:
    1. Sort the array.
    2. Fix one element nums[i] and find two numbers in the remaining array
       whose sum equals -nums[i].
    3. Use two pointers:
       - Left pointer starts at i + 1.
       - Right pointer starts at n - 1.
    4. If the current sum is greater than the target, move the right pointer.
    5. If the current sum is smaller than the target, move the left pointer.
    6. If a triplet is found, store it and skip duplicate values to avoid
       repeated triplets.
    7. Skip duplicate values for the fixed element as well.

    Time Complexity: O(n^2)
    Space Complexity: O(1) [excluding the output array]
*/

class Solution {
public:
    vector<vector<int>> result;

    void twosum(int i, int j, vector<int>& nums, int target) {
        while (i < j) {
            if (nums[i] + nums[j] > target) {
                j--;
            }
            else if (nums[i] + nums[j] < target) {
                i++;
            }
            else {
                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;

                result.push_back({-target, nums[i], nums[j]});

                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -nums[i];
            twosum(i + 1, n - 1, nums, target);
        }

        return result;
    }
};
```
