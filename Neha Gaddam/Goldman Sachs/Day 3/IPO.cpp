class Solution {
public:
    
    bool get_max_profit(vector<int>v1,vector<int>v2)
    {
        if(v1[0]==v2[0])
            return v1[1]<v2[1];
        return v1[0]>v2[0];
    }
    
    bool get_min_capital(vector<int>v1,vector<int>v2)
    {
        if(v1[0]==v2[0])
            return v1[1]>v2[1];
        return v1[0]<v2[0];
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        
        priority_queue<vector<int>>max_profit;
        priority_queue<vector<int>,vector<vector<int>>,greater<>>min_capital;
        
        
        
        for(int i=0;i<profits.size();i++)
        {
            max_profit.push({profits[i],capital[i]});
        }
        
        int answer=w;
        while(k>0)
        {
            while(!min_capital.empty() and min_capital.top()[0]<=answer)
            {
                //answer+=min_capital.top()[1];
                
               max_profit.push({min_capital.top()[1],min_capital.top()[0]});
                min_capital.pop();
            }
            while(!max_profit.empty() and max_profit.top()[1]>answer)
            {
                min_capital.push({max_profit.top()[1],max_profit.top()[0]});
                max_profit.pop();
              
            }
            
            if(max_profit.empty())
                return answer;
            
            
            answer+=max_profit.top()[0];
             k--;
            max_profit.pop();
            
        }
        
        return answer;
    }
};