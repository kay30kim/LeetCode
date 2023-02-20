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
public : 
vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    typedef struct{
        TreeNode* treeNode;
        int distance;
    }Node;
    vector<vector<int>> ans;

    if(!root) return ans;
    
    queue<Node> q;
    q.push({root,0});
    int nowDistance = 0;
    while(!q.empty()){
        nowDistance=q.front().distance;
        vector<int> tmpVector;
        while(!q.empty() && q.front().distance==nowDistance){            
            Node tmp = q.front();
            printf("%d %d %d\n",tmp.treeNode->val,tmp.distance, nowDistance);
            q.pop();
            
            if(tmp.treeNode && tmp.treeNode->left != NULL) q.push({tmp.treeNode->left,nowDistance+1});
            if(tmp.treeNode && tmp.treeNode->right != NULL) q.push({tmp.treeNode->right,nowDistance+1});
            tmpVector.push_back(tmp.treeNode->val);
            
        }
        if(nowDistance%2 == 1){
            for(int i=0; i<tmpVector.size(); i++){
                printf("%d ",tmpVector[i]);
            }
            printf("\n");
            reverse(tmpVector.begin(),tmpVector.end());
            for(int i=0; i<tmpVector.size(); i++){
                printf("%d ",tmpVector[i]);
            }
            printf("\n");
            ans.push_back(tmpVector);
        }
        else{
            
            ans.push_back(tmpVector);
            //printf("%d\n", )
            //tmpVector = tmpVector.reserve(tmpVector.size());
            
        }
    }

    return ans;

}
};
