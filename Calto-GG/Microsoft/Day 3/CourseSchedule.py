class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        from collections import defaultdict
        graph = defaultdict(list)
        for a, b in prerequisites:
            graph[b].append(a)

        # Create an array to track the in-degree (number of incoming edges) of each node
        in_degree = [0 for _ in range(numCourses)]
        for node in graph:
            for neighbor in graph[node]:
                in_degree[neighbor] += 1

        # Initialize a queue to hold nodes with no incoming edges (i.e. no prerequisites)
        queue = []
        for i in range(numCourses):
            if in_degree[i] == 0:
                queue.append(i)

        # Perform a topological sort
        while queue:
            node = queue.pop(0)
            for neighbor in graph[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)

        # If all nodes have been visited, a valid ordering exists and we return True
        # Otherwise, we return False
        return sum(in_degree) == 0