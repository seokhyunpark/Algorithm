def bin(n, k):
    if (k > n // 2):
        k = n - k
    B = [0] * (k + 1)
    B[0] = 1
    for i in range(1, n + 1):
        j = min(i, k)
        while (j > 0):
            B[j] = (B[j] + B[j - 1]) % 10007
            j -= 1
    return B[k]

n, k = map(int, input().split())
print(bin(n, k))
