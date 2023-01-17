class Solution {
public:
    bool isPossible(vector<int>& nums) {
    
        map<int,int>m , m1;
        for(auto it : nums){m[it]++;}
        for(int i = 0;i< nums.size() ; i++)
        {
            if( m[nums[i]]==0){continue;}
            m[nums[i]]--;
            if(m1[nums[i]-1] >0)
            {
                m1[nums[i]-1]--;
                m1[nums[i]]++;
            }
            else if(m[nums[i ]+1]  >0 && m[nums[i]+2] >0)
            {
                m[nums[i]+1]--;
                m[nums[i]+2]--;

                m1[nums[i] + 2]++;
            }
            else{return false;}
        }
return true;


    }
};
