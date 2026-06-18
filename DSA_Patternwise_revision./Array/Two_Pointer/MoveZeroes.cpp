/*
Approach:

1. Find the index of the first zero.
2. Keep pointer j at the first zero position.
3. Traverse the remaining array.
4. Whenever a non-zero element is found, swap it with nums[j].
5. Increment j to point to the next zero position.

This is a two-pointer approach.

Example:

nums = [1,0,3,0,12]

j = 1

i = 2:
swap(3,0)
[1,3,0,0,12]

i = 4:
swap(12,0)
[1,3,12,0,0]

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = -1;

        // find first zero
        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == 0){

                j = i;
                break;
            }
        }

        // no zero present
        if(j == -1){

            return;
        }

        // bring non-zero elements forward
        for(int i = j + 1; i < nums.size(); i++){

            if(nums[i] != 0){

                swap(nums[i], nums[j]);

                j++;
            }
        }
    }
};
