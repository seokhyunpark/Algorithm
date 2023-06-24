def prim(W):
    n = len(W) - 1
    F = []
    nearest = [-1] * (n + 1)
    distance = [-1] * (n + 1)
    for i in range(2, n + 1):
        nearest[i] = 1
        distance[i] = W[1][i]
    print_nearest(nearest)
    for _ in range(n - 1):
        minValue = INF
        for i in range(2, n + 1):
            if (0 <= distance[i] and distance[i] < minValue):
                minValue = distance[i]
                vnear = i
        edge = [vnear, nearest[vnear], W[nearest[vnear]][vnear]]
        F.append(edge)
        distance[vnear] = -1
        for i in range(2, n + 1):
            if distance[i] > W[i][vnear]:
                distance[i] = W[i][vnear]
                nearest[i] = vnear
        print_nearest(nearest)
    return F

def print_nearest(nearest):
    n = len(nearest) - 1
    for i in range(2, n):
        print(nearest[i], end=' ')
    print(nearest[i + 1])

INF = 999999
n, m = map(int, input().split())
W = [[INF] * (n + 1) for i in range(n + 1)]
for i in range(m):
    u, v, w = map(int, input().split())
    W[u][v] = w
    W[v][u] = w
F = prim(W)
for f in F:
    print(*f)
