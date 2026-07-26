/*
    Problem: Minimum Days to Make M Bouquets
    Pattern: Binary Search on Answers

    Approach:
    1. The minimum possible answer is 1 day, and the maximum possible answer
       is the maximum bloom day in the array.
    2. Apply Binary Search on this range of possible days.
    3. For each candidate day:
       - Traverse the bloomDay array.
       - Count consecutive flowers that have bloomed on or before the current day.
       - Whenever k consecutive flowers are found, form one bouquet and reset
         the consecutive count.
    4. If at least m bouquets can be formed, store the current day as a
       potential answer and search for a smaller day.
    5. Otherwise, search for a larger day.
    6. Return the minimum day required, or -1 if it is impossible.

    Key Insight:
    As the number of days increases, more flowers bloom, so the number of
    bouquets that can be formed never decreases. This monotonic property
    makes Binary Search on the answer space applicable.

    Time Complexity: O(n × log(max(arr)))
    Space Complexity: O(1)
*/

class Solution {
public:
    bool possible(int mid, vector<int>& arr, int k, int m) {
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= mid) {
                count++;

                if (count == k) {
                    count = 0;
                    m--;

                    if (m == 0)
                        return true;
                }
            } else {
                count = 0;
            }
        }

        return false;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(mid, arr, k, m)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
