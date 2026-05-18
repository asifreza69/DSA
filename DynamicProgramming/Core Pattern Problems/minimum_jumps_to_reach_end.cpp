class Solution {
public:
    int minJumps(vector<int>& arr) {

        int farthest = 0;   // farthest index reachable
        int currentEnd = 0; // end of current jump range
        int jumps = 0;

        // No need to process last index
        for(int i = 0; i < arr.size() - 1; i++) {

            // Update farthest reachable index
            farthest =
                max(farthest,
                    i + arr[i]);

            // Current range exhausted
            if(i == currentEnd) {

                jumps++;
                currentEnd = farthest;
            }
        }

        // If last index is reachable
        if(currentEnd >= arr.size() - 1) {
            return jumps;
        }

        return -1;
    }
};

/*
==========================
🔥 MINIMUM JUMPS
TO REACH END
==========================

Goal:
Find the minimum number of jumps
required to reach the last index.

Each arr[i] tells the maximum
jump length from index i.

--------------------------------

🧠 Core Idea:

Treat each jump as a range.

Within the current reachable
range, compute the farthest
position reachable.

When the current range ends,
take one jump and extend the
range to farthest.

--------------------------------

Variables:

farthest
= maximum index reachable
  from current range

currentEnd
= end of current jump range

jumps
= total jumps taken

--------------------------------

Example:

arr = [2, 3, 1, 1, 4]

Start:
range = [0]

From index 0,
farthest = 2

Jump 1:
range = [1..2]

Within this range,
farthest = 4

Jump 2:
reach end

Answer = 2

--------------------------------

⏱️ Time Complexity:
O(n)

--------------------------------

🧠 Space Complexity:
O(1)

--------------------------------

🧩 Pattern:
Greedy Range Expansion

--------------------------------

🎯 Category:
Greedy

--------------------------------

🧠 Interview One-Liner:

Track the farthest reachable
index in the current jump range;
when the range ends, take a jump.

*/
