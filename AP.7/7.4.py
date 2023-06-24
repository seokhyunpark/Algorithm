def selection(n, s, f):
    S, T = [], []
    F = 0
    for k in range(1, n + 1):
        if F <= s[k]:
            S += [k]
            F = f[k]
            T.append([s[k], f[k]])
    return S, T

n = int(input())
s, f = [0] * (n + 1), [0] * (n + 1)
for i in range(1, n + 1):
    s[i], f[i] = map(int, input().split())
solution, T = selection(n, s, f)
print(len(solution))
for t in T:
    print(*t)
