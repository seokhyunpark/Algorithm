class Disjointset:
    def __init__(self, n):
        self.U = []
        for i in range(n):
            self.U.append(i)

    def equal(self, p, q):
        if (p == q):
            return True
        else:
            return False
    
    def find(self, i):
        j = i
        while (self.U[j] != j):
            j = self.U[j]
        return j
    
    def union(self, p, q):
        if (p < q):
            self.U[q] = p
        else:
            self.U[p] = q

def kruskal(n ,E):
    F = []
    E.sort(key = lambda x: x[2])
    dset = Disjointset(n + 1)
    while (len(F) < n - 1):
        edge = E.pop(0)
        i, j = edge[0], edge[1]
        p = dset.find(i)
        q = dset.find(j)
        if (not dset.equal(p, q)):
            dset.union(p, q)
            F.append(edge)
    return F

# def cost(F):
#     total = 0
#     for f in F:
#         total += f[2]
#     return total

n, m = map(int, input().split())
E = []
for i in range(m):
    u, v, w = map(int, input().split())
    E.append([u, v, w])
F = kruskal(n, E)
for f in F:
    print(*f)
