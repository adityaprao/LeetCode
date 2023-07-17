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
        ListNode* fp = head, *sp = head;
        
        while (n--) fp = fp->next;
        if (fp == NULL) return head->next;
        while (fp->next)
        {
            fp = fp->next;
            sp = sp->next;
        }
        sp->next = sp->next->next;
        return head;
        
    }
};