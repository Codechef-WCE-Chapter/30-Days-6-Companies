class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int>dist;
        dist.push_back((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]));
        dist.push_back((p2[0]-p3[0])*(p2[0]-p3[0]) + (p2[1]-p3[1])*(p2[1]-p3[1]));
        dist.push_back((p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1]));
        dist.push_back((p1[0]-p4[0])*(p1[0]-p4[0]) + (p1[1]-p4[1])*(p1[1]-p4[1]));
        dist.push_back((p3[0]-p4[0])*(p3[0]-p4[0]) + (p3[1]-p4[1])*(p3[1]-p4[1]));
        dist.push_back((p4[0]-p2[0])*(p4[0]-p2[0]) + (p4[1]-p2[1])*(p4[1]-p2[1]));

        sort(dist.begin(),dist.end());

        for(int i = 0;i<dist.size();i++){
            if(dist[i]==0)return false;
        }

        if(dist[0]==dist[1] && dist[1]==dist[2] && dist[2] == dist[3]  && dist[4]==dist[5])return true;

        return false;
    }
};