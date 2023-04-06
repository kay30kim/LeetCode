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
    int dfs(TreeNode* root, int &diameter){
        if(!root) return 0;
        
        int leftPath = dfs(root->left,diameter);
        int rightPath = dfs(root->right,diameter);
        
        diameter = max(diameter,leftPath+rightPath);
        
        return max(leftPath,rightPath)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        dfs(root,diameter);
        return diameter;
    }
};