class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int sum=0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }

        int n=nums.size();

        int curr=0;

        for(int i= 0;i<n;i++)
        {
            curr+=i*nums[i];
        }

        int ans=curr;

        for(int i=n-1;i>=0;i--)
        {
            curr=curr+sum-n*nums[i];
            ans=max(ans,curr);
        }
        return ans;
    }
};