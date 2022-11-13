from Graph import Graph

g = Graph()
for i in range(9):
    g.addVertex(i)
print(g.vertList)
g.addEdge(0, 3)
g.addEdge(1, 3)
g.addEdge(2, 3)

g.addEdge(3, 5)
g.addEdge(3, 7)

g.addEdge(4, 5)

g.addEdge(5, 6)

g.addEdge(7, 8)
g.addEdge(6, 8)

g.DFS(2)
