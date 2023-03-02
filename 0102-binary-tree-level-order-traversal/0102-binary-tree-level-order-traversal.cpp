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

// 1) dfs
// 
// 2) bfs
// queue 

class Solution {
private:
    struct Point{
        TreeNode* node;
        int depth;
    };
public:    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<Point> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        q.push({root,0});
        
        while(!q.empty()){            
            vector<int> tmp;
            int size=q.size();
            for(int i=0; i<size; i++){
                Point now = q.front();
                q.pop();
                
                tmp.push_back(now.node->val);
                if(now.node->left) q.push({now.node->left, now.depth+1});
                if(now.node->right) q.push({now.node->right, now.depth+1});
            }
            
            ans.push_back(tmp);        
            
        }       
        return ans;
    }
};