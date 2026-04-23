#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

/*
Problem: Search Insert Position (LC 35)

Approach:
Binary Search using STL (lower_bound)

Logic:
- Finds first element >= target
- Returns its index
- If not found, gives correct insertion position

Time Complexity:
O(log n)

Space Complexity:
O(1)

Key Insight:
lower_bound directly solves this problem
*/
