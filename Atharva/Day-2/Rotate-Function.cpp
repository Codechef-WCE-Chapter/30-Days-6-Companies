class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int prev=0,sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            prev+=(i*nums[i]);
            sum+=nums[i];
        }
        int res=prev;
        for(int i=n-1;i>0;i--){
            prev=prev-(n-1)*nums[i]+sum-nums[i];
            res=max(res,prev);
        }
        return res;

    }
};
