#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto &t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int t1 = st.top(); st.pop();
                int t2 = st.top(); st.pop();

                if (t == "+") st.push(t2 + t1);
                else if (t == "-") st.push(t2 - t1);
                else if (t == "*") st.push(t2 * t1);
                else st.push(t2 / t1);
            } 
            else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};

/*
Problem: Evaluate Reverse Polish Notation (LeetCode 150)

Approach:
Stack

Logic:
- Traverse tokens
- If number → push
- If operator:
   → pop two elements
   → apply operation
   → push result

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
Stack naturally fits postfix evaluation
*/
