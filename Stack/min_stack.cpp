#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;   // main stack
    stack<int> minSt; // stack to track minimum

    MinStack() {}

    void push(int val) {
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
        st.push(val);
    }

    void pop() {
        if (!minSt.empty() && st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

/*
Problem: Min Stack (LeetCode 155)

Approach:
Two Stacks

Logic:
- Main stack stores all elements
- Min stack stores minimum elements
- Push to min stack only when val <= current min
- Pop from min stack when top matches

Time Complexity:
All operations → O(1)

Space Complexity:
O(n)

Key Insight:
Maintain a separate stack for tracking minimum values
*/
