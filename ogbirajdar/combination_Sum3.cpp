#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int ind, int sum, int n, vector<vector<int>> &ans, vector<int> v, int k) 
    {
        if(sum==n &&k==0)
        {
            ans.push_back(v);
            return;
        }
        
        if(sum > n)
        {
            return;
        }
        
        for(int i=ind; i<=9; i++)
        {
            if(i>n)
                return;
            v.push_back(i);
            solve(i+1, sum+i, n, ans, v, k-1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        vector<int> v;
        solve(1, 0, n, ans, v, k);
        return ans;
    }
};