/*
    Problem: Equilibrium Point
    Pattern: Prefix Sum

    Approach:
    1. Compute the total sum of all elements in the array.
    2. Maintain a variable leftSum to store the sum of elements on the left.
    3. Traverse the array:
       - Remove the current element from totalSum to obtain the right sum.
       - Compare leftSum and right sum.
       - If they are equal, the current index is the equilibrium point.
       - Otherwise, add the current element to leftSum.
    4. If no such index exists, return -1.

    Key Insight:
    Instead of precomputing prefix and suffix arrays, maintain the left sum
    while updating the right sum dynamically using the total sum. This
    optimizes the space complexity to O(1).

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int findEquilibrium(vector<int> &arr) {
        int totalSum = 0;

        for (int x : arr)
            totalSum += x;

        int leftSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            totalSum -= arr[i];

            if (leftSum == totalSum)
                return i;

            leftSum += arr[i];
        }

        return -1;
    }
};
