class Solution { 
    // It won't be possible to complete the courses
    // if courseA and courseB
    // are directly or indirectly pre-requisite of
    // each other
    // i.e. if a cycle is formed.
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<Integer>[] graph = new ArrayList[numCourses];
        
        // form a graph with edge from A to B if 
        // A is pre-requisite for B
        for(int i = 0 ; i <  numCourses; i++){
            graph[i] = new ArrayList<>() ;
        }
        for (int[] edge: prerequisites){
            graph[edge[0]].add(edge[1]) ;
        }
       
        return !isCycle(graph, numCourses) ;
    }

    boolean isCycle(ArrayList<Integer>[] graph, int n{ 
        
        /*
            - indegree represets number of 
              edges coming to that vertex.
            - In this case, it represents, number
              of prerequisites of course-i
        */
        int[] indegree = new int[n] ;
        
        for (int i = 0; i < n; i++) {
            for (int nbr: graph[i]) {
                indegree[nbr]++ ;
            }
        }
        
        Queue<Integer> q = new  LinkedList<>() ;

        // Add all the courses with zero 
        // pre-requisites in the queue
        for (int i = 0 ; i <  n; i++){
            if (indegree[i] == 0){
                q.offer(i) ;
            }
        }
        
        // visitedNodes represents number of courses
        // completed
        int visitedNodes = 0 ;
        
        while(!q.isEmpty()){
            // courses polled from queue is considered
            // to be completed
            int curr = q.poll() ;
            
            visitedNodes++ ;
            
            // decrease the number of pre-requisite
            // of all the courses for which
            // currCourse was a pre-requisite
            // as it is completed
            for (int nbr: graph[curr]){
                indegree[nbr]-- ;

                // if all pre-requisites are completed
                // add the course in the queue
                if (indegree[nbr] == 0){
                    q.offer(nbr) ;
                }
            }
        }
        
        // if all the nodes are visited, there's no
        // cycle else there is a cycle
        return visitedNodes != n ;
    }
}
