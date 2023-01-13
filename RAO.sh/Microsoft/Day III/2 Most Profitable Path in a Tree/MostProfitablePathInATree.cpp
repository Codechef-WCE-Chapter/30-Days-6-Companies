#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define MOD 1000000007

/*
Approach:
    1. As Alice can have multiple paths to reach the leaf node but Bob can have only 1 path to reach the root node. So firstly we'll find Bob's path.
    2. Now we'll traverse the tree from the root node and find the maximum profit Alice can make by taking the path which is not the same as Bob's path.
    3. We'll use a vector to store the path of Bob and a boolean variable to check if the current node is in Bob's path or not.
    4. We'll traverse the tree in a DFS manner and check if the current node is in Bob's path or not. If yes, we'll return the profit Alice can make by taking the path which is not the same as Bob's path.
    5. If the current node is not in Bob's path, we'll check if the current node is a leaf node or not. If yes, we'll return the profit Alice can make by taking the path which is not the same as Bob's path.
    6. If the current node is not a leaf node, we'll traverse the adjacency list of the current node and check if the current node is in Bob's path or not. If yes, we'll return the profit Alice can make by taking the path which is not the same as Bob's path.
*/

class Solution{
public:
    bool bob_path(int n, vector<int>& path, vector<bool>& visited, vector<vector<int>>& ADJ){
        if(!n){
            path.push_back(n);
            return true;
        }

        if(visited[n]) return false;    // Already visited

        visited[n] = true;  // Mark visited as true

        // Traversing the adjacency matrix
        for(auto edge : ADJ[n]){
            bool flag = bob_path(edge, path, visited, ADJ);

            if(!flag) continue;

            path.push_back(n);
            return true;
        }

        return 0;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount){
        int n = amount.size();

        vector<vector<int>> ADJ(n, vector<int>()); // Adjacency Matrix
        for(auto edge : edges){
            ADJ[edge[0]].push_back(edge[1]);
            ADJ[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited_B(n, false);
        vector<int> path_B;
        bob_path(bob, path_B, visited_B, ADJ);

        amount[bob] = 0;
        path_B.pop_back();

        int val = amount[0], maxVal = INT_MIN;;
        vector<bool> visited_A(n, false);  // visited array for Alice
        queue<pair<int, int>> Q({{0, val}});  // Pair Queue: Pair.first = Node, Pair.second = Amount/Value

        visited_A[0] = 1;   // Root node marked as visited

        // BFS for Alice with Bob's path
        while(!Q.empty()){
            int len_Q = Q.size();

            // Bob's Path
            int bob_node = -1;
            if(!path_B.empty()){
                bob_node = path_B.back();
                path_B.pop_back();
            }

            // Alice's movement
            while(len_Q--){
                int node_A = Q.front().first;   // Alice's node
                int val = Q.front().second;     // Amount/Value of Alice's node
                Q.pop();

                // Lead Node condition
                if(ADJ[node_A].size() == 1 && node_A != 0){
                    maxVal = max(maxVal, val);
                    continue;
                }

                // Traversing the Adjacency list of Alice's node
                for(auto child : ADJ[node_A]){
                    if(visited_A[child]) continue;      // If visited then skip

                    visited_A[child] = true;            // Mark visited true

                    if(child != bob_node) Q.push({child, val + amount[child]}); // If it's not Bob's nod            
                    else Q.push({child, val + amount[child]/2}); // If it is Bob's Node
                }
            }

            // If Bob visits the node first then amout becomes 0
            if(bob_node != -1) amount[bob_node] = 0;
        }

        return maxVal;
    }
};

void solve(){
    Solution s;
    

    return;
}

int main(){
    fastIO
    ll t;
    cin>>t;
           
    while(t--){
        solve();
    }
              
    return 0;
}
