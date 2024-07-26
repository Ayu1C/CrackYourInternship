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
    map<int, int> count;
    int max_freq = 0;
    
//     static bool cmp(const pair<int, int>& a, const pair<int, int>& b) 
//     { 
//         return a.second < b.second; 
//     } 
 
    int treeSum(TreeNode* root) {
        
        if(root == nullptr) return 0;
        
        int leftSum = treeSum(root -> left);
        int rightSum = treeSum(root -> right);
        
        int total = root->val + leftSum + rightSum;
        count[total]++;
        
        if(count[total] > max_freq) max_freq = count[total];
        return total;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        int sum = treeSum(root);
        
        vector<int> ans;
        
//         vector<pair<int, int>> temp; 
        
//         for (auto& it : count) { 
//            temp.push_back(it); 
//         }  
        
//         sort(temp.begin(), temp.end(), cmp);
        
        // int highestF = temp.end()->second;
        
        for(auto& it : count) {
            if(it.second == max_freq) ans.push_back(it.first);
        }
        
        return ans;
    }
};