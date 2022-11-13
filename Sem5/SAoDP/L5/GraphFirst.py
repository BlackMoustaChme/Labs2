from Graph import Graph

g = Graph()
for i in range(6):
    g.addVertex(i)
print(g.vertList)
g.addEdge(0, 1, 5)
g.addEdge(0, 5, 2)
g.addEdge(1, 2, 4)
g.addEdge(2, 3, 9)
g.addEdge(3, 4, 7)
g.addEdge(3, 5, 3)
g.addEdge(4, 0, 1)
g.addEdge(5, 4, 8)
g.addEdge(5, 2, 1)
for vert in g:
    for neighbor in vert.getConnections():
        print("( %s, %s, %s )" % (vert.getId(), neighbor.getId(), vert.getWeight(neighbor)))
