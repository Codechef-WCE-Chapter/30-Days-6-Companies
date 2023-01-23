#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long int
using namespace std;
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
    int count(TreeNode *root, int &sum, int &c)
    {
        if (!root)
            return 0;
        int res = 0;
        sum += root->val;
        c++;
        int res1 = count(root->left, sum, c);
        int res2 = count(root->right, sum, c);
        res += res1;
        res += res2;
        return res;
    }

    int averageOfSubtree(TreeNode *root)
    {
        int res = 0;
        if (root)
        {
            int sum = 0;
            int c = 0;
            res += count(root, sum, c);
            if (c)
            {
                if (root->val * c == sum)
                    res++;
            }
            else
            {
                if (!root->left && !root->right && root->val == sum)
                    res++;
            }
            res += averageOfSubtree(root->left);
            res += averageOfSubtree(root->right);
        }
        return res;
    }
};
int main()
{
    Solution s;
    // cout<<s.averageOfSubtree();
}