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
    int findLen(ListNode* curr)
    {
        int cnt = 0;
        while(curr)
        {
            curr = curr->next;
            cnt++;
        }
        return cnt;
    }

    ListNode* deleteMiddle(ListNode* head) 
    {
        if(!head->next) return NULL;
        ListNode* curr = head;
        int n = findLen(curr);

        ListNode* ans = head;

        int i = 0;
        ListNode* prev = NULL;
        while(i < n/2)
        {
            prev = head;
            head = head->next;
            i++;
        }
        ListNode* forward = head->next;
        prev->next = forward;
        
        return ans;
    }
};