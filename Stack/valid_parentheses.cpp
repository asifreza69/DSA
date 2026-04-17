#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            if (st.empty()) {
                st.push(s[i]);
            }
            else if (s[i] == ']' && st.top() == '[') {
                st.pop();
            }
            else if (s[i] == ')' && st.top() == '(') {
                st.pop();
            }
            else if (s[i] == '}' && st.top() == '{') {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};

/*
Problem: Valid Parentheses (LeetCode 20)

Approach:
Stack (User-defined logic)

Logic:
- Traverse string
- If stack empty → push
- If current char matches top → pop
- Else → push
- At end, stack should be empty

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
Matching brackets cancel each other using stack
*/
