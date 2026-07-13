/*
    Problem: Maximum Product Subarray
    Pattern: Kadane's Algorithm (Product Variant)

    Approach:
    1. Traverse the array from left to right while maintaining a running product.
    2. Update the maximum product after processing each element.
    3. If the running product becomes zero, reset it to 1 since any product
       beyond zero starts a new subarray.
    4. Repeat the same process from right to left.
    5. The maximum product obtained from both traversals is the answer.

    Key Insight:
    Negative numbers can flip the sign of the product. A single left-to-right
    traversal may miss the optimal subarray when an odd number of negatives
    exists. Traversing from both directions ensures every possible maximum
    product subarray is considered.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxi = INT_MIN;
        int prod = 1;

        // Left to Right
        for (int i = 0; i < arr.size(); i++) {
            prod *= arr[i];
            maxi = max(maxi, prod);

            if (prod == 0) {
                prod = 1;
            }
        }

        // Right to Left
        prod = 1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            prod *= arr[i];
            maxi = max(maxi, prod);

            if (prod == 0) {
                prod = 1;
            }
        }

        return maxi;
    }
};
