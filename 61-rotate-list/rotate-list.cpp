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
    ListNode* getTail(ListNode* head, int& cnt)
    {
        ListNode* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int cnt = 1;
        ListNode* tail = getTail(head, cnt);

        int nK = k%cnt;
        int straight = cnt - nK;
        int i = 0;
        ListNode* temp = head;
        while(i++ < straight-1)
            temp = temp->next;
        
        ListNode* ans = temp->next;
        if(ans == NULL) return head;
        temp->next = NULL;
        tail->next = head;

        return ans;
    }
};