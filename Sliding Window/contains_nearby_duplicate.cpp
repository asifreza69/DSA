#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // value → last index

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k) {
                return true;
            }
            mp[nums[i]] = i;
        }

        return false;
    }
};

/*
Problem: Contains Duplicate II (LeetCode 219)

Approach:
HashMap to store last index of each element

Logic:
- Traverse array
- If element seen before:
   → check distance between indices
   → if <= k → return true
- Update latest index in map

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
Only the most recent index matters for minimum distance
*/
