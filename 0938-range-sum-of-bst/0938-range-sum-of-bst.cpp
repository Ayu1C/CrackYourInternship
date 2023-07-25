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
    
    int rangeSumBST(TreeNode* root, int low, int high) {
       
        vector<int> bst;
        inorder(root, bst);
        
        int sum = 0;
        for(int i=0; i<bst.size(); i++)
        {
            if(bst[i]==low)
            {
                while(i<bst.size() && bst[i]<=high)
                {
                    sum += bst[i];
                    i++;
                }
                break;
            }
        }
        return sum;
        
    }
};