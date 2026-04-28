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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1head = l1;
        ListNode* l2head = l2;

        int carry = 0;

        ListNode* head = new ListNode(-1);
        ListNode* trav = head;

        // Step 1: Traverse both lists
        while (l1head != NULL && l2head != NULL) {
            int data1 = l1head->val;
            int data2 = l2head->val;

            int value = (data1 + data2 + carry) % 10;
            carry = (data1 + data2 + carry) / 10;

            ListNode* t = new ListNode(value);
            trav->next = t;
            trav = trav->next;

            l1head = l1head->next;
            l2head = l2head->next;
        }

        // Step 2: Remaining nodes of l1
        while (l1head != NULL) {
            int data1 = l1head->val;

            int value = (data1 + carry) % 10;
            carry = (data1 + carry) / 10;

            ListNode* t = new ListNode(value);
            trav->next = t;
            trav = trav->next;

            l1head = l1head->next;
        }

        // Step 3: Remaining nodes of l2
        while (l2head != NULL) {
            int data1 = l2head->val;

            int value = (data1 + carry) % 10;
            carry = (data1 + carry) / 10;

            ListNode* t = new ListNode(value);
            trav->next = t;
            trav = trav->next;

            l2head = l2head->next;
        }

        // Step 4: If carry left
        if (carry != 0) {
            ListNode* t = new ListNode(carry);
            trav->next = t;
            trav = trav->next;
        }

        head = head->next;
        return head;
    }
};

/*
Approach (Your Logic):

1. Traverse both linked lists simultaneously
2. Add corresponding digits + carry
3. Store result digit (mod 10)
4. Update carry (division by 10)
5. Process remaining nodes
6. If carry remains, add new node

Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))
*/
