/*
    Problem: Capacity to Ship Packages Within D Days
    Pattern: Binary Search on Answers

    Approach:
    1. The minimum possible ship capacity is the maximum weight among all packages.
    2. The maximum possible ship capacity is the sum of all package weights.
    3. Apply Binary Search on this capacity range.
    4. For each candidate capacity:
       - Simulate shipping the packages in order.
       - If adding a package exceeds the capacity, start a new day.
       - Count the total days required.
    5. If the required days are within the given limit, store the capacity
       as a potential answer and search for a smaller capacity.
    6. Otherwise, search for a larger capacity.
    7. Return the minimum feasible ship capacity.

    Key Insight:
    As the ship capacity increases, the number of days required never
    increases. This monotonic property makes Binary Search on the answer
    space applicable.

    Time Complexity: O(n × log(sum(arr)))
    Space Complexity: O(1)
*/

class Solution {
public:
    bool possible(int mid, vector<int>& arr, int d) {
        int sum = 0;
        int count = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > mid)
                return false;

            sum += arr[i];

            if (sum > mid) {
                count++;
                sum = arr[i];
            }
        }

        return count <= d;
    }

    int leastWeightCapacity(vector<int>& arr, int D) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(mid, arr, D)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
