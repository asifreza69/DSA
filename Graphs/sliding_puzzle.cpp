// LeetCode 773: Sliding Puzzle
//
// Approach: Breadth First Search (BFS)
//
// Explanation:
// - The 2x3 board is converted into a string of length 6
// - Each unique string represents one board configuration (state)
// - We need to find the minimum number of moves to reach "123450"
// - BFS is used because it guarantees the shortest path in an unweighted graph
//
// State Representation:
// - Example board:
//     1 0 3
//     4 2 5
//   is represented as string: "103425"
//
// Transitions:
// - The position of '0' (empty cell) determines valid swaps
// - A predefined adjacency list tells which indices '0' can swap with
//
// Algorithm:
// 1. Push the starting state into the queue
// 2. For each state, try all valid swaps of '0'
// 3. Push new states into the queue if not visited
// 4. Stop when the target state is reached
//
// Time Complexity:
// - Total possible states = 6! = 720
// - Worst case: O(6!)
//
// Space Complexity:
// - Queue + Visited set store up to 6! states
// - Space: O(6!)

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        // Convert the 2x3 board into a string
        string start = "";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }

        // Target configuration
        string target = "123450";

        // BFS queue
        queue<string> que;
        que.push(start);

        // Adjacency list for valid swaps of '0'
        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        // Visited states to avoid revisiting
        unordered_set<string> visited;
        visited.insert(start);

        int level = 0;  // Number of moves

        // BFS traversal
        while(!que.empty()) {
            int n = que.size();

            // Process all states at the current level
            while(n--) {
                string curr = que.front();
                que.pop();

                // If target is reached
                if(curr == target) {
                    return level;
                }

                // Find the index of '0'
                int indexOfZero = curr.find('0');

                // Try all valid swaps
                for(int swapIdx : mp[indexOfZero]) {
                    string newState = curr;
                    swap(newState[indexOfZero], newState[swapIdx]);

                    // Push new state if not visited
                    if(visited.find(newState) == visited.end()) {
                        que.push(newState);
                        visited.insert(newState);
                    }
                }
            }
            level++;
        }

        // Target not reachable
        return -1;
    }
};
