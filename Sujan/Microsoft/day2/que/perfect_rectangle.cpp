class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {

        map<pair<int, int>, int> mp;
        for(vector<int>& x:rectangles){
            mp[{x[0], x[1]}]++;
            mp[{x[0], x[3]}]--;
            mp[{x[2], x[1]}]--;
            mp[{x[2], x[3]}]++;
        }
        int n_mp=0;
        for(auto ptr=mp.begin();ptr!=mp.end();ptr++)
            if(ptr->second!=0){
                if(abs(ptr->second)!=1) 
                return false;
                n_mp++;
            }
        return n_mp==4;
    }
};
