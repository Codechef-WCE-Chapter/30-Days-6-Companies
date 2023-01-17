class Solution {
public:
    
    
    long long check(vector<int>& p1, vector<int>&p2)
    {
        long long d1=(pow((p1[0]-p2[0]),2)+pow((p1[1]-p2[1]),2));
        
    
        return d1;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // if(p1==p2==p3==p4) return false;
        if((p1==p2) and (p3==p4) and (p1==p3))return false;
        int t=false;
        vector<long long>v;
        v.push_back(check(p1,p2));
        v.push_back(check(p1,p3));
        v.push_back(check(p1,p4));
        v.push_back(check(p2,p4));
        v.push_back(check(p2,p3));
        v.push_back(check(p3,p4));

        sort(v.begin(),v.end());
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
        // cout<<(v[0]==v[1]==v[2]==v[3])<<endl;
        if((v[0]==v[1]) and (v[2]==v[3]) and (v[0]==v[2])) 
        {
            if(v[4]==v[5])
                return true;
        }
    return t;

    }
};