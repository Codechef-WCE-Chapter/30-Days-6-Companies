class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    priority_queue<pair<int,int>>pq;
    sort(barcodes.begin(),barcodes.end());
    int temp=0;
    for(int i=0;i< barcodes.size()-1;i++){
        if(barcodes[i]!=barcodes[i+1]){
            pq.push({temp+1,barcodes[i]});
            temp=0;
        }
        else{
            temp++;
        }
    }
    pq.push({temp+1,barcodes[barcodes.size()-1]});
    int n=barcodes.size();
    vector<int>ans(n,0);
    //Index 0
    int i=0;
    int cnt=pq.top().first;
    int elem=pq.top().second;
    while(i<n){
        if(cnt!=0){
            ans[i]=elem;
            cnt--;
        }
        else{
            pq.pop();
            cnt=pq.top().first;
            elem=pq.top().second;
            ans[i]=elem;
            cnt--;
        }
        i+=2;
    }
    //Index 1
    int j=1;
    while(j<n){
        if(cnt!=0){
            ans[j]=elem;
            cnt--;
        }
        else{
            pq.pop();
            cnt=pq.top().first;
            elem=pq.top().second;
            ans[j]=elem;
            cnt--;
        }
        j+=2;
    }
    return ans;
    }
};
