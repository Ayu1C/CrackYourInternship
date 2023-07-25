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
    void inorder(TreeNode* root, vector<int>& bst)
    {
        if(!root) return;
        
        inorder(root->left, bst);
        bst.push_back(root->val);
        inorder(root->right, bst);

    }
    
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> bst;
        inorder(root, bst);
        
        int diff, minDiff = INT_MAX;
        for(int i=1; i<bst.size(); i++)
        {
            diff = bst[i]-bst[i-1];
            if(diff < minDiff) minDiff = diff;
        }
        
        return minDiff;
    }
};