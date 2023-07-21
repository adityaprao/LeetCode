/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* fp = head, *sp = head, *temp = head;
        if (head == NULL or head->next == NULL) return NULL;
        
        bool cycle = false;
        
        while (fp->next and fp->next->next)
        {
            fp = fp->next->next;
            sp = sp->next;
            if (fp == sp) {cycle = true; break;}
        }
        if (!cycle) return NULL;
        
        while (sp != temp)
        {
            sp = sp->next;
            temp = temp->next;
        }
        return sp;
        
    }
};