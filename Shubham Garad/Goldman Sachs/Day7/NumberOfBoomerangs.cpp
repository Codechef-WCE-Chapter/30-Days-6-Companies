class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int count =0;
        int n = points.size();
        if(n<3)
        {
            return 0;
        }

        for(int i=0;i<n;++i)
        {
            map<int,int>mp;
            for(int j =0 ;j<n;++j)
            {
                int x = pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);

                mp[x]++;
            }   
            for(auto it : mp)
            {
                if(it.second)
                {
                    count += it.second*(it.second-1);
                }
            }
        }

        return count;
    }
};