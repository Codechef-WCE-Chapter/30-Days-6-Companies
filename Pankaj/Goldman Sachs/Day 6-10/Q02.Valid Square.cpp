class Solution {
public:
    int distanceSquare(vector<int>& a,vector<int>& b){
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> st;
        st.insert(distanceSquare(p1,p2));
        st.insert(distanceSquare(p1,p3));
        st.insert(distanceSquare(p1,p4));
        st.insert(distanceSquare(p2,p3));
        st.insert(distanceSquare(p2,p4));
        st.insert(distanceSquare(p3,p4));
        return !st.count(0)&&st.size()==2;
    }
};