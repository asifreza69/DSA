#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countSt;
        stack<string> strSt;

        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                countSt.push(num);
                strSt.push(curr);
                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = countSt.top(); countSt.pop();
                string prev = strSt.top(); strSt.pop();

                while (repeat--) {
                    prev += curr;
                }
                curr = prev;
            }
            else {
                curr += c;
            }
        }

        return curr;
    }
};

/*
Problem: Decode String (LeetCode 394)

Approach:
Stack + String Parsing

Logic:
- Number → build multiplier
- '[' → push state
- ']' → build repeated string
- Character → append

Time Complexity:
O(n * k) (k = max repetition)

Space Complexity:
O(n)

Key Insight:
Maintain count + string separately for efficient decoding
*/
