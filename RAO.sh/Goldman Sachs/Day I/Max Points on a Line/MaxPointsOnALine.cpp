class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
		int n = points.size();
		
		if(n <= 2) return n;
		
		int ans = 0;
		for(int i = 0; i < n; i++){
			map<pair<int, int>, int> slope_count;
			
			int same = 0, vertical = 0;
			for(int j = i + 1; j < n; j++){
				if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
					same++;
				}
				else if(points[i][0] == points[j][0]){
					vertical++;
				}
				else{
					int x = points[i][0] - points[j][0];
					int y = points[i][1] - points[j][1];
					int g = __gcd(x, y);
					x /= g;
					y /= g;
					slope_count[{x, y}]++;
				}
			}

			int local = 0;
			for(auto it : slope_count){
				local = max(local, it.second);
			}

			local = max(local, vertical);
			ans = max(ans, local + same + 1);
		}
		return ans;       
    }
};
