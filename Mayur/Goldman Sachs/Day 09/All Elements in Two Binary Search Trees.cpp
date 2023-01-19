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
void trevel(TreeNode* root,vector<int>&v)
{
    if(!root)
        return;
    trevel(root->left,v);
    v.push_back(root->val);
    trevel(root->right,v);
}

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
            vector<int>v1,v2,v3;
            trevel(root1,v1);
            trevel(root2,v2);
            v1.insert(v1.begin(),v2.begin(),v2.end());  
             sort(v1.begin(),v1.end());  
             return v1;    
    }
};