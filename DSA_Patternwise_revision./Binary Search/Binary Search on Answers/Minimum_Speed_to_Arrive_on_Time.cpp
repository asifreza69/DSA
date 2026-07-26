/*
    Problem: Minimum Speed to Arrive on Time
    Pattern: Binary Search on Answers

    Approach:
    1. The minimum possible speed is 1 and the maximum possible speed is 10^7.
    2. Apply Binary Search on the possible speed range.
    3. For each candidate speed:
       - Compute the total travel time.
       - For every train except the last, round the travel time up to the
         nearest integer using ceil().
       - For the last train, use the exact fractional travel time.
    4. If the total time is within the given limit, store the speed as a
       potential answer and search for a smaller speed.
    5. Otherwise, search for a larger speed.
    6. Return the minimum feasible speed, or -1 if no such speed exists.

    Key Insight:
    As the train speed increases, the total travel time never increases.
    This monotonic relationship allows Binary Search on the answer space to
    efficiently find the minimum valid speed.

    Time Complexity: O(n × log(10^7))
    Space Complexity: O(1)
*/

class Solution {
public:
    bool possible(int mid, vector<int>& dist, double hour) {
        double time = 0.0;

        for (int i = 0; i < dist.size(); i++) {
            if (i != dist.size() - 1) {
                time += ceil((double)dist[i] / (double)mid);
            } else {
                time += (double)dist[i] / (double)mid;
            }
        }

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(mid, dist, hour)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
