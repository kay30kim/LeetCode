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
 // It's known that inorder traversal of BST is an array sorted in the ascending order.
 // 0 4 -> 2 | 0~1 / 3~4
 // 0 1 -> 0 ++1 | 0~0 / 2~1 => null
 // 0 0 -> 0 | 0~-1 => null / 1~0 => null

 // 3 4 -> 3 ++ 4 | 3~3 / 5~4 => null
 // 3 3 -> 3 | 3~2 =>null / 4~3 => null

class Solution {
public:
    TreeNode* preOrder(int left, int right, vector<int>& nums){
        if(left>right) return NULL;
        
        int mid4root = (left+right)/2;
        if ((left+right)%2 == 1) mid4root++;
        
        TreeNode *root = new TreeNode(nums[mid4root]);
        root->left = preOrder(left,mid4root-1,nums);
        root->right = preOrder(mid4root+1, right,nums);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return preOrder(0,nums.size()-1,nums);
    }
};