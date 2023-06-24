def tri(row, col):
    global A, B
    if row == n - 1:
        return A[row][col]
    if B[row][col] != 0:
        return B[row][col]
    B[row][col] = A[row][col] + max(tri(row + 1, col), tri(row + 1, col + 1))
    return B[row][col]

def path(row, col):
    global A, B
    if row == n - 1:
        return [A[row][col]]
    if B[row + 1][col] > B[row + 1][col + 1]:
        return [A[row][col]] + path(row + 1, col)
    else:
        return [A[row][col]] + path(row + 1, col + 1)

n = int(input())
A = [[0 for _ in range(n)] for _ in range(n)]
B = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    A[i] = list(map(int, input().split()))

print(tri(0, 0))
print(*path(0, 0))
