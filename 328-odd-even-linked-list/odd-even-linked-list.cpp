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

        vector<ListNode*> odd;
        vector<ListNode*> even;

        ListNode* curr = head;
        bool isOdd = true;
        while(curr)
        {
            if(isOdd)
            {
                odd.push_back(curr);
                isOdd = false;
            }
            else
            {
                even.push_back(curr);
                isOdd = true;
            }
            curr = curr->next;
        }

        ListNode* dummy = new ListNode(-1);
        head = dummy;

        for(int i=0; i<odd.size(); i++)
        {
            head->next = odd[i];
            head = head->next;
        }
        for(int i=0; i<even.size(); i++)
        {
            head->next = even[i];
            head = head->next;
        }
        head->next = NULL;
        return dummy->next;
    }
};