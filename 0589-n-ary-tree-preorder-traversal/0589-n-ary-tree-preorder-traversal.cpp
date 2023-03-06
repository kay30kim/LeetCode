/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

     vector<int> preorder(Node* root) {
        
        // Step 1: This vector will store our preorder traversal.
        vector<int> sol;

        // Step 2: We call pre_order function on the root node, and
        // pass our solution vector by reference. 
        pre_order(root, sol);
        return sol;
    }

    void pre_order(Node* node, vector<int>& v){

        // Step 2.1: If the current node is null, we have nothing to
        // do and we will return to the calling function. This is the
        // base condition for recursion.
        if (node == nullptr) return;

        // Step 2.2: If the node is not null, before doing anything
        // else, we will push the nodes value to our solution array,
        // since in pre order traversal, we process the current node
        // first and then move on to the children.
        v.push_back(node -> val);
        
        // Step 2.3: Once our current node is processed, we will go
        // through all of its children and pass them to the pre_order
        // function i.e. perform our recursive calls.
        for (auto child: node -> children){
            pre_order(child, v);
        }

    }
   
};