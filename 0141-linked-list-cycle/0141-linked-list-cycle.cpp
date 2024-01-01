/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> hash;
        while (head) {
            if (hash.find(head) != hash.end())
                return true;
            hash[head] = 1;
            head = head->next;
        }
        return false;
    }
};