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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head) return NULL;
        if(!head->next || !head->next->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* firstEven = even;

        while(even && even->next)
        {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            odd->next = firstEven;
            even = even->next;
        }

        return head;
    }
};