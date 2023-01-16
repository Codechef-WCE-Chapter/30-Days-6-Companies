class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int H = 0;
        for(int i=0; i<numsDivide.size(); i++) H = __gcd(H, numsDivide[i]);
        
        sort(nums.begin(), nums.end());
        
        int div = 0;
        for(int i=0; i<nums.size(); i++){
            if(H%nums[i]) div++;
            else return div;
        }
        
        return -1;
    }
};
