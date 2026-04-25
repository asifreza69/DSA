#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool ispossible(int capacity, vector<int>& weights, int days) {
        int curr = 0;
        int usedDays = 1;

        for (int w : weights) {
            if (curr + w <= capacity) {
                curr += w;
            } else {
                curr = w;
                usedDays++;
            }
        }

        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (ispossible(mid, weights, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

/*
Problem: Capacity to Ship Packages Within D Days

Approach:
Binary Search on Answer

Time Complexity: O(n log(sum))
Space Complexity: O(1)

Key Insight:
Capacity is monotonic → apply binary search
*/
