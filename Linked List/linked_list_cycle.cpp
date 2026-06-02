class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // 1 step
            fast = fast->next->next;     // 2 steps

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

/*
Approach (Your Logic):

1. Use two pointers:
   - slow → moves 1 step
   - fast → moves 2 steps

2. Traverse the list:
   - If there is a cycle → fast will catch slow

3. If they meet → cycle exists

4. If fast reaches NULL → no cycle

Time Complexity: O(n)
Space Complexity: O(1)
*/
