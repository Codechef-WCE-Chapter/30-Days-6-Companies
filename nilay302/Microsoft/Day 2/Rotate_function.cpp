class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int f0 = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            f0 += i*nums[i];
        }
        vector<int>dp(nums.size(),0);
        dp[0] = f0;
        int max_ans = dp[0];
        int n = nums.size();
        for(int i = 1;i<nums.size();i++){
            dp[i] = dp[i-1] + sum - n*nums[n-i];
            max_ans = max(dp[i],max_ans);
        }
        return max_ans;
    }
};