class Solution {
public:
vector<int>bobArrows;//answer array 
int maxPoints=0; //stores the maximum points by bob
    void solve(int ind,int score,int arrow,vector<int> &nums,vector<int> &res){
        //if ind goes negitive or arrows count became 0.
        if(arrow==0||ind<0){
            // Then check if current score is the maximum score. If score is maximum the res array is bobArrows array.
            if(score>maxPoints){
                maxPoints=score;
                bobArrows=res;
            }
            return;
        }

        //if available arrows is greater than the arrorws requires for the current score index then we can take this score.
        if(arrow>nums[ind]){
           res[ind]=nums[ind]+1;
            solve(ind-1,score+ind,arrow-(nums[ind]+1),nums,res);    //taking the current index score.
          res[ind]=0;
           
        }
        //Here we are not taking the current index score.
        solve(ind-1,score,arrow,nums,res);
        
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>res(12,0);
        // vector<int> bobArrows;
        // int points = 0;
        solve(11,0,numArrows,aliceArrows,res);

        int count=0;
        for(auto it:bobArrows) count+=it;

        if(numArrows-count>0){
            bobArrows[0] += numArrows - count;
        }

        return bobArrows;
    }
};
