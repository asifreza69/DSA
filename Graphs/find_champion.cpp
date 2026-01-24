// LeetCode 2923: Find Champion I
// Approach: Mark all nodes that have incoming edges.
//           The champion is the only node with no incoming edges.
// Time Complexity: O(n + m)   where m = edges.size()
// Space Complexity: O(n)



class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, true);

        // Mark nodes that have incoming edges
        for(auto it : edges){
            visited[it[1]] = false;
        }

        int count = 0, ans = -1;

        // Find the node with no incoming edges
        for(int i = 0; i < n; i++){
            if(visited[i] == true){
                count++;
                ans = i;
            }
        }

        // If more than one such node exists, no unique champion
        if(count > 1){
            return -1;
        }
        return ans;
    }
};
