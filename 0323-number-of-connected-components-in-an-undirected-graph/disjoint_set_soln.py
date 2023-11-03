# Time complexity: O(V) to build the parent and size arrays + O(E.alpha(V)) to perform combine operation for E edges = O(V + E.alpha(V))
# Space complexity: O(V) for parent and size arrays
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parent = [_ for _ in range(n)]
        size = [1]*n
        num_comps = n

        def findPar(node):
            if node != parent[node]:
                parent[node] = findPar(parent[node])
            
            return parent[node]

        def combine(x, y):
            par_x = findPar(x)
            par_y = findPar(y)

            if par_x == par_y:
                return 0
            else:
                if size[par_x] > size[par_y]:
                    parent[par_y] = par_x
                    size[par_x] += size[par_y]
                else:
                    parent[par_x] = par_y
                    size[par_y] += size[par_x]
                return 1

        for e in edges:
            num_comps -= combine(e[0], e[1])

        return num_comps