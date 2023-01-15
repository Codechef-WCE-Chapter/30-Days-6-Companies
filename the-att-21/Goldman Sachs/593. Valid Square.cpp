* Problem : https://leetcode.com/problems/valid-square/

* Solution : 

class Solution {
public:
    double len(vector<int>& a, vector<int>& b){
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2) * 1.0);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1==p2 || p1==p3 || p1==p4 || p2==p3 || p2==p4 || p3==p4) return false;
        
        map<double, int> m;
        double s1 = len(p1, p2);
        double s2 = len(p1, p3);
        double s3 = len(p1, p4);
        double s4 = len(p3, p2);
        double s5 = len(p4, p2);
        double s6 = len(p3, p4);

        m[s1]++; m[s2]++; m[s3]++;  
        m[s4]++; m[s5]++; m[s6]++;  

        if(m.size() > 2) return false;
        return true;
    }
};