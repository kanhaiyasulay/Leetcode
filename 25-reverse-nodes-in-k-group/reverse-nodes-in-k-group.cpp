class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        stack<int> st;
        ListNode* curr = head;

        while(curr)
        {
            ListNode* present = curr;
            int cnt = 1;
            for(int i=0; i<k; i++)
            {
                if(!curr) return head;
                st.push(curr->val);
                curr = curr->next;
            }
            while(!st.empty())
            {
                present->val = st.top();
                st.pop();
                present = present->next;
            }
        }

        return head;
    }
};