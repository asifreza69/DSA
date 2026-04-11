#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& h) {
        int i = 0, j = h.size() - 1;
        int ans = 0;

        while (i < j) {
            int width = j - i;
            int height = min(h[i], h[j]);

            ans = max(ans, width * height);

            // Move the smaller height pointer
            if (h[i] <= h[j]) {
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};

/*
Problem: Container With Most Water (LeetCode 11)

Approach:
Two Pointer Technique

Logic:
- Start with two pointers at ends
- Calculate area = width × min(height)
- Move the pointer with smaller height

Why?
- Because area is limited by smaller height
- Moving larger height won’t increase area

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Always move the pointer with smaller height to try for a better area
*/
