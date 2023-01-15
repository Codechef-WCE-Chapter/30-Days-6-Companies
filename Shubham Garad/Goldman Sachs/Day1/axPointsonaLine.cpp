class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int n = points.size();
        // vector<double>v;
        int maxi = 0;
        for(int i = 0 ;i<n ;++i)
        {
            unordered_map<double ,int>mp;
            for(int j = 0 ;j<n;++j)
            {
                double ans = (double)(points[i][0] - points[j][0])/(points[i][1]-points[j][1]); 
                // v.push_back(ans);

                mp[ans]++;
                maxi = max(maxi , mp[ans]+1);
            }
        }
        // for(int i = 0 ;i< v.size();++i)
        // {
        //     mp[v[i]]++;
        // }
        // int max =0;
        // for(auto it : mp)
        // {
        //     if(max<it.second)
        //     {
        //         max = it.second;
        //     }
        // }
        return maxi;
        
    }
};