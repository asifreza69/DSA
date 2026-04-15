#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;

        int i = 0, j = arr.size() - 1;

        while (i <= j) {
            int diff1 = abs(arr[i] - x);
            int diff2 = abs(arr[j] - x);

            if (diff1 > diff2) {
                pq.push({diff2, arr[j]});
                j--;
            } else {
                pq.push({diff1, arr[i]});
                i++;
            }

            if (pq.size() > k) {
                pq.pop(); // remove farthest
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
Problem: Find K Closest Elements (LeetCode 658)

Approach:
Two Pointer + Max Heap

Logic:
- Compare elements from both ends
- Push closer one into heap
- Maintain heap size k
- Remove farthest element if size exceeds k
- Return sorted result

Time Complexity:
O(n log k)

Space Complexity:
O(k)

Key Insight:
Heap keeps track of k closest elements
*/
