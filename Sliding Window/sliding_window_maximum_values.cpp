#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        int i = 0, j = 0;

        while (j < nums.size()) {
            // Maintain decreasing order
            while (!dq.empty() && nums[j] > dq.back()) {
                dq.pop_back();
            }

            dq.push_back(nums[j]);

            // Window size reached
            if (j - i + 1 == k) {
                ans.push_back(dq.front());

                // Remove element going out of window
                if (nums[i] == dq.front()) {
                    dq.pop_front();
                }

                i++;
            }

            j++;
        }

        return ans;
    }
};

/*
Problem: Sliding Window Maximum (LeetCode 239)

Approach:
Monotonic Deque (Value-based)

Logic:
- Maintain decreasing deque
- Front always gives maximum
- Remove outgoing element if equal to front

Time Complexity:
O(n)

Space Complexity:
O(k)

Key Insight:
Deque stores useful elements in decreasing order
*/
