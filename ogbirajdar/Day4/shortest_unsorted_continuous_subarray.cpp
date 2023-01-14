#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> v = nums;
        sort(begin(v), end(v));
        int i=0;
        while(i<n && v[i]==nums[i])
            i++;
        
        int j=n-1;
        while(j>=0 && v[j]==nums[j])
            j--;
        
        return i==n && j==-1 ? 0: j-i+1;
    }
};