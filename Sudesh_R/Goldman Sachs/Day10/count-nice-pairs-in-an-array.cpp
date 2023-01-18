class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)
        {
            string x = to_string(nums[i]);
            reverse(x.begin() , x.end());
            nums[i]-= stoll(x);
        }
        long long M = 1e9+7;
        map<int,int>m;
        int ans = 0;
        for(int i = nums.size()-1;i>=0;i--)
        {
            m[nums[i]]++;
            if(m[nums[i]]>1)
            {
                ans = (ans + m[nums[i]]-1)%(M);
            }
        }
        return ans;
    }
};
