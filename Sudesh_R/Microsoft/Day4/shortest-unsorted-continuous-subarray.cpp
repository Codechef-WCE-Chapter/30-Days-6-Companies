class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n = a.size();
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i = 1;i<n;i++)
        {
            if(a[i] < a[i-1])
            {
                mn = min(mn , a[i]);
            }
        }
        for(int i = n-2;i>=0;i--)
        {
            if(a[i] > a[i+1])
            {
                mx = max(mx , a[i]);
            }
        }

        int start = 0;
        int end = n-1;
        for(;start<n;start++)
        {
            if( a[start] > mn)
            {
                break;
            }
        }

        for(; end >=0;end--)
        {
            if(a[end] < mx)
            {
                break;
            }
        }

        if(mn == INT_MAX && mx == INT_MIN){return 0;}
        return end - start +1;
    }
};
