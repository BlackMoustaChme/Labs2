from Graph import Graph
from Vertex import Vertex


def dijkstra(graph: Graph, start_node: Vertex):
    unvisited_nodes = list(graph.getVertices())
    shortest_path = {}
    prev_nodes = {}
    infinity = float("inf")
    for node in unvisited_nodes:
        shortest_path[node] = infinity
    shortest_path[start_node.getId()] = 0

    while unvisited_nodes:
        current_min_node = None
        for node in unvisited_nodes:
            if current_min_node == None:
                current_min_node = node
            elif shortest_path[node] < shortest_path[current_min_node]:
                current_min_node = node

        neighbors = []
        for neighbor in graph.getVertex(current_min_node).getConnections():
            neighbors.append(neighbor.getId())
        for neighbor in neighbors:
            nbr = graph.getVertex(neighbor)

            tentative_value = shortest_path[current_min_node] + graph.getVertex(current_min_node).getWeight(nbr)
            if tentative_value < shortest_path[neighbor]:
                shortest_path[neighbor] = tentative_value
                prev_nodes[neighbor] = current_min_node
        unvisited_nodes.remove(current_min_node)
    return prev_nodes, shortest_path


def print_path(prev_nodes: dict, shortest_path: dict, start_node: str, end_node: str):
    path = []
    node = end_node
    while node != start_node:
        path.append(node)
        try:
            node = prev_nodes[node]
        except:
            print("Нет подходящего маршрута")
            return

    path.append(start_node)
    path.reverse()
    print("Лучший маршрут:", end=" ")
    print(" -> ".join(path))
    print("Расстояние:", shortest_path[end_node])


g = Graph()
g.addEdge("Белово", "Ленинск-Кузнецкий", 39)
g.addEdge("Белово", "Гурьевск", 34)
g.addEdge("Ленинск-Кузнецкий", "Гурьевск", 70)
g.addEdge("Ленинск-Кузнецкий", "Мыски", 203)
g.addEdge("Ленинск-Кузнецкий", "Кемерово", 86)
g.addEdge("Ленинск-Кузнецкий", "Новосибирск", 236)
g.addEdge("Киселевск", "Ленинск-Кузнецкий", 91)
g.addEdge("Киселевск", "Новосибирск", 328)
g.addEdge("Гурьевск", "Мыски", 206)
g.addEdge("Мыски", "Кемерово", 282)
g.addEdge("Новосибирск", "Кемерово", 260)

starting_point = input()
destination_point = input()
start_node = g.getVertex(starting_point)
end_node = g.getVertex(destination_point)

prev_nodes, shortest_path = dijkstra(g, start_node)
print_path(prev_nodes, shortest_path, start_node.getId(), end_node.getId())
