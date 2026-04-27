#include <cstddef>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* fwd = curr->next; // store next safely
            curr->next = prev;          // reverse link
            prev = curr;                // move prev
            curr = fwd;                 // move curr
        }

        return prev;
    }
};

/*
Approach (Your Logic Fixed):

1. Use three pointers:
   - prev → previous node
   - curr → current node
   - fwd  → next node (temporary)

2. For each node:
   - Store next node (fwd)
   - Reverse current pointer
   - Move prev forward
   - Move curr forward

3. Continue until curr becomes NULL

4. prev becomes new head

Time Complexity: O(n)
Space Complexity: O(1)
*/
