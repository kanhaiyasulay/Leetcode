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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int digit = 0;
        int addition = l1->val + l2->val + carry;
        ListNode* new_head = new ListNode(-1);
        ListNode* new_tail = new_head;

        while(l1 != NULL && l2 != NULL) {
            addition = l1->val + l2->val + carry;
            carry = addition / 10;
            digit = addition % 10;
            ListNode* newNode = new ListNode(digit);
            new_tail->next = newNode;
            new_tail = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            addition = l1->val + carry;
            carry = addition / 10;
            digit = addition % 10;
            ListNode* newNode = new ListNode(digit);
            new_tail->next = newNode;
            new_tail = newNode;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            addition = l2->val + carry;
            carry = addition / 10;
            digit = addition % 10;
            ListNode* newNode = new ListNode(digit);
            new_tail->next = newNode;
            new_tail = newNode;
            l2 = l2->next;
        }
        
        if(carry != 0) {
            ListNode* newNode = new ListNode(carry);
            new_tail->next = newNode;
            new_tail = newNode;       
        }

        //remove -1 wali node from new_head
        ListNode* temp = new_head;
        new_head = new_head->next;
        temp->next = NULL;
        delete temp;
        
        return new_head;
    }
};