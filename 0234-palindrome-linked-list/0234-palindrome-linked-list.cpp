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
    ListNode* findMiddle(ListNode* head)
    {
        if (head == NULL or head->next == NULL) return head;
        ListNode* fp = head, *sp = head;
        
        while (fp != NULL and fp->next != NULL)
        {
            fp = fp->next->next;
            sp = sp->next;
        }
        
        if (fp == NULL) return sp;
        return sp->next;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL, *cur = head, *fwd = head;
        
        while (cur != NULL)
        {
            fwd = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = fwd;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head->next == NULL) return true;
        
        ListNode* mid = findMiddle(head);
        cout << mid->val;
        ListNode* revhead = reverse(mid);
        
        while (revhead)
        {
            if (head->val != revhead->val) return false;
            head = head->next;
            revhead = revhead->next;
        }
        return true;        
    }
};