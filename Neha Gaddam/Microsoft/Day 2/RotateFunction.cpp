class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=INT_MIN,s=0,total=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=(nums[i]*i);
            total+=nums[i];
        }
        sum=max(sum,s);
        for(int i=nums.size()-1;i>=0;i--)
        {
           s+=total;
           s-=(nums.size()*nums[i]);
           sum=max(sum,s);
        }
        return sum;
    }
};