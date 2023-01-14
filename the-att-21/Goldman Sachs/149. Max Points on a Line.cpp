* Problem : https://leetcode.com/problems/max-points-on-a-line/description/

* Solution :

class point {
public:
    double x, y;
    point(double a, double b){
        this -> x = a;
        this -> y = b;
    }
};

class Solution {
public:
    bool isCollinear(point a, point b, point c){
        double m1 = (a.y - b.y)/(a.x - b.x);
        double m2 = (a.y - c.y)/(a.x - c.x);

        return m1 == m2;
    }
    
    int maxPoints(vector<vector<int>>& p) {
        int n = p.size(), ans = 0;
        if(n <= 2) { return n; }

        vector<point> coords;
        for(int i = 0; i < p.size(); i++){
            point m = point((double)p[i][0], (double)p[i][1]);
            coords.push_back(m);
        }

        for(int i = 0; i < coords.size(); i++){
            for(int j = 0; j < coords.size(); j++){
                int cnt = 0;
                for(int k = 0; k < coords.size(); k++){
                    if(i!=j  and j!=k and k!=i){
                        if(isCollinear(coords[i], coords[j], coords[k])) { cnt++; }
                    }
                }
                ans = max(cnt + 2, ans);
            }
        }

        return ans;
    }
};