class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
                  int res=1;
                  int flg=0,flg1=0;
          for(int i=0;i<p.size()-1;i++)
          {
              if(p[i][0]!=p[i+1][0])
              {
                  flg=0;
                  break;
              }
              else
              {
                flg=1;
              }

                           
          }
  for(int i=0;i<p.size()-1;i++)
  {
       if(p[i][1]!=p[i+1][1])
              {
                  flg1=0;
                  break;
              }
              else
              {
                flg1=1;
              }
  }

          if(flg1 or flg)
          {
              return p.size();
          }
        for(int i=0;i<p.size();i++)
        {
            unordered_map<double,int>mp;
            
        
            for(int j=i+1;j<p.size();j++)
            {
               double m=(double)(p[i][0]-p[j][0])/(p[i][1]-p[j][1]);

                mp[m]++;
            res=max(res,mp[m]+1);
            }
            
            
        }
  
        // for(auto m:mp)
        // {
           
        // }
        return res;
    }
};