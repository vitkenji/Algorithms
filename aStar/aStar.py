import heapq

romania_map = {
    'Arad': {'Zerind': 75, 'Sibiu': 140, 'Timisoara': 118},
    'Zerind': {'Arad': 75, 'Oradea': 71},
    'Oradea': {'Zerind': 71, 'Sibiu': 151},
    'Sibiu': {'Arad': 140, 'Oradea': 151, 'Fagaras': 99, 'Rimnicu Vilcea': 80},
    'Timisoara': {'Arad': 118, 'Lugoj': 111},
    'Fagaras': {'Sibiu': 99, 'Bucareste': 211},
    'Rimnicu Vilcea': {'Sibiu': 80, 'Pitesti': 97, 'Craiova': 146},
    'Pitesti': {'Rimnicu Vilcea': 97, 'Bucareste': 101},
    'Craiova': {'Rimnicu Vilcea': 146, 'Drobeta': 120},
    'Bucareste': {'Fagaras': 211, 'Pitesti': 101},
}

heuristic = {
    'Arad': 366,
    'Zerind': 374,
    'Oradea': 380,
    'Sibiu': 253,
    'Timisoara': 329,
    'Fagaras': 178,
    'Rimnicu Vilcea': 193,
    'Pitesti': 98,
    'Craiova': 160,
    'Bucareste': 0
}

def a_star(start, goal, graph, heuristic):
    priority_queue = []
    heapq.heappush(priority_queue, (heuristic[start], 0, start, []))  # Corretamente empurrado para a fila
    visited = set()
    
    while priority_queue:
        f, g, node, path = heapq.heappop(priority_queue)
        if node in visited:
            continue
        
        visited.add(node)
        path = path + [node]

        if node == goal:
            return path, g

        for neighbor, weight in graph.get(node, {}).items():
            if neighbor not in visited:
                g_node = g + weight
                f_node = g_node + heuristic.get(neighbor, 0)
                heapq.heappush(priority_queue, (f_node, g_node, neighbor, path))  # Parêntese fechado corretamente
    
    return None, float('inf')

path, cost = a_star('Arad', 'Bucareste', romania_map, heuristic)

if path:
    print(f"{' -> '.join(path)}")
    print(f"{cost}")

