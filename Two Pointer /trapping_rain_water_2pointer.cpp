/*
Problem: Trapping Rain Water (LeetCode 42)

Approach:
Two-pointer technique with constant space.

Logic:
- Maintain left and right pointers
- Track leftMax and rightMax
- Process the smaller height side:
   → ensures correct water calculation

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Water depends on the smaller boundary, so process that side first.
*/

class Solution {
public:
    int trap(vector<int>& height) {
         if (height.size() == 0) return 0;

        int ans=0;
        int leftboundary=0;
        int rightboundary=height.size()-1;
        int leftmax=height[0];
        int rightmax=height[height.size()-1];
        while(leftboundary<rightboundary){
                if(leftmax<=rightmax){
                    ans+=leftmax-height[leftboundary];
                    leftboundary++;
                    leftmax=max(height[leftboundary],leftmax);
                }else {
                    ans+=rightmax-height[rightboundary];
                    rightboundary--;
                    rightmax=max(height[rightboundary],rightmax);
                }
        }
        return ans;
    }
};
