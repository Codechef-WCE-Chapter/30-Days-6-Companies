class Solution {
public:
    int distSquare(vector<int>& a,vector<int>& b){
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        map<vector<int>,map<int,int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    int d1=distSquare(points[i],points[j]);
                    ans+=mp[points[i]][d1];
                    mp[points[i]][d1]++;
                }
            }
        }
        return 2*ans;
    }
};