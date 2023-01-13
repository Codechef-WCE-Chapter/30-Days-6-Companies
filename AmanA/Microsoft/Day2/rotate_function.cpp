//https://leetcode.com/problems/rotate-function/

/*
Logic:
Time Complexity: O(N)
Ex: 4,2,3,6
sum = 4 + 2 + 3 + 6
1. curr = 4*0 + 2*1 + 3*2 + 6*3
2. curr = 4*1 + 2*2 + 3*3 + 6*0
can also be written as:
2. curr = 4*0 + 2*1 + 3*2 + 6*3 + 4 + 2 + 3 + 6 - 6*4 (need to make 6 as 0)
        = 1. curr + sum - n*nums[i] (where i: n-1->0)
So by observing the pattern, we create a formula

res = curr 

for loop start : i n-1->0
curr+=(sum - nums[i]*n)
res = max(res,curr)

return res;

*/

class Solution {
public:

    int maxRotateFunction(vector<int>& nums) {
     long long curr=0,sum=0;
     int n = nums.size();
     for(int i = 0;i<n;i++){
         curr+=i*nums[i];
         sum+=nums[i];
     }
     long long res = curr;
     for(int i = n-1;i>=0;i--){
         curr+= (sum - n*nums[i]);
         res = max(res,curr);
     }
     return res;
    }
};
