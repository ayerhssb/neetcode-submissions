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

class Codec {
public:
    void helper(TreeNode* root, string& ans){
        if(!root){ans+="N,"; return;}
        ans+= to_string(root->val);
        ans+=',';
        helper(root->left, ans);
        helper(root->right, ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        helper(root, ans);
        return ans;
    }

    TreeNode* helper1(string &data, int& ind){
        string token;
        while(ind<data.size()&& data[ind]!=','){
            token+=data[ind]; ind++;
        }
        ind++;
        if(token=="N"){return nullptr;}
        int value= stoi(token);
        TreeNode* root = new TreeNode(value);
        root->left = helper1(data, ind);
        root->right = helper1(data, ind);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ind=0;
        return helper1(data, ind);
    }
};
