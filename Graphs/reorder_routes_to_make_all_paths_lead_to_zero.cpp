// LeetCode 1466: Reorder Routes to Make All Paths Lead to the City Zero
// Approach: Build a graph where each edge stores whether it needs reordering.
//           Perform DFS from node 0 and count edges that are directed away from it.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int count = 0;

    void dfs(int i, int parent, unordered_map<int, vector<pair<int,int>>>& mp){
        for(auto it : mp[i]){
            int v = it.first;
            int check = it.second;

            if(v != parent){
                if(check == 1){
                    count++;
                }
                dfs(v, i, mp);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int,int>>> mp;

        // Build graph with direction information
        for(auto it : connections){
            int a = it[0];
            int b = it[1];
            mp[a].push_back({b, 1});  // Original direction
            mp[b].push_back({a, 0});  // Reverse direction
        }

        dfs(0, -1, mp);
        return count;
    }
};
