//Microsoft:  Largest Divisible Subset
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n,0);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        int maxi=1;
        int lastIndex=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0&&dp[prev]+1>dp[i]){
                    hash[i]=prev;
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> ans;
        while(hash[lastIndex]!=lastIndex){
            ans.push_back(nums[lastIndex]);
            lastIndex=hash[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};