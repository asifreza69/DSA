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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return;
        }

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Split and reverse second half
        ListNode* head2 = slow->next;
        slow->next = NULL;

        ListNode* curr = head2;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }

        head2 = prev;

        // Step 3: Merge both halves
        ListNode* t1 = head;
        ListNode* t2 = head2;

        while(t1 != NULL && t2 != NULL){
            ListNode* op1 = t1;
            ListNode* op2 = t2;

            t1 = t1->next;
            t2 = t2->next;

            op1->next = op2;
            op2->next = t1;
        }

        return;
    }
};

/*
Approach (Your Logic):

1. Find middle using slow-fast pointer
2. Split list into two halves
3. Reverse second half
4. Merge alternately:
   L0 → Ln → L1 → Ln-1 ...

Time Complexity: O(n)
Space Complexity: O(1)
*/
