#include<bits/stdc++.h>
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int size=nums.size();
        int original_sum=0,array_sum=0;
        for(int i=0;i<size;i++)
        {
            array_sum+=nums[i];
            original_sum+=i*nums[i];
        }
        int ans=original_sum;
        for(int i=0;i<size;i++)
        {
            original_sum+=array_sum-(size*nums[size-i-1]);
            ans=max(ans,original_sum);
        }
        return ans;   
    }
};