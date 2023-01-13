class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());

        vector<vector<int>>result(nums.size());

        vector<int>ret;

        for(int i = 0;i<nums.size();++i) 
        {
            for(int j = 0;j<i;++j) 
            {
                if((nums[i] % nums[j] == 0)&&(result[j].size() > result[i].size())) 
                {
                    result[i] = result[j];
                }
            }

            result[i].push_back(nums[i]);

            if(ret.size() < result[i].size()) 
                ret = result[i];
        }
        
        return ret;
    }
};