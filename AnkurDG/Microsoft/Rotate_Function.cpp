class Solution {
public:
    int dp[100005];
    int Find(int i,int sum, int n, vector<int>&a){
        if(dp[i]!=-1){
            return dp[i];
        }
        if(i>0){
            return dp[i]=Find(i-1,sum,n,a)+sum-n*a[n-i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(i*a[i]);
        }

        return dp[i]=ans;
    }
    int maxRotateFunction(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
    int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        Find(nums.size()-1,sum,nums.size(),nums);

        return *max_element(dp, dp + nums.size());
    }
};