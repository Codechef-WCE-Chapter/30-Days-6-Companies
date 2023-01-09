//Microsoft:  Minimum Deletions to Make Array Divisible
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=numsDivide.size();
        int commonFactor=0;
        for(int i=0;i<n;i++){
            commonFactor=__gcd(commonFactor,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(commonFactor%nums[i]==0){
                return i;
            }
        }
        return -1;
    }
};