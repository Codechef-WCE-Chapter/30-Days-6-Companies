class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums)
            mp[it]++;
        unordered_map<int,int>hm;
        for(auto it:nums)
        {
            if(!mp[it]) continue;
            if(hm[it]>0)
            {
                hm[it]-=1;
                hm[it+1]+=1;
                mp[it]--;
            }
            else if(mp[it]>0 and mp[it+1]>0 and mp[it+2]>0)
            {
                hm[it+3]+=1;
                mp[it]--;
                mp[it+1]--;
                mp[it+2]--;
            }
            else
                return false;
           
        }
       
        return true;
    }
};