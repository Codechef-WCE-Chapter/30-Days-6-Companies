class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> mp;
        for(auto &i:rectangles){
            mp[{i[0], i[1]}]++;
            mp[{i[0], i[3]}]--;
            mp[{i[2], i[1]}]--;
            mp[{i[2], i[3]}]++;
        }
        int cnt=0;
        for(auto &i:mp){
            if(i.second!=0){
                if(abs(i.second)!=1){
                    return false;
                }
                cnt++;
            }
        }
        return cnt==4;
    }
};