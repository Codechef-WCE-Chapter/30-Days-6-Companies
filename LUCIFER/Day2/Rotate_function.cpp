class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long ans=INT_MIN;
        long long temp=0,sum=0;
        for(long long i=0;i<nums.size();i++)
        {
            temp+=nums[i];
            sum+=i*nums[i];
        }
        ans=max(sum,ans);
        for(long long i=0;i<nums.size()-1;i++)
        {
            sum+=temp;
            sum-=nums.size()*nums[nums.size()-1-i];
            ans=max(sum,ans);
        }
        return ans;
    }
};
