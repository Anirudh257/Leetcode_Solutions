# Time complexity: O(V + E), Space complexity: O(V) for visited, O(E) for building  graph + Auxiliary space : O(V) = O(V + E)
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        num_comps = 0
        graph = [[] for _ in range(n)]
        visited = [False]*n

        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])

        def dfs(node):
            visited[node] = True

            for neigh in graph[node]:
                if not visited[neigh]:
                    dfs(neigh)
        
        for i in range(n):
            if not visited[i]:
                num_comps += 1
                dfs(i)

        return num_comps