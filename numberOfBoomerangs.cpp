class Solution {
public:

 int findDistance(vector<int> &p1, vector<int> &p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }

    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int cnt = 0;
        
        int n = points.size();
        for(int i = 0; i < n; i++)
        {
            map<int, int> mp;


            for(int j = 0; j < n; j++)
            {
                if(i == j){
                    continue;
                }
                int tmp = findDistance(points[i], points[j]);
                if(mp.find(tmp) != mp.end())
                    cnt += mp[tmp] * 2; 
                
                mp[tmp]++;
            }
        }
         
        return cnt;
    }
    
   
};
