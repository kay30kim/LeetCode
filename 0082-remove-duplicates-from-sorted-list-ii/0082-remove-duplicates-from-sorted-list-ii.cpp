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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> hash;
        ListNode *ptr = head;
        ListNode *ans = new ListNode(0, head);
        ListNode *prev = ans;
        while (ptr) {
            hash[ptr->val]++;
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            if (hash[ptr->val] > 1)
                prev->next = ptr->next;
            else
                prev = prev->next;
            ptr = ptr->next;
            
        }
        return ans->next;
    }
};