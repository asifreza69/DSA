// LeetCode 997: Find the Town Judge
// Approach: Use indegree and outdegree arrays to track trust relationships.
//           The judge is trusted by (n - 1) people and trusts nobody.
// Time Complexity: O(n + m)   where m = trust.size()
// Space Complexity: O(n)

#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        for(int i = 0; i < trust.size(); i++){
            indegree[trust[i][1]]++;
            outdegree[trust[i][0]]++;
        }

        for(int i = 1; i <= n; i++){
            if(indegree[i] - outdegree[i] == n - 1){
                return i;
            }
        }
        return -1;
    }
};
