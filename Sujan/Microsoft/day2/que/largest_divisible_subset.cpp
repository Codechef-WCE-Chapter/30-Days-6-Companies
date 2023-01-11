class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
      
        int n=nums.size();
          vector<int>dp(n,1);
        int m=1,num=-1;
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<i;j++)
           {
               if(!(nums[i]%nums[j]) && dp[i]<dp[j]+1)
               {
                   dp[i]=dp[j]+1;
                   if(m<dp[i])
                   {
                       m=dp[i];
                   }
               }
           }
       }
       for(int i=n-1;i>=0;i--)
       {
           if(m==dp[i] && (num==-1 || !(num%nums[i])))
           {
               v.push_back(nums[i]);
               m--;
               num=nums[i];
           }
       }
       sort(v.begin(),v.end());
  return v;
    }
};
