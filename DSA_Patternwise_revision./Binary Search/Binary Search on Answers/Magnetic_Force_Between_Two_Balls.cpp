/*
    Problem: Magnetic Force Between Two Balls
    Pattern: Binary Search on Answers

    Approach:
    1. Sort the basket positions.
    2. The minimum possible magnetic force is 0.
    3. The maximum possible magnetic force is the distance between the
       farthest two baskets.
    4. Apply Binary Search on this range of possible forces.
    5. For each candidate force:
       - Place the first ball in the first basket.
       - Greedily place each subsequent ball in the next basket whose
         distance from the last placed ball is at least the candidate force.
       - If all m balls can be placed, the force is feasible.
    6. If the force is feasible, store it as a potential answer and search
       for a larger minimum force.
    7. Otherwise, search for a smaller force.
    8. Return the maximum feasible minimum magnetic force.

    Key Insight:
    If it is possible to place all balls with a minimum magnetic force d,
    then it is also possible for every force smaller than d. This monotonic
    property makes Binary Search on the answer space applicable.

    Time Complexity: O(n × log(max(position) - min(position)))
    Space Complexity: O(1)
*/

class Solution {
public:
    bool ispossible(int mid, vector<int>& p, int m) {
        int count = 1;
        int currpos = 0;

        for (int i = 1; i < p.size(); i++) {
            if (p[i] - p[currpos] >= mid) {
                count++;
                currpos = i;

                if (count == m) {
                    return true;
                }
            }
        }

        return false;
    }

    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(), p.end());

        int ans = -1;
        int low = 0;
        int high = p[p.size() - 1] - p[0];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (ispossible(mid, p, m)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
