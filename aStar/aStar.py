import heapq
import pygame
import time

pygame.init()

SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption('A* Algorithm Visualization')

WHITE = (255,255,255)
RED = (255,0,0)
GREEN = (0,255,0)
BLUE = (0,0,255)
BLACK = (0,0,0)

coordinates = {
    'Arad': (100, 500),
    'Zerind': (200, 450),
    'Oradea': (250, 400),
    'Sibiu': (350, 450),
    'Timisoara': (100, 350),
    'Fagaras': (450, 350),
    'Rimnicu Vilcea': (450, 400),
    'Pitesti': (500, 300),
    'Craiova': (600, 200),
    'Bucareste': (700, 100),
    'Lugoj': (200, 300),
    'Drobeta': (550, 250)
}



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

def draw_map(screen, coordinates, graph):
    for node, (x, y) in coordinates.items():
        pygame.draw.circle(screen, BLUE, (x, y), 5)
        font = pygame.font.SysFont(None, 20)
        label = font.render(node, True, BLACK)
        screen.blit(label, (x + 5, y - 5))
    
    for node, neighbors in graph.items():
        x1, y1 = coordinates[node]
        for neighbor, distance in neighbors.items():
            x2, y2 = coordinates[neighbor]
            pygame.draw.line(screen, BLACK, (x1, y1), (x2, y2), 1)

def draw_path(screen, coordinates, path):
    for i in range(len(path) - 1):
        start = coordinates[path[i]]
        end = coordinates[path[i + 1]]
        pygame.draw.line(screen, GREEN, start, end, 3)


def a_star(start, goal, graph, heuristic, screen, coordinates):
    priority_queue = []
    heapq.heappush(priority_queue, (heuristic[start], 0, start, []))
    visited = set()
    
    while priority_queue:
        f, g, node, path = heapq.heappop(priority_queue)
        if node in visited:
            continue
        
        visited.add(node)
        path = path + [node]

        screen.fill(WHITE)
        draw_map(screen, coordinates, graph)
        draw_path(screen, coordinates, path)
        pygame.display.update()
        time.sleep(1)

        if node == goal:
            return path, g

        for neighbor, weight in graph.get(node, {}).items():
            if neighbor not in visited:
                g_node = g + weight
                f_node = g_node + heuristic.get(neighbor, 0)
                heapq.heappush(priority_queue, (f_node, g_node, neighbor, path)) 
    return None, float('inf')

path, cost = a_star('Arad', 'Bucareste', romania_map, heuristic, screen, coordinates)

if path:
    print(f"{' -> '.join(path)}")
    print(f"{cost}")

