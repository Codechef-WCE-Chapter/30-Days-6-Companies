class point{
    public:
    double x,y;
    point(double x,double y){
        this->x=x;
        this->y=y;
    }
};
class Solution {
public:
    bool isCollinear(point a,point b,point c){
        double m1=(b.y-a.y)/(b.x-a.x);
        double m2=(c.y-b.y)/(c.x-b.x);
        return m1==m2;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2){
            return n;
        }
        vector<point> coordinates;
        for(auto& i:points){
            point k=point((double)i[0],(double)i[1]);
            coordinates.push_back(k);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int cnt=0;
                for(int k=0;k<n;k++){
                    if(i!=j&&j!=k&&i!=k){
                        if(isCollinear(coordinates[i],coordinates[j],coordinates[k])){
                            cnt++;
                        }
                    }
                }
                ans=max(cnt+2,ans);
            }
        }
        return ans;
    }
};