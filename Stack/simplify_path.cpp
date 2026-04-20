#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> st;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;

            if (token == "..") {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(token);
            }
        }

        if (st.empty()) return "/";

        string ans = "";
        for (auto &dir : st) {
            ans += "/" + dir;
        }

        return ans;
    }
};

/*
Problem: Simplify Path (LeetCode 71)

Approach:
Stack Simulation (using vector)

Logic:
- Split path by '/'
- Ignore "" and "."
- ".." → pop last directory
- Else → push directory
- Rebuild path

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Insight:
Simulate directory traversal using stack
*/
