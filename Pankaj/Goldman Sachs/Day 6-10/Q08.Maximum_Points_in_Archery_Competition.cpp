class Solution {
public:
    vector<int> bobArrows;
    int total_arrows=0;
    void solve(int idx,int n,vector<int>& ds,vector<int>& aliceArrows,int &maximumScore){
        if(idx==12){
            int score=0;
            int arrows=0;
            for(int i=0;i<12;i++){
                if(ds[i]>aliceArrows[i]){
                    score+=(i);
                }
                arrows+=ds[i];
            }
            if(maximumScore<score){
                maximumScore=score;
                ds[0]+=(total_arrows-arrows);
                bobArrows=ds;
                ds[0]-=(total_arrows-arrows);
            }
            return;
        }
        if(aliceArrows[idx]+1<=n){
            ds[idx]+=aliceArrows[idx]+1;
            solve(idx+1,n-aliceArrows[idx]-1,ds,aliceArrows,maximumScore);
            ds[idx]-=(aliceArrows[idx]+1);
        } 
        solve(idx+1,n,ds,aliceArrows,maximumScore);
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        bobArrows.resize(12,0);
        vector<int> ds(12,0);
        int maximumScore=0;
        total_arrows=numArrows;
        solve(1,numArrows,ds,aliceArrows,maximumScore);
        return bobArrows;
    }
};