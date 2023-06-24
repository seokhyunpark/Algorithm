def promising(i, profit, weight):
    global bound
    if weight > W:
        return False
    else:
        j = i + 1
        bound = profit
        totweight = weight
        while j <= n and totweight + w[j] <= W:
            totweight += w[j]
            bound += p[j]
            j += 1
        k = j
        if k <= n:
            bound += int((W - totweight) * p[k] / w[k])
        return bound > maxprofit


def knapsack3(i, profit, weight):
    global maxprofit, bestset, numbest, bound
    if weight <= W and profit > maxprofit:
        maxprofit = profit
        numbest = i
        bestset = include[:]
    flag = promising(i, profit, weight)
    print(i, weight, profit, bound, maxprofit)
    if flag:
        include[i + 1] = True
        knapsack3(i + 1, profit + p[i + 1], weight + w[i + 1])
        include[i + 1] = False
        knapsack3(i + 1, profit, weight)

n, W = map(int, input().split())
w = list(map(int, input().split()))
p = list(map(int, input().split()))

sorted_items = list(sorted(zip(w, p), key=lambda x: x[1] / x[0], reverse=True))
w, p = zip(*sorted_items)
w = [0] + list(w)
p = [0] + list(p)

maxprofit = 0
numbest = 0
bound = 0
bestset = [False] * (n + 1)
include = [False] * (n + 1)

knapsack3(0, 0, 0)
print(maxprofit)
for i in range(1, n + 1):
    if bestset[i]:
        print(w[i], p[i])
