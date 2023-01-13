class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& nD) {
        int g=*max_element(nD.begin(),nD.end());
        sort(nums.begin(),nums.end());
        for(auto x:nD)
        {
            g=__gcd(g,x);
        }
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(g%nums[i]==0) 
                {
                    ans=i;
                    break;
                }
        }
        return ans;
    }
};