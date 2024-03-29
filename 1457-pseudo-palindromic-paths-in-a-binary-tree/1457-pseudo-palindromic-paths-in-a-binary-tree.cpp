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
    int pseudoPalindromicPaths(TreeNode* root) {
        result = 0;
        digit.resize(10, 0);
        dfs(root);
        return result;
    }

private:
    int result;
    vector<int> digit;

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        digit[root->val]++;

        if (root->left == nullptr && root->right == nullptr) {
            if (isPalindrome()) {
                result++;
            }
        } else {
            dfs(root->left);
            dfs(root->right);
        }

        digit[root->val]--;
    }

    bool isPalindrome() {
        int odd = 0;
        for (int i = 1; i <= 9; i++) {
            if (digit[i] % 2 != 0) {
                odd++;
            }
        }

        return (odd <= 1);
    }
};