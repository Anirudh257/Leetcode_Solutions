class Graph:
    def __init__(self, num_vertices):
        self.num_verts = num_vertices
        self.graph = []*self.num_verts

    def add_edge(self, src, dest, wt):
        self.graph[src].append([dest, wt])

    def djikstra(self, src):
        dest = [float('inf')*self.num_verts]
        dest[src] = 0



g = Graph(6)

# src, dest, wt
g.add_edge(1, 2, 2)
g.add_edge(1, 4, 1)

g.add_edge(2, 1, 2)
g.add_edge(2, 3, 4)
g.add_edge(2, 5, 5)

g.add_edge(3, 2, 4)
g.add_edge(3, 4, 3)
g.add_edge(3, 5, 1)

g.add_edge(4, 1, 1)
g.add_edge(4, 3, 3)

g.add_edge(5, 2, 5)
g.add_edge(5, 3, 1)

src = 1
g.comp_djikstra(src)