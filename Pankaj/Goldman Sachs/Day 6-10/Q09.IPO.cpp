class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();//total no. of projects
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({capital[i],profits[i]});
        }
        priority_queue<int> pq;
        sort(arr.begin(),arr.end());//sort the projects according to the requirements of capital of a project
        int i=0;
        while(i<n and k){
            if(w>=arr[i].first){
                pq.push(arr[i++].second);
            }
            else{
                if(pq.empty()) return w;
                w+=pq.top();
                pq.pop();
                k--;
            }
        }
        while(k-- and !pq.empty()){
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};