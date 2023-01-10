* Problem : https://leetcode.com/problems/perfect-rectangle/

* Solution : 

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> mp;
        int count = 0;
        for(auto P : rectangles){
            mp[{P[0], P[1]}]++;
            mp[{P[2], P[3]}]++;
            mp[{P[0], P[3]}]--;
            mp[{P[2], P[1]}]--;
        }
        for(auto itr : mp)count += abs(itr.second);
        return count == 4;
    }
};