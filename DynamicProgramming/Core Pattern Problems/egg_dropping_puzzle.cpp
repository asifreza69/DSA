class Solution {
public:
    int t[1001][1001];

    int solve(int eggs, int floors) {

        // Only one egg left:
        // must try every floor.
        if(eggs == 1) {
            return floors;
        }

        // 0 or 1 floor
        if(floors == 0 || floors == 1) {
            return floors;
        }

        // Memoized result
        if(t[eggs][floors] != -1) {
            return t[eggs][floors];
        }

        int low = 1;
        int high = floors;
        int ans = INT_MAX;

        /*
        Binary search is possible because:

        breakCase   increases as mid increases.
        surviveCase decreases as mid increases.

        We want to minimize:
        1 + max(breakCase, surviveCase)
        */
        while(low <= high) {

            int mid =
                low + (high - low) / 2;

            // Egg breaks
            int breakCase =
                solve(eggs - 1, mid - 1);

            // Egg survives
            int surviveCase =
                solve(eggs, floors - mid);

            int temp =
                1 + max(breakCase, surviveCase);

            ans = min(ans, temp);

            // Move toward larger side
            if(breakCase < surviveCase) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return t[eggs][floors] = ans;
    }

    int eggDrop(int n, int k) {

        memset(t, -1, sizeof(t));

        return solve(n, k);
    }
};

/*
==========================
🔥 EGG DROPPING PUZZLE
==========================

Goal:
Find the minimum number of
attempts needed in the worst case
to determine the critical floor.

--------------------------------

Critical Floor:
Highest floor from which egg
does not break.

--------------------------------

🧠 Core Idea:

Drop an egg from floor x.

Case 1:
Egg breaks
→ search below x
→ solve(eggs - 1, x - 1)

Case 2:
Egg survives
→ search above x
→ solve(eggs, floors - x)

Worst case:
1 + max(breakCase, surviveCase)

Choose x that minimizes this.

--------------------------------

State:

solve(eggs, floors)

= minimum attempts needed.

--------------------------------

Base Cases:

eggs == 1
→ try all floors
→ floors

floors == 0 or 1
→ floors

--------------------------------

Optimization:

Use Binary Search because:
- breakCase increases with x
- surviveCase decreases with x

This reduces transition cost.

--------------------------------

Example:

2 eggs, 10 floors

Answer = 4

--------------------------------

⏱️ Time Complexity:
Approximately O(eggs × floors × log floors)

--------------------------------

🧠 Space Complexity:
O(eggs × floors)

--------------------------------

🧩 Pattern:
Minimax DP

--------------------------------

🎯 Category:
Dynamic Programming → Partition DP

--------------------------------

🧠 Interview One-Liner:

For every drop floor, consider
the worst of break and survive
cases, and minimize that value.

*/
