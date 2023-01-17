


class Solution{
public:
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    
    int n=profits.size();

    vector<pair<int,int>> projects(n); // forming a pair to store profit and capitals

    for(int i=0;i<n;i++)
    
    {
         projects[i]={profits[i],capital[i]}; 
    }

    int i=0;
    // Sorting pairs as per Capital
    sort(projects.begin(),projects.end(),[&](pair<int,int> a,pair<int,int> b){ return a.second<b.second;});

    // to take the max profit from the projects
    priority_queue<int> maxProfit;


    while(k--){
        while(i<n && w>=projects[i].second)
        
        {
            
             maxProfit.push(projects[i++].first);

        }
        
        if(!maxProfit.empty()){
            
             ans+=maxProfit.top(),maxProfit.pop();

        }
    }
    
    return ans;
}
};
