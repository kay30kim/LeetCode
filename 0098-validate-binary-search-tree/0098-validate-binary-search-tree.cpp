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
private:
    TreeNode *prev;
public:
    // bool inorder(TreeNode* node, TreeNode *prev){ wrongway 왜냐면 전꺼로 prev가 바뀌여야함 나왔을때
    bool inorder(TreeNode* node){
        if(node==NULL) return true;
        
        // if(node->left) inorder(node->left, prev); wrong way
        if(!inorder(node->left)) return false;
    
        if(prev!=NULL && node->val <= prev->val) return false;
            
        prev = node;
        return inorder(node->right);
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};