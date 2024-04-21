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
    int ans = INT_MAX;
    
    void find(TreeNode* node, int count)
    {
        if(node->left==NULL && node->right==NULL)
        {
            ans = min(ans, count);
            return;
        }
        
        if(node->left) find(node->left, count+1);
        if(node->right) find(node->right, count+1);
        
    }
    
    int minDepth(TreeNode* root) {
        
        if(!root) return 0;
        
        find(root, 1);
        
        return ans;
    }
};