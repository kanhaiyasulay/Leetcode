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
    bool isOdd = false;
    int cntLen(ListNode* head)
    {
        ListNode* curr = head;
        int cnt = 0;
        while(curr) 
        {
            curr = curr->next;
            cnt++;
        }
        if(cnt%2 != 0) isOdd = true;
        return cnt/2;
    }
public:
    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next) return true;
        int len = cntLen(head);

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = head;

        while(curr != NULL && len > 0)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            len--;
        }

        if(isOdd) forward = forward->next;
        while(forward && prev)
        {
            if(forward->val != prev->val) return false;
            forward = forward->next;
            prev = prev->next;
        }

        return forward == prev;
    }
};