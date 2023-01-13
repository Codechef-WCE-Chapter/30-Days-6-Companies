class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
          int n = nums.size();
          sort(nums.begin(),nums.end());
      vector<int>dp(n,1),hash(n);
      int maxi = 1;
      int lastind = 0;
      for(int i = 0;i<n;i++){
          hash[i] = i;
          for(int j = 0;j<i;j++){
              if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                  dp[i] = dp[j]+1;
                  hash[i] = j;
              }
          }
          if(dp[i]>maxi){
              maxi = dp[i];
              lastind = i;
          }
      }

      vector<int>t;
      t.push_back(nums[lastind]);
      while(hash[lastind]!=lastind){
          lastind = hash[lastind];
          t.push_back(nums[lastind]);
      }
      reverse(t.begin(),t.end());
      return t;
    }
};
Console
