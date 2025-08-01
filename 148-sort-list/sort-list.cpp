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
    ListNode* sortList(ListNode* head) 
    {
        ListNode* curr = head;
        vector<int> sortedData;
        while(curr)
        {
            sortedData.push_back(curr->val);
            curr = curr->next;
        }

        sort(sortedData.begin(), sortedData.end());

        curr = head;
        int idx = 0;
        while(curr)
        {
            curr->val = sortedData[idx];
            idx++;
            curr = curr->next;
        }
        
        return head;
    }
};