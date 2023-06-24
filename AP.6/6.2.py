def optsearchtree(p):
    n = len(p) - 1
    A = [[0] * (n + 1) for _ in range(n + 2)]
    R = [[0] * (n + 1) for _ in range(n + 2)]
    for i in range(1, n + 1):
        A[i][i - 1] = 0
        A[i][i] = p[i]
        R[i][i - 1] = 0
        R[i][i] = i
    A[n + 1][n] = 0
    R[n + 1][n] = 0
    for diagonal in range(1, n):
        for i in range(1, n - diagonal + 1):
            j = i + diagonal
            A[i][j], R[i][j] = minimum(A, p, i, j)
    return A, R

def minimum(A, p, i, j):
    minValue = INF
    minK = 0
    for k in range(i, j + 1):
        value = A[i][k - 1] + A[k + 1][j]
        for m in range(i, j + 1):
            value += p[m]
        if (minValue > value):
            minValue = value
            minK = k
    return minValue, minK

def tree(R, i, j):
    k = R[i][j]
    if (k == 0):
        return None
    else:
        node = BSTNode(K[k])
        node.left = tree(R, i, k - 1)
        node.right = tree(R, k + 1, j)
        return node

class BSTNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
    
def preorder(node):
    if (node is None):
        return
    else:
        po.append(node.key)
        preorder(node.left)
        preorder(node.right)

def inorder(node):
    if (node is None):
        return
    else:
        inorder(node.left)
        io.append(node.key)
        inorder(node.right)


INF = 999999

n = int(input())
K = list(map(int, input().split()))
p = list(map(int, input().split()))
K.insert(0, 0)
p.insert(0, 0)
A, R = optsearchtree(p)
for i in range(1, len(A)):
    print(*A[i][i - 1:])
for i in range(1, len(R)):
    print(*R[i][i - 1:])
print(A[1][n])

root = tree(R, 1, n)
po = []
io = []
preorder(root)
inorder(root)
print(*po)
print(*io)
