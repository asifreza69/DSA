// LeetCode 169: Majority Element

// Approach (Boyer-Moore Voting Algorithm):
// 1. Assume first element as candidate and set count = 1
// 2. Traverse the array:
//    - If current element == candidate → increment count
//    - Else → decrement count
//    - If count becomes 0 → update candidate to current element and reset count = 1
// 3. The final candidate will be the majority element (guaranteed to exist)

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int element = nums[0];
        int count = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] == element){
                count++;
            } else {
                count--;
                if(count == 0){
                    element = nums[i];
                    count = 1;
                }
            }
        }

        return element;
    }
};
