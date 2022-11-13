from Graph import Graph

g = Graph()
for i in range(4):
    g.addVertex(i)
print(g.vertList)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(2, 1)
g.addEdge(1, 3)

inverse_g = Graph()
for i in range(g.getVertices().__len__()):
    inverse_g.addVertex(i)

print("Original Graph")
for vert in g:
    for neighbor in vert.getConnections():
        print("( %s, %s, %s )" % (vert.getId(), neighbor.getId(), vert.getWeight(neighbor)))
        inverse_g.addEdge(neighbor.getId(), vert.getId(), vert.getWeight(neighbor))

print("")
print("Inverse Graph")
for vert in inverse_g:
    for neighbor in vert.getConnections():
        print("( %s, %s, %s )" % (vert.getId(), neighbor.getId(), vert.getWeight(neighbor)))
