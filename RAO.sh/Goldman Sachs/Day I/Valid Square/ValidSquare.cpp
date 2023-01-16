class Solution {
public:
    int distance(vector<int>& A, vector<int>& B){return (A[0] - B[0])*(A[0] - B[0]) + (A[1] - B[1])*(A[1] - B[1]);} 
    

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> V;
        V.push_back(p1); V.push_back(p2); V.push_back(p3); V.push_back(p4);

        sort(V.begin(), V.end());

        int side1 = distance(V[0], V[1]), side2 = distance(V[0], V[2]), side3 = distance(V[1], V[3]), side4 = distance(V[2], V[3]);
        int dai1 = distance(V[0], V[3]), dia2 = distance(V[1], V[2]);

        if(!side1 or !side2 or !side3 or !side4 or !dai1 or !dia2) return false;

        if(side1 == side2 and side3 == side4 and dia2 == dai1) return true;

        return false;
    }
};
