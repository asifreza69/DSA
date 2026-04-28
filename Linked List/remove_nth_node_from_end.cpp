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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* t = head;

        // Step 1: Calculate length
        while (t != NULL) {
            len++;
            t = t->next;
        }

        // Step 2: If head needs to be removed
        if (len == n) {
            return head->next;
        }

        // Step 3: Find node before target
        len = len - n - 1;
        t = head;

        while (len--) {
            t = t->next;
        }

        // Step 4: Delete node
        ListNode* del = t->next;
        t->next = t->next->next;

        del->next = NULL;
        delete del;

        return head;
    }
};

/*
Approach (Your Logic):

1. Traverse list to calculate total length (len)

2. If len == n:
   → remove head node

3. Otherwise:
   → find (len - n - 1)th node
   → this node is just before the one to delete

4. Adjust pointers:
   → skip the target node

Time Complexity: O(n)
Space Complexity: O(1)
*/
