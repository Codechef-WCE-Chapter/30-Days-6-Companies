class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>num1=nums;
        sort(num1.begin(),num1.end());
        int c=0;
        int start=-1,end=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=num1[i])
            {
                start=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]!=num1[i])
            {
                end=i;
                break;
            }
        }
        if(start==-1 or end==-1) return 0;
        return (end-start+1);
    }
};