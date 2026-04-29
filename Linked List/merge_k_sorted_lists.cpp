#include <vector>
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
    // merge two sorted lists
    ListNode* mergetwosorted(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val <= l2->val){
            l1->next = mergetwosorted(l1->next, l2);
            return l1;
        } else {
            l2->next = mergetwosorted(l1, l2->next);
            return l2;
        }
    }

    // divide and conquer
    ListNode* partition(int s, int e, vector<ListNode*>& lists){
        if(s > e) return NULL;
        if(s == e) return lists[s];

        int mid = s + (e - s) / 2;

        ListNode* p1 = partition(s, mid, lists);
        ListNode* p2 = partition(mid + 1, e, lists);

        return mergetwosorted(p1, p2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        return partition(0, lists.size() - 1, lists);
    }
};

/*
Approach (Your Logic):

1. Divide the list of linked lists into halves
2. Recursively merge left and right halves
3. Use mergeTwoSortedLists to combine

This is similar to merge sort

Time Complexity: O(N log k)
Space Complexity: O(log k) recursion
*/
