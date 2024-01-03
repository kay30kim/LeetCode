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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr = head;
        ListNode *prev = NULL;
        int num = 0;
        while (ptr) {
            ptr = ptr->next;
            num++;
        }
        
        ptr = head;
        num -= n;
        while (num--) {
            prev = ptr;
            ptr = ptr->next;
        }
        if (prev){
          //  printf("%d %d\n",prev->val, ptr->val);
            prev->next = ptr->next;
        }
        else
            return head->next;
        return head;
        
    }
};