/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void PreorderTreversal(TreeNode* node, int max){
        if(node==NULL) return;
       // printf("현재 : %d ",node->val);
        if(node->val >= max){
            max = node->val;
           // printf("max!\n");
            ans++;
        }      
        
        if(node->left) PreorderTreversal(node->left,max);
        if(node->right) PreorderTreversal(node->right,max);
    }
    int goodNodes(TreeNode* root) {
        PreorderTreversal(root,-10001);
        return ans;
    }
};