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
    
    int height(int curHeight, TreeNode* root)
    {
       int h = curHeight;
        
       if(!root->left && !root->right) return curHeight;
        
        if(root->left) h = height(curHeight+1, root->left);
        
        if(root->right) h = max(h, height(curHeight+1, root->right));
        
        return h;
    }
    
    int maxDepth(TreeNode* root) {
        
        int h = 1;
        
        if(!root) return 0;
        
//         if(root->left) h = height(h+1, root->left);
        
//         if(root->right) h = max(h, height(h+1, root->right));
        
        return height(h, root);
        
    }
};