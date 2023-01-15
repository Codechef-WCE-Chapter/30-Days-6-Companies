
class Solution {
public:
    int maxPoints(vector<vector<int>>& pt) {
        int ans=1; 
        int n=pt.size();
       // slope of every point with selected point
        for(int i=0;i<n-1;i++){
            map<double,int> mp;
            for(int j=i+1;j<n;j++){
                if(pt[j][1]==pt[i][1]) 
                mp[-90]++;//i assume slope to avoid slope of 90 degree(we can say that is Perpendicular line) 
                else{ 
                    double x = (double)(pt[j][0]-pt[i][0])/(double)(pt[j][1]-pt[i][1]);
                    //storing the slop into map
                    mp[x]++;
                }
            }
            // same slope w.r.t.that selected point
            int temp = 0;
            for(auto it:mp)
                temp = max(temp, it.second+1);    // +1 for the current point(point itself)
            ans = max(temp, ans);
        }
        return ans;
    }
};
