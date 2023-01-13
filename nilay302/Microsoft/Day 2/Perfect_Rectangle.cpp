class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>mp;

        //storing left bottom and right top as 1 and other 2 as -1
        for(int i = 0;i<rectangles.size();i++){
            mp[make_pair(rectangles[i][0],rectangles[i][1])]++;
            mp[make_pair(rectangles[i][2],rectangles[i][3])]++;
            mp[make_pair(rectangles[i][0],rectangles[i][3])]--;
            mp[make_pair(rectangles[i][2],rectangles[i][1])]--;
        }
        int cnt = 0;
        //at last there should exist 4 such points where values will be 1,1,-1,-1
        for(auto it :mp){
            cout<<it.second<<" ";
            if(it.second == 1 || it.second == -1){
                cnt++;
            }
            else if(it.second == 0)continue;
            else return false;
        }
        if(cnt == 4)return true;
        return false;
    }
};