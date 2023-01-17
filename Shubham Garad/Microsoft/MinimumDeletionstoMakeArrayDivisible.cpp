class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int m = nums.size();
        int n = numsDivide.size();
        int count=0;
        int s=numsDivide[0];

        for(int i = 0  ;i<n ;++i)
        {
            s = gcd(numsDivide[i],s);
        }

        sort(nums.begin(),nums.end());

        if(nums[0]>s)
        {
            return -1;
        }
        for(int i = 0 ;i<m;++i)
        {
            if(s%nums[i]!=0)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if(count==m)
        {
            return -1;
        }
        return count;
    }
};