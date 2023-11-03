from typing import List

def bfsTraversal(n: int, adj: List[List[int]]) -> List[int]:
    # write your code here
    bfs_trav = []
    visited = [False]*n
    graph = [[] for _ in range(n)]

    for node in range(n):
        for edge in adj[node]:
            if edge != 0:
                graph[node].append(edge)

    q = []
    q.append(0)
    visited[0] = True

    while len(q) != 0:
        top = q[0]
        q.pop(0)
        bfs_trav.append(top)

        for neigh in graph[top]:
            if not visited[neigh]:
                q.append(neigh)
                visited[neigh] = True
    
    return bfs_trav