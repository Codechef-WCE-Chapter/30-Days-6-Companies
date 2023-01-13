//https://leetcode.com/problems/rotate-function/submissions/875623463/
class Solution {
public:
    int maxRotateFunction(vector<int>& arr) {
        int sum=0;
        int f=0;
        int n=arr.size();
        if(n==1)return 0;

        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            f+=(i*arr[i]);
        }
        int m=f;
        for(int i=n-1;i>0;i--)
        {
            f+=(sum-(n*arr[i]));
            m=max(m,f);
        }
        return m;
    }
};