* Problem : https://leetcode.com/problems/rotate-function/description/

* Solution : 

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans, sum = 0, F0 = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            F0 += (i * nums[i]);
        }

        ans = F0;

        for(int i = 0; i < n; i++){
            F0 = F0 + sum - (n * nums[n - 1 - i]);
            ans = max(ans, F0);
        }

        return ans;
    }
};