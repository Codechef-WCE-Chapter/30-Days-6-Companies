class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0, sum1=0, ans=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            sum1+=(i*nums[i]);
        }
        ans=sum1;
        for(int i=nums.size()-1; i>=0; i--){
            sum1+=sum-(nums[i]*nums.size());
            ans=max(ans, sum1);
        }
        return ans;
    }
};