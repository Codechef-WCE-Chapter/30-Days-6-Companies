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


    void getAns(vector<int>&ans, TreeNode * root){
        if(root!=nullptr){
            getAns(ans,root->left);
            ans.push_back(root->val);
            getAns(ans,root->right);
        }
        return;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        getAns(ans,root1);
        getAns(ans,root2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};