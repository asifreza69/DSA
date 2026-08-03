/*
    Problem: Kth Smallest Element in a Sorted Matrix
    Pattern: Search in 2D Matrix + Binary Search on Answers

    Approach:
    1. The minimum possible answer is the top-left element.
    2. The maximum possible answer is the bottom-right element.
    3. Apply Binary Search on this value range.
    4. For each candidate value (mid):
       - For every row, use upper_bound() to count how many elements are
         less than or equal to mid.
       - Sum these counts across all rows.
    5. If the count is smaller than k, search in the larger values.
    6. Otherwise, search in the smaller values while keeping mid as a
       potential answer.
    7. When Binary Search ends, low points to the kth smallest element.

    Key Insight:
    Instead of searching indices, Binary Search is performed on the value
    range. The number of elements ≤ mid is monotonic, making Binary Search
    on the answer space applicable.

    Time Complexity: O(n × log n × log(maxValue - minValue))
    Space Complexity: O(1)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();

        int low = mat[0][0];
        int high = mat[n - 1][n - 1];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int count = 0;

            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(),
                                     mat[i].end(),
                                     mid) - mat[i].begin();
            }

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
