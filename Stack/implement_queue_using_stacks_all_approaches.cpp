#include <stack>
using namespace std;

/*
====================================================
Approach 1: Single Stack + Recursion
====================================================
Push: O(1)
Pop: O(n)
Peek: O(n)
*/

class MyQueue_Recursive {
public:
    stack<int> st;

    void push(int x) {
        st.push(x);
    }

    int pop() {
        int t = st.top();
        st.pop();

        if (st.empty()) {
            return t;
        }

        int res = pop();
        st.push(t);
        return res;
    }

    int peek() {
        int t = st.top();
        st.pop();

        if (st.empty()) {
            st.push(t);
            return t;
        }

        int res = peek();
        st.push(t);
        return res;
    }

    bool empty() {
        return st.empty();
    }
};


/*
====================================================
Approach 2: Two Stacks (Naive)
====================================================
Push: O(1)
Pop: O(n)
Peek: O(n)
*/

class MyQueue_TwoStacks_Naive {
public:
    stack<int> st1, st2;

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        int ans = st2.top();
        st2.pop();

        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

        return ans;
    }

    int peek() {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        int ans = st2.top();

        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

        return ans;
    }

    bool empty() {
        return st1.empty();
    }
};


/*
====================================================
Approach 3: Two Stacks (Optimized - BEST)
====================================================
Push: O(1)
Pop: Amortized O(1)
Peek: Amortized O(1)
*/

class MyQueue_Optimized {
private:
    stack<int> s1, s2;

public:
    MyQueue_Optimized() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};


/*
====================================================
Key Insights
====================================================
- Queue = FIFO
- Stack = LIFO

Approach 1:
- Use recursion to access bottom element

Approach 2:
- Reverse using second stack every time

Approach 3 (BEST):
- Use two stacks
- Transfer only when needed
- Achieves amortized O(1)

====================================================
*/
