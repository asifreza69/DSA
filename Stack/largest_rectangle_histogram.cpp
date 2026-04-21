#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;

        vector<int> prev(n), next(n);

        // Previous Smaller
        st.push(-1);
        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && h[i] <= h[st.top()]) {
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }

        // clear stack
        while (!st.empty()) st.pop();

        // Next Smaller
        st.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != -1 && h[i] <= h[st.top()]) {
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (next[i] == -1) next[i] = n;

            int width = next[i] - prev[i] - 1;
            int area = width * h[i];

            maxi = max(maxi, area);
        }

        return maxi;
    }
};

/*
Problem: Largest Rectangle in Histogram (LC 84)

Approach:
Monotonic Stack (Prev + Next Smaller)

Time Complexity: O(n)
Space Complexity: O(n)

Key Insight:
Each bar expands till smaller element on both sides
*/
