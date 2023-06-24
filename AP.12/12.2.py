def isIn(i, A):
    if ((A & (1 << (i - 2))) != 0):
        return True
    return False

def diff(A, j):
    t = 1 << (j - 2)
    return (A & (~t))

def count(A, n):
    count = 0
    for i in range(n):
        if ((A & (1 << i)) != 0):
            count += 1
    return count

def minimum(W, D, i, A):
    minValue = INF
    minJ = 1
    n = len(W) - 1
    for j in range(2, n + 1):
        if (isIn(j, A)):
            m = W[i][j] + D[j][diff(A, j)]
            if (minValue > m):
                minValue = m
                minJ = j
    return minValue, minJ

def travel(W):
    n = len(W) - 1
    size = 2 ** (n - 1)
    D = [[0] * size for _ in range(n + 1)]
    P = [[0] * size for _ in range(n + 1)]
    for i in range(2, n + 1):
        D[i][0] = W[i][1]
    for k in range(1, size):
        for A in range(1, size):
            if (count(A, n) == k):
                for i in range(2, n + 1):
                    if (not isIn(i, A)):
                        D[i][A], P[i][A] = minimum(W, D, i, A)
    A = size - 1
    D[1][A], P[1][A] = minimum(W, D, 1, A)
    return D, P

def tour(i, A, P):
    k = P[i][A]
    if (k == 0):
        print(1)
    else:
        print(k, end=" ")
        tour(k, diff(A, k), P)

INF = 999
n, m = map(int, input().split())
W = [[INF] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    W[u][v] = w
D, P = travel(W)
print(D[1][2 ** (n - 1) - 1])
print(1, end=" ")
tour(1, 2 ** (n - 1) - 1, P)

for i in range(len(D)):
    for j in range(len(D[i])):
        if (D[i][j] != INF and D[i][j] != 0):
            print(i, j, D[i][j])
