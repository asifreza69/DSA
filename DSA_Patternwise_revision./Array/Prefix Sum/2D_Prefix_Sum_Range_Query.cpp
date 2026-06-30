/*
    Problem: 2D Prefix Sum Range Query
    Pattern: 2D Prefix Sum

    Approach:
    1. Convert the given matrix into its 2D prefix sum representation.
    2. For every cell (i, j), store the sum of all elements in the rectangle
       from (0, 0) to (i, j).

       prefix[i][j] =
           mat[i][j]
         + prefix[i-1][j]
         + prefix[i][j-1]
         - prefix[i-1][j-1]

    3. For each query (x1, y1, x2, y2):
       - Start with the prefix sum at (x2, y2).
       - Remove the extra area above the rectangle.
       - Remove the extra area to the left of the rectangle.
       - Add back the overlapping region that was subtracted twice.
    4. Store the computed sum for every query.

    Key Insight:
    A 2D Prefix Sum allows the sum of any submatrix to be computed in O(1)
    after O(m × n) preprocessing.

        Sum(x1, y1, x2, y2)
        = prefix[x2][y2]
        - prefix[x1-1][y2]
        - prefix[x2][y1-1]
        + prefix[x1-1][y1-1]

    Time Complexity:
    - Building Prefix Sum: O(m × n)
    - Each Query: O(1)
    - Total: O(m × n + q)

    Space Complexity: O(1)
    (The prefix sum is built in-place by modifying the input matrix.)
*/

class Solution {
public:
    vector<int> prefixSum2D(vector<vector<int>>& mat,
                            vector<vector<int>>& queries) {

        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;

        // Build 2D Prefix Sum
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                else if (i == 0)
                    mat[i][j] += mat[i][j - 1];

                else if (j == 0)
                    mat[i][j] += mat[i - 1][j];

                else
                    mat[i][j] += mat[i - 1][j]
                               + mat[i][j - 1]
                               - mat[i - 1][j - 1];
            }
        }

        // Answer Queries
        for (auto& q : queries) {

            int x1 = q[0];
            int y1 = q[1];
            int x2 = q[2];
            int y2 = q[3];

            int sum = mat[x2][y2];

            if (x1 > 0)
                sum -= mat[x1 - 1][y2];

            if (y1 > 0)
                sum -= mat[x2][y1 - 1];

            if (x1 > 0 && y1 > 0)
                sum += mat[x1 - 1][y1 - 1];

            ans.push_back(sum);
        }

        return ans;
    }
};
