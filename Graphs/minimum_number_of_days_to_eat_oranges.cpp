// LeetCode 1553: Minimum Number of Days to Eat N Oranges
//
// Approach: Breadth First Search (BFS)
//
// Explanation:
// - Each state represents the number of oranges remaining
// - From any state `curr`, we can perform 3 possible actions:
//   1) Eat 1 orange        -> curr - 1
//   2) Eat curr/2 oranges  -> curr / 2 (only if curr is divisible by 2)
//   3) Eat curr/3 oranges  -> curr / 3 (only if curr is divisible by 3)
// - We want to reach state 0 in minimum number of days
//
// Why BFS?
// - Each action takes exactly 1 day
// - BFS guarantees the shortest number of steps to reach 0
//
// To avoid revisiting states, we use a visited set
//
// Time Complexity:
// - Each number from n down to 0 is visited at most once
// - O(n) in worst case
//
// Space Complexity:
// - Queue + visited set
// - O(n)

class Solution {
public:
    int minDays(int n) {

        queue<int> q;                 // BFS queue
        unordered_set<int> visited;   // To avoid revisiting states

        q.push(n);
        visited.insert(n);

        int days = 0;

        // BFS traversal
        while (!q.empty()) {
            int sz = q.size();

            // Process all states at the current day
            while (sz--) {
                int curr = q.front();
                q.pop();

                // If no oranges left
                if (curr == 0)
                    return days;

                // Option 1: Eat 1 orange
                if (!visited.count(curr - 1)) {
                    visited.insert(curr - 1);
                    q.push(curr - 1);
                }

                // Option 2: Eat curr / 2 oranges (if divisible by 2)
                if (curr % 2 == 0 && !visited.count(curr / 2)) {
                    visited.insert(curr / 2);
                    q.push(curr / 2);
                }

                // Option 3: Eat curr / 3 oranges (if divisible by 3)
                if (curr % 3 == 0 && !visited.count(curr / 3)) {
                    visited.insert(curr / 3);
                    q.push(curr / 3);
                }
            }

            // One BFS level completed = one day passed
            days++;
        }

        return -1;
    }
};
