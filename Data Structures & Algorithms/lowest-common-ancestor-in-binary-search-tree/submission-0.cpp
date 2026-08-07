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
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){return nullptr;}
        if((p->val>root->val && q->val<root->val) || (p->val<root->val && q->val>root->val)){return root;}
        if(root->val==p->val || root->val == q->val){return root;}
        TreeNode* node;
        if(p->val>root->val){
            node = helper(root->right, p, q);
        }else{
            node = helper(root->left,p,q);
        }
        if(!node){return nullptr;}
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val || root->val == q->val){return root;}
        if((p->val>root->val && q->val<root->val) || (p->val<root->val && q->val>root->val)){return root;}
        return helper(root, p, q);
    }
};
