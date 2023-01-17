class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> m,m1;
        for(int i = 0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for(auto it: nums)
        {
            if(m[it] == 0)
            {
                continue;
            }
            m[it]--;
            if(m1[it-1]>0)
            {
                m1[it-1]--;
                m1[it]++;
            }
            else if(m[it+1]!=0 && m[it+2]!=0)
            {
                m[it+1]--;
                m[it+2]--;
                m1[it+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};