#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define MOD 1000000007

/*
    Approach:
    1. Use 2 vectors, one to store the num of incoming edges(indegree of the node) on a node and another to store the adjacency matrix.
    2. Push all the nodes with 0 indegree in a queue. So we could start with courses which doesn't require any prerequisites.
    3. Pop the node from the queue and increment the count of courses taken. Once popped we can say that, we completed the course.
    4. Traverse the adjacency matrix to check which course we can take upon. Decrease it's indegree by 1, as we completed one of it's prerequisite.
    5. While traversing check if the indegree of a particular node is 0, means if all the prerequisites of a paricular node are done.
        If yes: add it to the queue.
    6. Repeat the process from 3 until the queue is empty.
    7. If the count of courses taken is equal to the total number of courses, then we can say that we can complete all the courses.
*/
class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> inDegree(numCourses, 0);    // vector to store number of incoming edges i.e. frequecny
        vector<vector<int>> ADJ(numCourses);    // Adjacency Matrix

        // Fill the frequency and Adjacency matrix
        for(auto x : prerequisites){
            inDegree[x[0]]++;
            ADJ[x[1]].push_back(x[0]);
        }

        queue<int> q;   // Queue to store courses with no prerequisites or completed prerequisites.
        for(int i=0; i<numCourses; i++) if(!inDegree[i]) q.push(i);
        
        int count = 0;  // to store num of course completed
        while(!q.empty()){
            int curr = q.front(); // course to be completed
            q.pop();

            count++;
            // traversing the adjacency list and reducing the indegree's
            for(auto x : ADJ[curr]){
                inDegree[x]--;
                if(!inDegree[x]) q.push(x);
            }
        }

        return count == numCourses; // return true if all of the courses are completed
    }
};


int main(){
    fastIO

    int numCourses = 3;
    vector<vector<int>> prerequisites_1 = {{1,0}, {2,1}, {0,2}};
    Solution obj_1;
    cout << obj_1.canFinish(numCourses, prerequisites_1) << endl;

    vector<vector<int>> prerequisites_2 = {{1,0}, {2,1}};
    Solution obj_2;
    cout << obj_2.canFinish(numCourses, prerequisites_2) << endl;

    return 0;
}
