class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    vector<vector<int>>pairs;
    map<int,int>mpp;
    pairs.push_back(p1);
    pairs.push_back(p2);
    pairs.push_back(p3);
    pairs.push_back(p4);
    for(int i=0;i<4;i++){
        int x1=pairs[i][0];
        int y1=pairs[i][1];
        for(int j=i+1;j<4;j++){
            int x2=pairs[j][0];
            int y2=pairs[j][1];
            int m=(x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
            if(m==0) return false;
            mpp[m]++;
        }
    }
    for(auto it : mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    if(mpp.size()==2 || mpp.size()==1) return true;
    return false;
    }
};
