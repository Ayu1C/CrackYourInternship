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
    vector<vector<int>> ans;
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
        
    }
    
    void dfs(TreeNode* root, int targetSum, vector<int>& path){
        
        if (root == nullptr) return;
        
        path.push_back(root->val);
        targetSum -= root->val;
        
        if (root->left == nullptr && root->right == nullptr) { // Is leaf node
            if (targetSum == 0) // Found valid path
                ans.push_back(path);
        } else {
            dfs(root->left, targetSum, path);
            dfs(root->right, targetSum, path);
        }
        
        path.pop_back(); // backtrack
        
    }   
};