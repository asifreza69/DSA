/*
    Problem: Koko Eating Bananas
    Pattern: Binary Search on Answers

    Approach:
    1. The minimum possible eating speed is 1 banana/hour.
    2. The maximum possible eating speed is the size of the largest pile.
    3. Apply Binary Search on this range of possible speeds.
    4. For each candidate speed:
       - Calculate the total hours required to eat all piles.
       - If the required hours are within the given limit, store the speed
         as a potential answer and search for a smaller speed.
       - Otherwise, search for a larger speed.
    5. Return the minimum feasible eating speed.

    Key Insight:
    As Koko's eating speed increases, the total hours required never increase.
    This monotonic property makes Binary Search on the answer space applicable.

    Time Complexity: O(n × log(max(arr)))
    Space Complexity: O(1)
*/

class Solution {
public:
    bool solve(int mid, vector<int>& arr, int k) {

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= mid) {
                k--;
            } else {
                int t = arr[i] / mid;

                if (arr[i] % mid == 0) {
                    k -= t;
                } else {
                    k -= (t + 1);
                }
            }
        }

        return k >= 0;
    }

    int kokoEat(vector<int>& arr, int k) {
        int ans = 0;
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (solve(mid, arr, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
