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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        // Step 1: Check if k nodes exist
        int count = k;
        ListNode* temp = head;
        while (count != 0) {
            if (temp == NULL) {
                return head; // less than k nodes
            }
            temp = temp->next;
            count--;
        }

        // Step 2: Reverse k nodes
        count = 0;
        ListNode* fwd = NULL;

        while (count < k && curr != NULL) {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            count++;
        }

        // Step 3: Recursive call for remaining list
        if (fwd != NULL) {
            head->next = reverseKGroup(fwd, k);
        }

        return prev; // new head
    }
};

/*
Approach (Your Logic):

1. Check if k nodes are available:
   → if not, return head

2. Reverse first k nodes:
   → standard reverse LL logic

3. Recursive call:
   → process remaining list

4. Connect:
   → original head becomes tail of reversed group
   → attach next reversed group

Time Complexity: O(n)
Space Complexity: O(n/k) (recursion stack)
*/
