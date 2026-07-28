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
    void helper(TreeNode* root, int k, priority_queue<int>& pq){
        if(!root){
            return;
        }
        // TreeNode* left = helper(root->left,k);
        // TreeNode* right = helper(root->right, k);
        // if(k==0){
        //     return root;
        // }
        // k--;
        // if(left!=nullptr){return left;}
        // return right;
        helper(root->left,k,pq); helper(root->right, k,pq);
        pq.push(root->val);
        if(pq.size()>k){pq.pop();}
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            return 0;
        }
        // priority_queue<TreeNode*, vector<TreeNode*>, greater<TreeNode*>> pq;
        priority_queue<int> pq;
        helper(root, k, pq);
        return pq.top();
    }
};
