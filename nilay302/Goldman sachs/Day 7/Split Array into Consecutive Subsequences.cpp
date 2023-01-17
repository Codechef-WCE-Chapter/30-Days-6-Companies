class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>fm;
        map<int,int>hm;
        for(int i = 0;i<nums.size();i++){
            fm[nums[i]]++;
        }


        for(int i = 0;i<nums.size();i++){
            if(fm[nums[i]]==0)continue;
            if( hm.find(nums[i])==hm.end() || hm[nums[i]]<1 ){
                // cout<<1<<" ";
                fm[nums[i]]--;
                if(fm[nums[i]+1]==0)return false;
                fm[nums[i]+1]--;
                if(fm[nums[i]+2]==0)return false;
                fm[nums[i]+2]--;
                hm[nums[i]+3]++;
            }
            else{
                cout<<"->"<<nums[i]<<' ';
                fm[nums[i]]--;
                hm[nums[i]]--;
                cout<<hm[nums[i]]<<"*";
                hm[nums[i]+1]++;
            }
        }
        return true;
    }
};