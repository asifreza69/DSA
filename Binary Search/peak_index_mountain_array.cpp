#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;

        while (i < j) {
            int m = i + (j - i) / 2;

            if (arr[m] < arr[m + 1]) {
                i = m + 1;      // increasing slope → peak on right
            } else {
                j = m;          // decreasing slope → peak on left (including m)
            }
        }

        return i; // final peak index
    }
};

/*
Approach (Your Logic):

1. Binary Search on Mountain Array:
   - Use two pointers i (start) and j (end)

2. Find mid:
   - Compare arr[mid] with arr[mid+1]

3. Decision:
   - If arr[mid] < arr[mid+1]
       → we are on increasing slope
       → move right (i = mid + 1)

   - Else
       → we are on decreasing slope
       → peak lies on left or at mid
       → move left (j = mid)

4. Loop ends when:
   - i == j → peak index

5. Return i (or j)

Key Insight:
Peak is the point where increasing turns into decreasing

Time Complexity: O(log n)
Space Complexity: O(1)
*/
