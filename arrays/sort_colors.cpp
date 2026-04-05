#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

/*
Problem: Sort Colors (LeetCode 75)

Approach:
Used Dutch National Flag Algorithm with three pointers:
- low → position for 0
- mid → current element
- high → position for 2

Logic:
- If element is 0 → swap with low, move both pointers
- If element is 1 → just move mid
- If element is 2 → swap with high, decrease high (mid stays)

Time Complexity: O(n)
Space Complexity: O(1)

This is an in-place one-pass solution.
*/
