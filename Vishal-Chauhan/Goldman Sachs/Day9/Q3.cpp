#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>
#define ll long long int
#define inf 11111111111
using namespace std;

//  * Definition for a binary tree node.
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
    void traverse(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;
        arr.push_back(root->val);
        // cout<<"root:"<<root->val<<endl;
        if (root->left)
        {

            // cout<<root->val<<" gooted   ";
            traverse(root->left, arr);
        }
        if (root->right)
        {
            // arr.push_back(root->val);
            // cout<<root->val<<" gootedddd   ";
            traverse(root->right, arr);
        }
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> arr;
        traverse(root1, arr);
        traverse(root2, arr);
        sort(arr.begin(), arr.end());
        return arr;
    }
};

int main()
{
    Solution s;
    TreeNode *root1 = new TreeNode(10), *root2 = new TreeNode(5);
    root1->left = new TreeNode(6);
    root1->right = new TreeNode(4);
    root2->left = new TreeNode(6);
    vector<int> ans = s.getAllElements(root1, root2);
    for (auto val : ans)
        cout << val << "  ";
}