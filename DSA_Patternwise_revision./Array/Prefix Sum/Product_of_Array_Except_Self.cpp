/*
    Problem: Product of Array Except Self
    Pattern: Prefix Product + Suffix Product

    Approach:
    1. Create an answer array to store prefix products.
    2. Initialize the first element as 1 since there are no elements to its left.
    3. Traverse from left to right:
       - Store the product of all elements before the current index.
    4. Maintain a running suffix product while traversing from right to left.
    5. Multiply each prefix product with the corresponding suffix product to
       obtain the product of all elements except the current one.
    6. Return the resulting array.

    Key Insight:
    The product of all elements except the current element is:

        Prefix Product × Suffix Product

    Instead of building separate prefix and suffix arrays, store prefix
    products in the answer array and use a running suffix product to
    optimize the space complexity.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);

        left[0] = 1;

        // Compute prefix products
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * arr[i - 1];
        }

        // Multiply with suffix products
        int rp = 1;
        for (int i = n - 2; i >= 0; i--) {
            rp *= arr[i + 1];
            left[i] *= rp;
        }

        return left;
    }
};
