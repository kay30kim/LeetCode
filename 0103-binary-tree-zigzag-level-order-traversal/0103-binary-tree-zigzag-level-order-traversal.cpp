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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
         int cnt=0;
        if(root==NULL)
        return ans;
        vector<int> helper;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            if(temp==NULL)
            {
                q.pop();
                if(!q.empty())
                q.push(NULL);
                if(cnt%2==0)
                ans.push_back(helper);
                else
                {
                    reverse(helper.begin(),helper.end());
                    ans.push_back(helper);
                }
                cnt++;
                helper.clear();
            }
            else
            {
                q.pop();
                helper.push_back(temp->val);
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
        }
        return ans;
    }
};