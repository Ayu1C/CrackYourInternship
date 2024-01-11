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
    
    map<TreeNode*, vector<TreeNode*>> child;
    
public:
    
    vector<TreeNode*> dfs(TreeNode* root)
    {
        vector<TreeNode*> temp, temp1, temp2;
        if(root->left)
        {
           temp1 = dfs(root->left);
           for(auto i : temp1)
           {
               child[root].push_back(i);
               temp.push_back(i);
           }
        }
        if(root->right)
        {
           temp2 = dfs(root->right);
           for(auto i : temp2)
           {
               child[root].push_back(i);
               temp.push_back(i);
           } 
        }
        
        temp.push_back(root);
        return temp;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
       vector<TreeNode*> all = dfs(root);
        
        int maxV = INT_MIN;
        
        for(auto it : child)
        {
            vector<TreeNode*> temp = it.second;
            
            for(int i=0; i<temp.size(); i++)
            {
                maxV = max(maxV, abs(it.first->val - temp[i]->val));
            }
            
        }
        
        return maxV;
    }
};