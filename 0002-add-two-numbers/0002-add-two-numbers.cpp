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
        ListNode *ans = new ListNode();
        ListNode *cur = ans;
        while (l1 && l2) {
            ListNode *now = new ListNode((carry + l1->val + l2->val) % 10);
            cur->next = now;
            cur = now;
            
            carry = (carry + l1->val + l2->val) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            ListNode *now = new ListNode((carry + l1->val) % 10);
            cur->next = now;
            cur = now;
            
            carry = (carry + l1->val) / 10;
            l1 = l1->next;
        }
        while (l2) {
            ListNode *now = new ListNode((carry + l2->val) % 10);
            cur->next = now;
            cur = now;
            
            carry = (carry + l2->val) / 10;
            l2 = l2->next;
        }
        if (carry)
            cur->next = new ListNode(1);
        return ans->next;
    }
};