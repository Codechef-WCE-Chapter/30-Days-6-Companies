/*
https://leetcode.com/problems/valid-square/
*/

#include<bits/stdc++.h>
using namespace std;
//check all possible pairs since seq is not known

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //cehck if all points are distinct
        if(p1==p2 || p1==p3|| p1==p4 || p2==p3 || p2==p4 || p3==p4)
        return false;
      
        double dist1 = sqrt( pow((p1[0] - p2[0]), 2) + pow( (p1[1]-p2[1]), 2)     );
   
        double dist2 = sqrt( pow((p1[0] - p3[0]), 2) + pow( (p1[1]-p3[1]), 2)     );
    
        double dist3 = sqrt( pow((p1[0] - p4[0]), 2) + pow( (p1[1]-p4[1]), 2)     );
       
        double dist4 = sqrt( pow((p2[0] - p3[0]), 2) + pow( (p2[1]-p3[1]), 2)     );
     
        double dist5 = sqrt( pow((p2[0] - p4[0]), 2) + pow( (p2[1]-p4[1]), 2)     );
      
        double dist6 = sqrt( pow((p3[0] - p4[0]), 2) + pow( (p3[1]-p4[1]), 2)     );

        vector<double> distance={dist1, dist2, dist3, dist4, dist5, dist6};
        int count=0;
        sort(distance.begin(), distance.end() );

        //last for diagonals
        if( (distance[0]==distance[1]) && (distance[1]==distance[2]) && (distance[2]==distance[3])  && (distance[4]==distance[5]) )
        return true;

        return false;
    }
};