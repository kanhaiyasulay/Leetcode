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
    int cntLen(ListNode* head)
    {
        ListNode* curr = head;
        int len = 0;
        while(curr)
        {
            curr = curr->next;
            len++;
        }
        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int len = cntLen(head);

        int stop = len - n;
        ListNode* curr = head;

        if(stop == 0) return head->next;
        
        while(curr != NULL && stop > 1)
        {
            curr = curr->next;
            stop--;
        }

        if(curr->next != NULL) curr->next = curr->next->next;
        return head;
    }
};