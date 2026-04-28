"This is a variation of Reverse Nodes in K-Group 
where even the last incomplete group is reversed."
  
#include <cstddef>
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;
        ListNode* fwd = NULL;

        // Reverse up to k nodes (even if less than k remain)
        while (count < k && curr != NULL) {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            count++;
        }

        // Recursive call
        if (fwd != NULL) {
            head->next = reverseKGroup(fwd, k);
        }

        return prev;
    }
};
