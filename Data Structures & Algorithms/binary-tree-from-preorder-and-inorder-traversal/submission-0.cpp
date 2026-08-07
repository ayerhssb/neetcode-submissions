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
    int findpos(int target, vector<int>& inorder){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]== target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int startindex, int endindex, int ind){
        if(startindex>endindex){return nullptr;}
        TreeNode* root= new TreeNode(preorder[ind]);
        int pos = findpos(preorder[ind], inorder);
        root->left = helper(preorder, inorder, startindex, pos-1, ind+1);
        root->right = helper(preorder, inorder, pos+1, endindex, ind+ (pos-startindex+1));
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return helper(preorder, inorder, 0, preorder.size()-1, 0);
    }
};
