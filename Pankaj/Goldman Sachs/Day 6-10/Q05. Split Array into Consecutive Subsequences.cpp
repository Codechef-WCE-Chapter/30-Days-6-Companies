class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]+1==nums[i]){
                    dp[i]++;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi>=3;
    }
};