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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode* newhead = new ListNode(-1);
        ListNode* t = newhead;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                ListNode* temp = l1;
                l1 = l1->next;
                t->next = temp;
                t = t->next;
            } else {
                ListNode* temp = l2;
                l2 = l2->next;
                t->next = temp;
                t = t->next;
            }
        }

        if (l1 != NULL) {
            t->next = l1;
        }
        if (l2 != NULL) {
            t->next = l2;
        }

        newhead = newhead->next;
        return newhead;
    }
};

/*
Approach (Your Logic):

1. Handle edge cases:
   - If one list is empty, return the other

2. Create a dummy node (newhead) to simplify merging

3. Traverse both lists:
   - Compare current nodes
   - Pick smaller node
   - Attach it to result
   - Move pointer forward

4. Attach remaining nodes:
   - If any list is left, connect directly

5. Return merged list:
   - Skip dummy node

Time Complexity: O(n + m)
Space Complexity: O(1)
*/
