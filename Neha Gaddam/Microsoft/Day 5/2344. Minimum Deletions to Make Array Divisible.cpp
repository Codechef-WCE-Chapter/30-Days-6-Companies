class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        // sort(nums.begin(),nuns.end());
        map<int,int>mp;
        for(auto it:nums)
        {
            // for(auto it:)
            mp[it]++;
        }
        int c=0;
        for(auto i:mp)
        {
            int changed=false;
            for(auto it:numsDivide)
            {   
                if(it%i.first!=0)
                {
                    changed=true;
                    break;
                }
            }
            if(!changed) return c;
            else   c+=i.second;
        }
        
        return -1;
    }
};