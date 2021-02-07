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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root,nodes);
        return construction(nodes,0,nodes.size()-1);  
    }
    
    
    void inorder(TreeNode* root, vector<int>& nodes){
        if(root != nullptr){
            inorder(root->left,nodes);
            nodes.push_back( root->val );
            inorder(root->right,nodes);
        }
    }
    TreeNode* construction(vector<int>& nodes,int start,int end){
        if(start <= end){
            int mid = (start + end)/2;
            TreeNode* tn = new TreeNode( nodes[mid] );
            tn->left = construction(nodes,start,mid-1);
            tn->right = construction(nodes,mid+1,end);
            return tn;
        }
        else return nullptr;
    }
};
