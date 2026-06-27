/*
    Problem: Sliding Window Maximum
    Pattern: Sliding Window + Monotonic Deque

    Approach:
    1. Maintain a deque in decreasing order of elements.
    2. Before inserting nums[j], remove all smaller elements from the back
       since they can never become the maximum while nums[j] is in the window.
    3. Insert nums[j] into the deque.
    4. Once the window size becomes k:
       - The front of the deque represents the maximum element.
       - Add it to the answer.
       - If the outgoing element equals the front of the deque,
         remove it before sliding the window.
    5. Continue until the entire array is processed.

    Key Insight:
    The deque always stores the window elements in decreasing order.
    Hence, the front of the deque is always the maximum element of the
    current window, allowing each element to be processed at most twice.

    Time Complexity: O(n)
    Space Complexity: O(k)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int i = 0, j = 0;

        while (j < nums.size()) {
            while (!q.empty() && q.back() < nums[j]) {
                q.pop_back();
            }

            q.push_back(nums[j]);

            if (j - i + 1 == k) {
                ans.push_back(q.front());

                if (nums[i] == q.front()) {
                    q.pop_front();
                }

                i++;
            }

            j++;
        }

        return ans;
    }
};
