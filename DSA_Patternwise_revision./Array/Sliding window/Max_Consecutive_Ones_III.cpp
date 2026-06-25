/*
    Problem: Max Consecutive Ones III
    Pattern: Sliding Window (Variable Size)

    Approach:
    1. Maintain a sliding window using two pointers i and j.
    2. Expand the window by moving j.
    3. Whenever a 0 is encountered, consume one available flip (k--).
    4. If k becomes negative, the window is invalid:
       - Shrink the window from the left.
       - If the removed element is 0, restore one flip (k++).
    5. Update the maximum valid window size after each iteration.

    Key Insight:
    The window remains valid as long as it contains at most k zeros.
    Whenever the number of zeros exceeds k, shrink the window until it
    becomes valid again.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int ans = 0;
        int i = 0, j = 0;

        while (j < arr.size()) {
            if (arr[j] == 0) {
                k--;
            }

            while (k < 0) {
                if (arr[i] == 0) {
                    k++;
                }
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
