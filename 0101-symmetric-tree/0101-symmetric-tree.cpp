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
    
    bool isSame(TreeNode* leftN, TreeNode* rightN) {
        
        if(leftN==NULL && rightN==NULL) return true;
        
        else if(leftN == NULL || rightN == NULL) return false;
        
        else if(leftN->val != rightN->val) return false;
        
        return isSame(leftN->left, rightN->right) && isSame(leftN->right, rightN->left);
    }
    
    bool isSymmetric(TreeNode* root) {
       
        if(root == NULL) return true;
        
        return isSame(root->left, root->right);
    }
};