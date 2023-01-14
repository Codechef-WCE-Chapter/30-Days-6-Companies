int solve(int x,int sum,int i){
    if(x==sum) return i;
    return solve(x+i,sum,i+1);
}
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi=INT_MIN;
        if(points.size()==1) return 1;
        for(int i=0;i< points.size()-1;i++){
            map<float,int>mpp;
            for(int j=i+1;j<points.size();j++){
            double m= 0;
            if(i==j) continue;
            int y=points[i][1]-points[j][1];
            int x=points[i][0]-points[j][0];
            if(x==0) m=10000.0;
            else m=(double)y/(double)x;
            mpp[m]++;
            }
            for(auto it : mpp){
            cout<<it.first<<" "<<it.second<<endl;
            maxi=max(it.second+1,maxi);
        }
        }
        return maxi;
    }
};
