#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[high]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return nums[low];
    }
};

/*
Problem: Find Minimum in Rotated Sorted Array (LC 153)

Approach:
Binary Search (modified)

Time Complexity: O(log n)
Space Complexity: O(1)

Key Insight:
Compare mid with high to decide search space
*/
