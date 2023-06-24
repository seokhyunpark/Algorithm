def dijkstra(W):
    n = len(W) - 1
    F = []
    touch = [-1] * (n + 1)
    length = [-1] * (n + 1)
    for i in range(2, n + 1):
        touch[i] = 1
        length[i] = W[1][i]
    print(*touch[2:])
    for _ in range(n - 1):
        minValue = INF
        for i in range(2, n + 1):
            if (0 <= length[i] and length[i] < minValue):
                minValue = length[i]
                vnear = i
        edge = [touch[vnear], vnear, W[touch[vnear]][vnear]]
        F.append(edge)
        for i in range(2, n + 1):
            if length[i] > length[vnear] + W[vnear][i]:
                length[i] = length[vnear] + W[vnear][i]
                touch[i] = vnear
        length[vnear] = -1
        print(*touch[2:])
    return F, touch

def find_path(touch, u, v):
    if u == v:
        return [u]
    else:
        return find_path(touch, u, touch[v]) + [v]

INF = 999999
n, m = map(int, input().split())
W = [[INF] * (n + 1) for i in range(n + 1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    W[u][v] = w
    W[v][u] = w
F, touch = dijkstra(W)
for f in F:
    print(*f)
t = int(input())
for _ in range(t):
    n = int(input())
    path = find_path(touch, 1, n)
    print(*path)
