/*Perfect Rectangle: https://leetcode.com/problems/perfect-rectangle/  */

#include<bits/stdc++.h>
using namespace std;

/*

Approach: 
T.C : O(n)
S.C : O(n) -> map

Step 1:
To represent the formation of a rectangle-> representing each point with its corres value as :
1 -> if its bottom left or top right
-1 -> if its top left or bottom right
0 -> if its an intermediate point lying on some edge and is shared by 2 rectangles
other -> if point is shared by more than 2 rectangles

Step 2:
Remove intermediate points c=by checking their corres values

Step 3:
To check if we get a rectangle after integrating all the rectangles:
Points reserved at the end must be 4 with corres values as 1 or -1 
(this also covers the edge case of overlapping rectangles -> needs to be avoided)

*/
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map< pair<int,int>, int> mp;

        //add all the points of each rectangle in a map with their corres values
        //Incr corres values of bottom left and top right points 
        //Decr corres values of top left and bottom right points 
        for(auto it: rectangles)
        {
            mp[{it[0], it[1]}]++;
            mp[{it[2], it[3]}]++;
            mp[{it[0], it[3]}]--;
            mp[{it[2], it[1]}]--;
    
        // Check if any point has its corres value equalized to 0 -> remove it from map
        if(mp[{it[0], it[1]}] == 0) 
        mp.erase( {it[0], it[1]});
        if(mp[{it[2], it[3]}] == 0)
        mp.erase({it[2], it[3]});
        if(mp[{it[0], it[3]}] == 0)
        mp.erase({it[0], it[3]} );
        if(mp[{it[2], it[1]}] == 0 )
        mp.erase( {it[2], it[1]} );
        
        }
        //Check if after removing these points -> map consists of 4 points forming a rectangle 
        if(mp.size() != 4)
        return false;

        // Also check if value of each final point in map is either 1 or -1 -> to avoid overlapping rectangles at end (edge case!!!)
        for(auto it: mp)
        {
            if(abs(it.second) != 1)
            return false;
        }

        return true;
    }
};