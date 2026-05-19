class Solution {
public:

    /*
    Check if all boards/books can be
    assigned to at most k painters
    such that no painter gets more
    than 'mid' work.
    */
    bool solve(int mid,
               vector<int>& arr,
               int k) {

        int sum = 0;

        for(int i = 0; i < arr.size(); i++) {

            // Continue assigning to
            // current painter
            if(sum + arr[i] <= mid) {
                sum += arr[i];
            }
            else {
                // Need a new painter
                k--;
                sum = arr[i];
            }
        }

        // If k becomes 0 or negative,
        // we needed too many painters
        if(k <= 0) {
            return false;
        }

        return true;
    }

    int minTime(vector<int>& arr,
                int k) {

        // Lower bound:
        // largest single board/book
        int low =
            *max_element(arr.begin(),
                         arr.end());

        // Upper bound:
        // one painter does all work
        int high =
            accumulate(arr.begin(),
                       arr.end(),
                       0);

        int ans = high;

        while(low <= high) {

            int mid =
                low + (high - low) / 2;

            if(solve(mid, arr, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

/*
==========================
🔥 ALLOCATE MINIMUM PAGES
/ PAINTER'S PARTITION
==========================

Goal:
Partition the array into exactly
(or at most) k contiguous parts
such that the maximum partition
sum is minimized.

--------------------------------

🧠 Core Idea:

Binary search on the answer.

For a candidate maximum value
(mid), greedily assign elements
to the current partition until
adding another element would
exceed mid.

Then start a new partition.

--------------------------------

Search Space:

low  = max(arr)
high = sum(arr)

--------------------------------

Feasibility Check:

Can we partition the array into
at most k groups so that each
group sum ≤ mid?

If yes:
    Try smaller answer.

If no:
    Increase answer.

--------------------------------

Example:

arr = [10, 20, 30, 40]
k = 2

Possible partition:
[10,20,30] and [40]

Maximum sum = 60

Answer = 60

--------------------------------

⏱️ Time Complexity:
O(n × log(sum(arr)))

--------------------------------

🧠 Space Complexity:
O(1)

--------------------------------

🧩 Pattern:
Binary Search on Answer

--------------------------------

🎯 Category:
Binary Search

--------------------------------

🧠 Interview One-Liner:

Binary search the maximum allowed
partition sum and greedily test
if k partitions are sufficient.

*/
