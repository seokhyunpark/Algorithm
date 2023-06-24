def floyd(D):
    n = len(D)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                D[i][j] = min(D[i][j], D[i][k] + D[k][j])

def floyd2(W):
    n = len(W)
    D = W
    P = [[0 for _ in range(n)] for _ in range(n)]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if (D[i][j] > D[i][k] + D[k][j]):
                    D[i][j] = D[i][k] + D[k][j]
                    P[i][j] = k + 1
    return D, P

def path(P, u, v, p):
    if P[u][v] != 0:
        path(P, u, P[u][v] - 1, p)
        p.append(P[u][v])
        path(P, P[u][v] - 1, v, p)

INF = 999
n, m = map(int, input().split())
D = [[0 for _ in range(n)] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    D[u - 1][v - 1] = w
for i in range(n):
    for j in range(n):
        if D[i][j] == 0 and i != j:
            D[i][j] = INF
D, P = floyd2(D)

for i in range(n):
    for j in range(n - 1):
        print(D[i][j], end=' ')
    print(D[i][j + 1])

for i in range(n):
    for j in range(n - 1):
        print(P[i][j], end=' ')
    print(P[i][j + 1])

t = int(input())
for _ in range(t):
    u, v = map(int, input().split())
    if D[u - 1][v - 1] == INF:
        print("NONE")
    else:
        p = [u]
        path(P, u - 1, v - 1, p)
        p.append(v)
        print(*p)
