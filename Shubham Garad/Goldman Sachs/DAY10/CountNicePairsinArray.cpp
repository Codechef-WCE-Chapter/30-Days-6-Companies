class Solution {
public:

    int revers(int n)
    {
        int rev_num = 0;
        while (n != 0) {
            rev_num = rev_num * 10 + n % 10;
            n = n / 10;
        }
        return rev_num;
    }

    int countNicePairs(vector<int>& nums) {
        
        int x = nums.size();
        int count =0;
        unordered_map<int,int>mp;
        for(int i = 0 ;i<x;++i)
        {
           int a = nums[i] - revers(nums[i]);

           mp[a]++;

           count = (count + mp[a]-1)%1000000007;
        }
       return count%1000000007;
    }
};