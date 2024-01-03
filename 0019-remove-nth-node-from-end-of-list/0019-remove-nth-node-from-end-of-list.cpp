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
        // 최적화 풀이
        ListNode *tmp = new ListNode(0, head);
        ListNode *ptr = head;
        ListNode *ptr_nprev = tmp;
        for (int i = 0 ; i < n; i++) 
            ptr = ptr->next;
        while (ptr) {
            ptr = ptr->next;
            ptr_nprev = ptr_nprev->next;
        }
        ptr_nprev->next = ptr_nprev->next->next;
        return tmp->next;
        
        /* 풀이 2
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
        if (prev)
            prev->next = ptr->next;
        else
            head = head->next;
        return head;
        */
    }
};