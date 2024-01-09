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
    
    void getLeafs(TreeNode* root, vector<int>& seq)
    {
        if(root->left==NULL && root->right==NULL) 
        {
            seq.push_back(root->val);
            return;
        }
        if(root->left) getLeafs(root->left, seq);
        if(root->right) getLeafs(root->right, seq);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;
        
        getLeafs(root1, seq1);
        getLeafs(root2, seq2);
        
        if(seq1==seq2) return true;
        
        return false;
    }
};