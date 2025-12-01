#Initializing the Graph Class
class Graph:
    def __init__(self, num_vertices):
        self.num_verts = num_vertices
        self.graph = []
        self.nodes = []

    def add_Edge(self, src, dest, wt):
        self.graph.append([src, dest, wt])

    def addNode(self, value):
        self.nodes.append(value)

    def relax_graph(self, dist):
        for u, v, w in self.graph:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
        return dist

    def bellman_ford(self, src):
        dist = {i: float("Inf") for i in self.nodes}
        dist[src] = 0

        for ind in range(self.num_verts - 1):
            dist = self.relax_graph(dist)

        new_dist = dist

        new_dist = self.relax_graph(new_dist)

        if new_dist != dist:
            print("Graph contains a negative edge cycle")
        else:
            print("Single source shortest path from " + str(src) + " to other nodes is: ")
            for ind in range(len(dist)):
                print("Distance from " + str(src) + " to " + str(ind) + " is: " + str(dist[ind]))


num_nodes = 6

g = Graph(num_nodes)

for node_ind in range(num_nodes):
    g.addNode(node_ind)

g.add_Edge(0, 1, 5)
g.add_Edge(1, 2, -2)
g.add_Edge(1, 5, -3)
g.add_Edge(2, 4, 3)
g.add_Edge(3, 2, 6)
g.add_Edge(3, 4, -2)
g.add_Edge(5, 3, 1)

g.bellman_ford(0)

