class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
         int ans = 0;
            if(points.size()<3)return ans;
        for(int i = 0;i<points.size();i++){           
            map<int,int>mp;
            for(int j = 0;j<points.size();j++){
                if(j == i)continue;
                int dist = ((points[i][0] - points[j][0])* (points[i][0] - points[j][0]));
                int dist2 = ((points[i][1] - points[j][1])* (points[i][1] - points[j][1]));
                dist = dist + dist2;
                mp[dist]++;
            }
            for(auto it:mp){
                if(it.second<2)continue;
                if(it.second == 2)ans+=2;
                else ans+=it.second*(it.second-1);
            }
        }
        return ans;
    }
};