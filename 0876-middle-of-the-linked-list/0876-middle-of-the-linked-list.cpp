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
    ListNode* middleNode(ListNode* head) {
        ListNode* pfirt=head;
        ListNode* psecond=head;
        int count=0;
        while(pfirt){
            count++;
            pfirt = pfirt->next;
        }
        if(count%2==0) count++;
        for(int i=0; i<count/2; i++){
            psecond = psecond->next;
        }
        return psecond;
    }
};