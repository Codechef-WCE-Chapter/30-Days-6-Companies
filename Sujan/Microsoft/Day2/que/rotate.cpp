class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int fun=0;
        int maximum=0;
        if (n==1) 
        return 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            fun+=i*nums[i];
        }
        maximum=fun;
        for(int i=n-1;i>0;i--)
        {
            fun+=(sum-(n*nums[i]));
            maximum=max(fun,maximum);
        }
        return maximum;
    }
};
