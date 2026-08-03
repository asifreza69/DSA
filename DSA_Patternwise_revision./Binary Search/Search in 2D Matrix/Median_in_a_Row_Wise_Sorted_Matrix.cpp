/*
    Problem: Median in a Row Wise Sorted Matrix
    Pattern: Search in 2D Matrix + Binary Search on Answers

    Approach:
    1. The minimum possible median is the smallest first element among all rows.
    2. The maximum possible median is the largest last element among all rows.
    3. The required median position is (rows × columns) / 2.
    4. Apply Binary Search on the value range.
    5. For each candidate value (mid):
       - For every row, use upper_bound() to count the number of elements
         less than or equal to mid.
       - Sum these counts across all rows.
    6. If the count is less than or equal to the required position, search
       in the larger values.
    7. Otherwise, search in the smaller values.
    8. When Binary Search ends, low points to the median.

    Key Insight:
    The matrix is row-wise sorted, so upper_bound() efficiently counts the
    number of elements ≤ mid in each row. Since this count increases
    monotonically with mid, Binary Search on the answer space can be applied.

    Time Complexity: O(n × log(m) × log(maxValue - minValue))
    Space Complexity: O(1)
*/

class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        int required = (n * m) / 2;

        while (low < high) {
            int mid = low + (high - low) / 2;

            int count = 0;

            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(),
                                     mat[i].end(),
                                     mid) - mat[i].begin();
            }

            if (count <= required)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};
