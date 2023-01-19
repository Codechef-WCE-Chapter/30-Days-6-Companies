class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;

        for(int i=0; i<points.size(); i++){
            unordered_map<int, int> dist;

            for(int j=0; j<points.size(); j++){
                if(i == j) continue;

                int d = ( points[i][0] - points[j][0] ) * ( points[i][0] - points[j][0] ) + ( points[i][1] - points[j][1] ) * ( points[i][1] - points[j][1] );

                dist[d]++;
            }

            for(auto d : dist){
                ans += d.second * (d.second - 1);
            }
        }

        return ans;
    }
};
