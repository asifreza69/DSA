#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        sort(p.begin(), p.end());

        int i = 0, j = p.size() - 1;
        int count = 0;

        while (i <= j) {
            if (p[i] + p[j] <= l) {
                i++;  // pair lightest with heaviest
            }
            j--;      // heaviest always goes
            count++;
        }

        return count;
    }
};

/*
Problem: Boats to Save People (LeetCode 881)

Approach:
Greedy + Two Pointer

Logic:
- Sort the array
- Try pairing lightest (i) with heaviest (j)
- If sum <= limit → move both
- Else → send heaviest alone

Time Complexity:
O(n log n) (sorting)

Space Complexity:
O(1)

Key Insight:
To minimize boats, always try to pair the heaviest person
with the lightest possible person.
*/
