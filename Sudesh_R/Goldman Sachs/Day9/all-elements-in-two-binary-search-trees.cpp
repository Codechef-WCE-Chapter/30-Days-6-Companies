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
        vector<int>s;
void solve(TreeNode* root)
{
    if(root==nullptr){return;}
    s.push_back(root->val);
    solve(root->left);
    solve(root->right);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        solve(root2);
        sort(s.begin() , s.end());
        return s;
    }
};
