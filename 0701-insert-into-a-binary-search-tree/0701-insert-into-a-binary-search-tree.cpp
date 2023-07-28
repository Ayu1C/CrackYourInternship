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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        
        if(!root)
        {
            TreeNode* dummy = new TreeNode(val);
            return dummy;
        }
        
        TreeNode* temp = root;
        
        if(root->val > val)
        {
            if(root->left) insertIntoBST(root->left, val);
            else
            {
                TreeNode* dummy = new TreeNode(val);
                root->left = dummy;
            }
        }
        
        else if(root->val < val)
        {
            if(root->right) insertIntoBST(root->right, val);
            else
            {
                TreeNode* dummy = new TreeNode(val);
                root->right = dummy;
            }
        }
            
        return temp;
    }
};