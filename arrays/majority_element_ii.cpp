#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int cd1 = INT_MIN, cd2 = INT_MIN;

        // Step 1: Find candidates
        for (int num : nums) {
            if (num == cd1) {
                count1++;
            }
            else if (num == cd2) {
                count2++;
            }
            else if (count1 == 0) {
                cd1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                cd2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify candidates
        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == cd1) count1++;
            else if (num == cd2) count2++;
        }

        vector<int> ans;
        if (count1 > nums.size() / 3) ans.push_back(cd1);
        if (count2 > nums.size() / 3) ans.push_back(cd2);

        return ans;
    }
};

/*
Problem: Majority Element II (LeetCode 229)

Approach:
Used Boyer-Moore Voting Algorithm (extended for n/3 case)

Logic:
- At most 2 elements can appear more than n/3 times
- First pass → find potential candidates
- Second pass → verify counts

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Generalization of majority element (> n/2) to (> n/3)
*/
