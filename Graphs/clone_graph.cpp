// LeetCode 133: Clone Graph
// Approach: Use DFS with a hash map to create deep copies of nodes.
//           The map stores original node -> cloned node mapping to avoid duplicates.
// Time Complexity: O(V + E)   where V = number of nodes, E = number of edges
// Space Complexity: O(V)

#include <unordered_map>
#include <vector>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    void dfs(Node* node, Node* newclone){
        for(Node* it : node->neighbors){
            if(mp.find(it) == mp.end()){
                Node* clone = new Node(it->val);
                mp[it] = clone;
                newclone->neighbors.push_back(clone);
                dfs(it, clone);
            } 
            else {
                newclone->neighbors.push_back(mp[it]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }

        Node* newclone = new Node(node->val);
        mp[node] = newclone;
        dfs(node, newclone);

        return newclone;
    }
};
