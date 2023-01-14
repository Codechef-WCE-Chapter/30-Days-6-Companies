class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        sort(numsDivide.begin(), numsDivide.end());
        int cnt=0;
        int divisor=numsDivide[0];
        for(int i=1; i<numsDivide.size(); i++){
            divisor=__gcd(divisor, numsDivide[i]);
        }
        if(nums[0]>divisor)return -1;
        for(int i=0; i<nums.size(); i++){
            if(divisor%nums[i]==0){
                return cnt;
            }
            cnt++;
        }
        return -1;
    }
};