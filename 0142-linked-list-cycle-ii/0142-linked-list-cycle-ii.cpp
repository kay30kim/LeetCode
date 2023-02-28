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
    ListNode *detectCycle(ListNode *ptr) {        
        unordered_set <ListNode*> hash;
        while(hash.count(ptr)==0){
            if(ptr == NULL)
                return NULL;
            hash.insert(ptr);
            ptr = ptr->next;
            
        }
        return ptr;     
    }
};