/*
    Problem: Split Array Largest Sum
    Pattern: Binary Search on Answers

    Approach:
    1. The minimum possible largest subarray sum is the maximum element in the array.
    2. The maximum possible largest subarray sum is the sum of all elements.
    3. Apply Binary Search on this range of possible answers.
    4. For each candidate maximum sum:
       - Traverse the array and greedily form subarrays.
       - If adding the current element exceeds the limit, start a new subarray.
       - Count the number of subarrays formed.
    5. If the array can be split into at most k subarrays, store the current
       value as a potential answer and search for a smaller maximum sum.
    6. Otherwise, search for a larger maximum sum.
    7. Return the minimum possible largest subarray sum.

    Key Insight:
    As the allowed maximum subarray sum increases, the number of subarrays
    required never increases. This monotonic property enables Binary Search
    on the answer space.

    Time Complexity: O(n × log(sum(arr)))
    Space Complexity: O(1)
*/

class Solution {
public:
    bool possible(long long mid, vector<int>& arr, int k) {
        long long sum = 0;
        int count = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (sum + arr[i] <= mid) {
                sum += arr[i];
            } else {
                count++;
                sum = arr[i];

                if (count > k)
                    return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& arr, int k) {
        if (k > arr.size())
            return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (possible(mid, arr, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};
