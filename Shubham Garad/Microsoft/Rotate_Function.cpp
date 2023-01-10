class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        int sum1 = 0 ;
        int sum2 = 0 ;
        int maxi =0;
        for(int i=0 ;i<n;++i)
        {
            sum2 += nums[i];
            sum1 += (nums[i]*i);
        }
        int prev = sum1;
        for(int i = n - 1; i > 0; i--) {
            int curr = prev - (nums[i] * (n - 1));
            curr += (sum2 - nums[i]);
            
            sum1 = max(sum1, curr);
            prev = curr;
        }
        return sum1;
    }
};