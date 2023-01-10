// https://leetcode.com/problems/combination-sum-iii/solutions/3027004/easy-to-understand-backtracking-c/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>curr;
        getSubset(1,9,curr,res,k,n);
        return res;
    }
    void getSubset(int s,int e,vector<int>&curr,vector<vector<int>>&res,int k,int n)
    {
        if(n==0 and curr.size()==k)
        {
                 res.push_back(curr);
        }

        for(int i=s;i<=e;i++)
        {
            curr.push_back(i);
            getSubset(i+1,e,curr,res,k,n-i);
            curr.pop_back();
        }
    }
};
