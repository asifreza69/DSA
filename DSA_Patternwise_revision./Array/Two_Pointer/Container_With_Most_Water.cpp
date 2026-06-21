
/*
    Problem: Container With Most Water
    Pattern: Two Pointers

    Approach:
    1. Place one pointer at the beginning and another at the end of the array.
    2. The width of the container is (j - i).
    3. The height of the container is determined by the smaller of the two heights.
    4. Calculate the current area and update the maximum area found so far.
    5. Move the pointer corresponding to the smaller height:
       - If arr[i] < arr[j], increment i.
       - Otherwise, decrement j.
    6. Continue until the two pointers meet.

    Key Insight:
    The area is limited by the shorter line. Moving the taller line cannot
    increase the area, so we always move the pointer with the smaller height.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        int ans = 0;

        while (i < j) {
            if (arr[i] < arr[j]) {
                ans = max(ans, arr[i] * (j - i));
                i++;
            }
            else {
                ans = max(ans, arr[j] * (j - i));
                j--;
            }
        }

        return ans;
    }
};
