//https://leetcode.com/problems/largest-divisible-subset/submissions/875675361/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};

        vector<int>dp(n+1,1);

    sort(nums.begin(),nums.end());
        int m=INT_MIN;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 and dp[i]<=dp[j])
                {
                    dp[i]=1+dp[j];
                }

            }
        }
        m= *max_element(dp.begin(), dp.end());
        vector<int>res;
        int prev=-1;

        for(int i=n-1;i>=0;i--)
        {
            if(dp[i]==m and (prev%nums[i]==0 || prev==-1))
            {
                
                res.push_back(nums[i]);
                prev=nums[i];
                m-=1;
                
            }
        }
        return res;
    }
};
