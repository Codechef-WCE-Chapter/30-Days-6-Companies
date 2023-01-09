//Microsoft: Q4.Rotate Function
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int prev=0,total_sum=0;
        for(int i=0;i<n;i++){
            prev+=(nums[i]*i);
            total_sum+=nums[i];
        }
        int ans=prev;
        for(int i=1;i<n;i++){
            int curr=prev+total_sum-n*nums[n-i];
            prev=curr;
            ans=max(ans,prev);
        }
        return ans;
    }
};