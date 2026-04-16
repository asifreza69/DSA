#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& o) {
        stack<int> st;

        for (auto &op : o) {
            if (op == "D") {
                st.push(2 * st.top());
            }
            else if (op == "+") {
                int p1 = st.top(); st.pop();
                int p2 = st.top();
                st.push(p1);
                st.push(p1 + p2);
            }
            else if (op == "C") {
                st.pop();
            }
            else {
                st.push(stoi(op));
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

/*
Problem: Baseball Game (LeetCode 682)

Approach:
Stack Simulation

Logic:
- "D" → double last score
- "+" → sum of last two scores
- "C" → remove last score
- Number → push as score

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
Stack keeps track of valid scores in order
*/
