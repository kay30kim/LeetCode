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
    struct Point{
        TreeNode *node;
        int depth;
    };
public:
    vector<vector<int>> levelOrder(TreeNode* root) {        
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        
        queue<Point> q;
        q.push({root,0});
        
        int ndepth = 0;
        while(!q.empty()){
            vector<int> tmp;
            while(q.front().depth==ndepth){
                TreeNode *now = q.front().node;
                q.pop();
                if(now->left) q.push({now->left,ndepth+1});
                if(now->right) q.push({now->right,ndepth+1});
                tmp.push_back(now->val);
            }
            ans.push_back(tmp);
            ndepth++;            
        }
        return ans;
    }
};