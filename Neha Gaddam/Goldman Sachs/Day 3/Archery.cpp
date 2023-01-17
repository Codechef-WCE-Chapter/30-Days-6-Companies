class Solution {
public:
    vector<int>ans;
    int mx=0;
    void Bob(int i,int num,vector<int>&arrow,int total,vector<int>&t)
    {
        if(i<0)
        {
            //cout<<num<<" ";
            if(total>=mx)
            {
                ans=t;
                mx=total;
            }
            return ;
        }
        if(num==0)
        {
            // cout<<total<<" ";
            if(total>=mx)
            {
                ans=t;
                mx=total;
            }
            return;
        }
        if(num<0)
            return;
        Bob(i-1,num,arrow,total,t);
        int k=arrow[i]+1;
        // 
        
        if(i==0)
        {
             k=num;
        }
        num-=k;
        total+=i;
        // cout<<k<<endl;
        
        t[i]=k;
        Bob(i-1,num,arrow,total,t);
        t[i]=0;
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>v(12,0);
        int tt=0;
        for(int i=0;i<=11;i++)
            if(aliceArrows[i]) tt+=i;
        Bob(11,numArrows,aliceArrows,0,v);
        return ans;

    }
};