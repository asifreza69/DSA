
/*
    Problem: Two Sum II - Input Array Is Sorted
    Pattern: Two Pointers

    Approach:
    1. Place one pointer at the beginning and another at the end of the array.
    2. Compute the sum of elements at both pointers.
    3. If the sum is greater than the target, move the right pointer left.
    4. If the sum is smaller than the target, move the left pointer right.
    5. If the sum equals the target, return the 1-based indices.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            if (nums[i] + nums[j] > target) {
                j--;
            } else if (nums[i] + nums[j] == target) {
                return {i + 1, j + 1};
            } else {
                i++;
            }
        }

        return {-1, -1};
    }
};

