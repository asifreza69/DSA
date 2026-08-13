/*
    Problem: Next Greater Element
    Pattern: Monotonic Stack (Decreasing Stack)

    Approach:
    1. Traverse the array from right to left.
    2. Maintain a decreasing stack containing potential next greater elements.
    3. Remove all elements from the stack that are smaller than or equal to
       the current element because they can never become the next greater element.
    4. The top of the stack becomes the next greater element.
    5. Push the current element onto the stack.
    6. Repeat the process for all elements.

    Key Insight:
    While moving from right to left, the stack always stores elements that are
    greater than the current element. Therefore, the top of the stack always
    represents the nearest greater element on the right.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> st;
        st.push(-1);

        vector<int> ans(arr.size(), -1);

        for (int i = arr.size() - 1; i >= 0; i--) {

            while (st.top() <= arr[i] && st.top() != -1) {
                st.pop();
            }

            ans[i] = st.top();

            st.push(arr[i]);
        }

        return ans;
    }
};
