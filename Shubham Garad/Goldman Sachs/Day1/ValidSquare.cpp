class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        int x3 = p3[0], y3 = p3[1];
        int x4 = p4[0], y4 = p4[1];

        double a = sqrt(pow((double)(x2-x1),2)+pow((double)(y2-y1),2));
        double b = sqrt(pow((double)(x3-x2),2)+pow((double)(y3-y2),2));
        double c = sqrt(pow((double)(x4-x3),2)+pow((double)(y4-y3),2));
        double d = sqrt(pow((double)(x4-x1),2)+pow((double)(y4-y1),2));
        double e = sqrt(pow((double)(x3-x1),2)+pow((double)(y3-y1),2));
        double f = sqrt(pow((double)(x2-x4),2)+pow((double)(y2-y4),2));

        vector<double>v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        v.push_back(e);
        v.push_back(f);
        
        sort(v.begin(),v.end());
        if(v[0]==v[1] &&v[0]==v[2]&&v[0]==v[3] && v[4]==v[5] &&v[0]>0)
        {
            return true;
        }
        return false;
        
    }
};