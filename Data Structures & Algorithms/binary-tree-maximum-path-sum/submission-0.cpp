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
    int maxsum = INT_MIN;
    int helper(TreeNode* root, int& sum){
        if(!root){return 0;}
        int left = max(0, helper(root->left, sum));
        int right = max(0,helper(root->right, sum));
        sum = root->val + left+ right;
        maxsum = max(sum, maxsum);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int sum=0;
        helper(root, sum);
        return maxsum;
    }
};
