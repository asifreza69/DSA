// LeetCode 15: 3Sum
// Approach:
// 1. Sort the array
// 2. Fix one element and use two-pointer technique to find remaining two elements
// 3. Skip duplicates to ensure unique triplets
// Time Complexity: O(n^2)
// Space Complexity: O(1) (excluding output)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(int target, int i, int j, vector<int>& nums, vector<vector<int>>& ans) {
        int low = i, high = j;

        while (low < high) {
            int sum = nums[low] + nums[high];

            if (sum > target) {
                high--;
            } 
            else if (sum < target) {
                low++;
            } 
            else {
                ans.push_back({-target, nums[low], nums[high]});

                low++;
                high--;

                while (low < high && nums[low] == nums[low - 1]) low++;
                while (low < high && nums[high] == nums[high + 1]) high--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            solve(-nums[i], i + 1, nums.size() - 1, nums, ans);
        }
        return ans;
    }
};
