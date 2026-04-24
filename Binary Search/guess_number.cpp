/**
 * Forward declaration of guess API.
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int res = guess(m);

            if (res > 0) {
                l = m + 1;
            }
            else if (res < 0) {
                r = m - 1;
            }
            else {
                return m;
            }
        }

        return -1; // theoretically unreachable
    }
};

/*
Problem: Guess Number Higher or Lower (LC 374)

Approach:
Binary Search on Answer

Time Complexity: O(log n)
Space Complexity: O(1)

Key Insight:
API gives direction → eliminate half search space
*/
