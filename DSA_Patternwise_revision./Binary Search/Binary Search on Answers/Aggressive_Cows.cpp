/*
    Problem: Aggressive Cows
    Pattern: Binary Search on Answers

    Approach:
    1. Sort the stall positions.
    2. The minimum possible distance between two cows is 0.
    3. The maximum possible distance is the difference between the last and
       first stall positions.
    4. Apply Binary Search on the possible distance range.
    5. For each candidate distance:
       - Place the first cow in the first stall.
       - Greedily place each subsequent cow in the next stall whose distance
         from the last placed cow is at least the candidate distance.
       - If all k cows can be placed, the distance is feasible.
    6. If the distance is feasible, store it as a potential answer and search
       for a larger minimum distance.
    7. Otherwise, search for a smaller distance.
    8. Return the maximum feasible minimum distance.

    Key Insight:
    If it is possible to place all cows with a minimum distance d, then it is
    also possible for every distance smaller than d. This monotonic property
    allows Binary Search on the answer space.

    Time Complexity: O(n × log(max(arr) - min(arr)))
    Space Complexity: O(1)
*/

class Solution {
public:
    bool possible(int mid, vector<int>& arr, int k) {
        int cow = 1;
        int lastpos = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastpos >= mid) {
                cow++;
                lastpos = arr[i];
            }

            if (cow == k)
                return true;
        }

        return false;
    }

    int aggressiveCows(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int low = 0;
        int high = arr[n - 1] - arr[0];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(mid, arr, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
