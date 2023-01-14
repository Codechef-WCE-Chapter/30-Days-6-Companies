#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        if(points.size()==1)return 1;
        int maxim=INT_MIN;
        for(int i=0;i<points.size();i++)
        {
            map<float,int> slope;
            priority_queue<int> maxi;
            for(int j=i+1;j<points.size();j++)
            {
                if(points[j][0]-points[i][0])
                {
                    slope[(float(points[j][1])-float(points[i][1]))/float((points[j][0])-float(points[i][0]))]++;
                    maxi.push(slope[(float(points[j][1])-float(points[i][1]))/float((points[j][0])-float(points[i][0]))]);
                }
                else
                {            
                    slope[INT_MAX]++;
                    maxi.push(slope[INT_MAX]);
                }
                if(!maxi.empty()&&maxi.top()+1>maxim)maxim=maxi.top()+1;
            }
        }
        return maxim;
    }
};