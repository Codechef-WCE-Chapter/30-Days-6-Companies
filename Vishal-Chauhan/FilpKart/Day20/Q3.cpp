#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
// #define ll long long int
using namespace std;
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int f(map<TreeNode *, int> &m, TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int ans = root->val;
        if (m.find(root) != m.end())
        {
            return m[root];
        }
        if (root->left)
        {
            ans += f(m, root->left->left) + f(m, root->left->right);
        }
        if (root->right)
        {
            ans += f(m, root->right->left) + f(m, root->right->right);
        }
        return m[root] = max(ans, f(m, root->left) + f(m, root->right));
    }
    int rob(TreeNode *root)
    {
        map<TreeNode *, int> m;
        return f(m, root);
    }
};

int main()
{
    Solution s;
}