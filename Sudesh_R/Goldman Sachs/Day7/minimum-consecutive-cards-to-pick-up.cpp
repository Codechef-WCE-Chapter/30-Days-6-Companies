
class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        vector<int>v(1000005 , -1);
        int mn = INT_MAX;
        for(int i = 0;i<c.size() ;i++)
        {
            if(v[c[i]]!=-1)
            {
                mn = min(mn , (i - v[c[i]]) +1);
                v[c[i]] = i;
            }
            else
            {
                v[c[i]] = i;
            }
        }
        if(mn==INT_MAX)
        {
            return -1;
        }

        return mn;


    }
};
