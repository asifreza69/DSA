// LeetCode 70: Climbing Stairs
//
// Approach: Bottom-Up Dynamic Programming
//
// Idea:
// - To reach step i, we can come from:
//      step (i-1) by taking 1 step
//      step (i-2) by taking 2 steps
//
// - So recurrence relation:
//      dp[i] = dp[i-1] + dp[i-2]
//
// This is similar to Fibonacci sequence.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    
    int climbStairs(int n) {
        
        // Base cases
        if (n <= 2)
            return n;
        
        vector<int> dp(n + 1);
        
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};


// Space Optimized Version
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        
        int prev2 = 1;  // dp[i-2]
        int prev1 = 2;  // dp[i-1]
        
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};


