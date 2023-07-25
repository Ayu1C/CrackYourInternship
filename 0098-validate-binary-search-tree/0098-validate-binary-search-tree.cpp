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
    
//     Implicitly, the inorder traversal of BST print the nodes in ascending order. (VVVIMP)
// So during the traversal, append the node val into the result vector.
// Set container has been used to remove the duplicates.
// Run a loop and compare the 'i'th val with (i+1)th val.. if 'i'th val found be greater than (i+1)th val.. just return false.
    
   void inorder(TreeNode* root, vector <int> &nodes)
    {
        if(!root)
            return;

        inorder(root -> left, nodes);
        nodes.push_back(root -> val);    
        inorder(root -> right, nodes); 
    }

    bool isValidBST(TreeNode* root) 
    {
        if(!root)
            return true;

        vector <int> nodes;
        inorder(root, nodes); 

        set <int> s(nodes.begin(), nodes.end());

        if(s.size() != nodes.size())
            return false;

        for(int i = 0; i < nodes.size()-1; i++)
        {
            if(nodes[i] > nodes[i+1])
                return false;
        }       

        return true;
    }
    
};