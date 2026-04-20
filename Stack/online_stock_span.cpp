#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st; // {price, span}

    StockSpanner() {}

    int next(int price) {
        int span = 1;

        // merge spans of smaller/equal prices
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

/*
Problem: Online Stock Span (LeetCode 901)

Approach:
Monotonic Stack (Decreasing)

Logic:
- Maintain decreasing stack
- Pop all smaller/equal prices
- Add their span to current
- Push {price, span}

Time Complexity:
Amortized O(1) per operation
Total O(n)

Space Complexity:
O(n)

Key Insight:
Store span instead of individual elements to compress operations
*/
