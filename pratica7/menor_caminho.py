'''
Program: Menor Caminho entre dois nós em um grafo

Author: Arthur Oliveira

Date: 18/05/2025

Description: Implementa o algoritmo de Dijkstra para encontrar o menor caminho entre dois nós
            em um grafo representado por uma matriz de pesos .

License: CC BY
'''

import sys  # Importa o módulo sys para usar sys.maxsize como "infinito"

# Função que implementa o algoritmo de Dijkstra
def dijkstra(matrix, s, t):
    n = len(matrix)  # Número de vértices do grafo

    # Inicializa a lista de distâncias com "infinito"
    dist = [sys.maxsize] * n
    dist[s] = 0  # A distância do vértice de origem para ele mesmo é zero

    # Lista de predecessores para reconstruir o caminho mínimo
    prev = [None] * n

    # Conjunto de vértices ainda não visitados
    unvisited = set(range(n))

    # Enquanto houver vértices não visitados
    while unvisited:
        # Seleciona o vértice não visitado com menor distância conhecida
        u = min(unvisited, key=lambda vertex: dist[vertex])
        unvisited.remove(u)  # Marca o vértice como visitado

        # Se já chegamos no destino, encerramos o laço
        if u == t:
            break

        # Para cada vizinho v de u
        for v in range(n):
            # Se v não foi visitado e há uma aresta de u para v
            if v in unvisited and matrix[u][v] != sys.maxsize:
                alt = dist[u] + matrix[u][v]  # Calcula distância alternativa até v
                if alt < dist[v]:  # Se essa distância for menor, atualiza
                    dist[v] = alt
                    prev[v] = u  # Registra o caminho

    # Reconstrução do caminho mínimo
    path = []
    u = t
    while u is not None:
        path.insert(0, u)  # Insere o vértice no início do caminho
        u = prev[u]

    return dist[t], path  # Retorna a distância total e o caminho encontrado

# Define a matriz de adjacência com pesos
matrix = [
    [0, 5, 1, 2, sys.maxsize, sys.maxsize, sys.maxsize, sys.maxsize, sys.maxsize],
    [5, 0, sys.maxsize, sys.maxsize, sys.maxsize, sys.maxsize, sys.maxsize, sys.maxsize, 3],
    [1, sys.maxsize, 0, sys.maxsize, 1, sys.maxsize, sys.maxsize, sys.maxsize, sys.maxsize],
    [2, sys.maxsize, sys.maxsize, 0, sys.maxsize, 1, sys.maxsize, sys.maxsize, sys.maxsize],
    [sys.maxsize, sys.maxsize, 1, sys.maxsize, 0, sys.maxsize, sys.maxsize, 1, sys.maxsize],
    [sys.maxsize, sys.maxsize, sys.maxsize, 1, sys.maxsize, 0, 1, sys.maxsize, sys.maxsize],
    [sys.maxsize, sys.maxsize, sys.maxsize, sys.maxsize, sys.maxsize, 1, 0, 3, 2],
    [sys.maxsize, 1, sys.maxsize, sys.maxsize, sys.maxsize, 1, sys.maxsize, 0, 3],
    [sys.maxsize, 3, sys.maxsize, sys.maxsize, sys.maxsize, sys.maxsize, 2, sys.maxsize, 0]
]

# Teste da função dijkstra
s = 0  # Vértice de origem
t = 8  # Vértice de destino

# Executa o algoritmo
distancia, caminho = dijkstra(matrix, s, t)

# Imprime os resultados
print(f"Distância mínima de {s} a {t}: {distancia}")
print(f"Caminho: {' -> '.join(map(str, caminho))}")
