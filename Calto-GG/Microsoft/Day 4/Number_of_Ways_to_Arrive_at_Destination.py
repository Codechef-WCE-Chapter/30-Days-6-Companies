# For Explanation -> https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/solutions/3038756/using-dijkstra-s-algorithm-beats-97-97/
import heapq
class Solution:
    def countPaths(self, n: int, roads: list[list[int]]) -> int:
        # Create a priority queue to store nodes to be processed
        pq = [(0, 0)]  # (distance, node)
        # Create a dictionary to store the distance to each node
        dist = {i: float('inf') for i in range(n)}
        dist[0] = 0
        # Create a dictionary to store the number of paths to each node
        paths = {i: 0 for i in range(n)}
        paths[0] = 1
        # Create a dictionary to store the neighbors of each node
        neighbors = {i: [] for i in range(n)}
        for u, v, time in roads:
            neighbors[u].append((v, time))
            neighbors[v].append((u, time))
        # Dijkstra's algorithm to find the shortest path
        while pq:
            d, u = heapq.heappop(pq)
            if d == dist[u]:
                for v, time in neighbors[u]:
                    if dist[u] + time < dist[v]:
                        dist[v] = dist[u] + time
                        paths[v] = paths[u]
                        heapq.heappush(pq, (dist[v], v))
                    elif dist[u] + time == dist[v]:
                        paths[v] += paths[u]
                        paths[v] = paths[v] % (10**9 + 7)
        return paths[n-1]

