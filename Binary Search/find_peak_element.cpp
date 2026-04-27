#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;

        while (l < h) {
            int m = l + (h - l) / 2;

            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                h = m;
            }
        }

        return l;
    }
};

/*
Problem: Find Peak Element (LC 162)

Approach:
Binary Search (Peak Finding)

Time Complexity: O(log n)
Space Complexity: O(1)

Key Insight:
Move towards the side which is increasing
*/
