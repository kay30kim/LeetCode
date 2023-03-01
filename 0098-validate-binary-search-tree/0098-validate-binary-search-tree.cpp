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
    bool recursive(TreeNode* node, TreeNode* left, TreeNode* right){
        if(node==NULL) return true;
        
        if(left!=NULL && node->val <= left->val) return false;
        if(right!=NULL && node->val >= right->val) return false;
        
        return recursive(node->left, left, node) & recursive(node->right, node,right);
    }
    bool isValidBST(TreeNode* root) {
        return recursive(root,NULL, NULL);
    }
};