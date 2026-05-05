#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> mp;
    int num;
    vector<string> ans;

    bool dfs(string start, vector<string>& path){
        path.push_back(start);

        // If all tickets used
        if(path.size() == num + 1){
            ans = path;
            return true;
        }

        auto &neighbours = mp[start];

        for(int i = 0; i < neighbours.size(); i++){
            string next = neighbours[i];

            // remove edge (use ticket)
            neighbours.erase(neighbours.begin() + i);

            if(dfs(next, path)) return true;

            // backtrack
            neighbours.insert(neighbours.begin() + i, next);
        }

        path.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        num = tickets.size();

        // Build graph
        for(auto &t : tickets){
            mp[t[0]].push_back(t[1]);
        }

        // Sort to ensure lexicographically smallest answer
        for(auto &p : mp){
            sort(p.second.begin(), p.second.end());
        }

        vector<string> path;
        dfs("JFK", path);

        return ans;
    }
};

/*
==========================
🔥 APPROACH EXPLAINED
==========================

Goal:
Use ALL tickets exactly once → form valid path

--------------------------------

🧠 Idea:

- This is a graph traversal problem
- Each ticket = directed edge
- Need path that uses all edges exactly once

--------------------------------

⚠️ Important:
Return lexicographically smallest itinerary

--------------------------------

Steps:

1. Build adjacency list
2. Sort neighbours (for smallest lex order)
3. Use DFS + Backtracking:
   - Try each edge
   - Remove it (mark used)
   - Recurse
   - If fail → restore (backtrack)

--------------------------------

Example:

tickets:
[JFK → KUL]
[JFK → NRT]
[NRT → JFK]

Sorted:
JFK → [KUL, NRT]

Path:
JFK → NRT → JFK → KUL ✅

--------------------------------

Time Complexity:
Worst: O(E!)
(but constraints manageable)

--------------------------------

🧠 Interview One-Liner:

"Use DFS with backtracking and lexicographical sorting to build Eulerian path"

*/
