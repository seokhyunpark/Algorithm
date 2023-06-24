def knapsack2(i, W, w, p):
    if (i <= 0 or W <= 0):
        return 0
    else:
        left = knapsack2(i - 1, W, w, p)
        right = knapsack2(i - 1, W - w[i], w, p)
        if (w[i] > W):
            P[(i, W)] = left
        else:
            P[(i, W)] = max(left, p[i] + right)
        return P[(i, W)]

n = int(input())
w = list(map(int, input().split()))
p = list(map(int, input().split()))

sorted_items = list(sorted(zip(w, p), key=lambda x: x[1] / x[0], reverse=True))
w, p = zip(*sorted_items)
w = [0] + list(w)
p = [0] + list(p)

T = int(input())
for i in range(T):
    W = int(input())
    P = {}
    print(knapsack2(n, W, w, p))
    P = list(P.items())
    P.sort(key=lambda x: (x[0][0], x[0][1]))
    for x, y in P:
        print(*x, y)
