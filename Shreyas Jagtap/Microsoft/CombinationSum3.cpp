class Solution {
public:
    void solve(vector<vector<int>>&v,vector<int>&res,vector<int>&nums,int k,int index,int target)
    {
        if(k==0 and target==0)
        {
            v.push_back(res);
            return ;
        }
        if(k<0 or target<0)
        {
            return ;
        }
        for(int i=index;i<nums.size();i++)
        {
            if(nums[i]>target) break;
            res.push_back(nums[i]);
            solve(v,res,nums,k-1,i+1,target-nums[i]);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=0;i<9;i++)
        {
            nums.push_back(i+1);
        }
        vector<vector<int>>v;
        vector<int>res;
        solve(v,res,nums,k,0,n);
        return v;
    }
};