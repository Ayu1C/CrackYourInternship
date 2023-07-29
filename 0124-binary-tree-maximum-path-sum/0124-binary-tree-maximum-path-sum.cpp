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
    int max_path = INT_MIN;
    
    int get_max_gain(TreeNode* root)
    {
        if(!root) return 0;
        
        int gain_on_left = max(get_max_gain(root->left), 0);
        int gain_on_right = max(get_max_gain(root->right), 0);
        
        int current_max_path = root->val + gain_on_left + gain_on_right;
         max_path = max(max_path, current_max_path);
        
        return root->val + max(gain_on_left, gain_on_right);
    }
    
    int maxPathSum(TreeNode* root) {
        
        get_max_gain(root);
        
        return max_path;
    }
};
