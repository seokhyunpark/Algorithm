from queue import PriorityQueue

class SSTNode:
    def __init__(self, level, profit, weight):
        self.level = level
        self.profit = profit
        self.weight = weight
        self.bound = 0
    
    def print(self):
        print(self.level, self.weight, self.profit, int(self.bound))

def knapsack4(p, w, W):
    PQ = PriorityQueue()
    v = SSTNode(0, 0, 0)
    maxprofit = 0
    v.bound = bound(v, p, w)
    v.print()
    PQ.put((-v.bound, v))
    while (not PQ.empty()):
        v = PQ.get()[1]
        if (v.bound > maxprofit):
            level = v.level + 1
            weight = v.weight + w[level]
            profit = v.profit + p[level]
            u = SSTNode(level, profit, weight)
            if (u.weight <= W and u.profit > maxprofit):
                maxprofit = u.profit
            u.bound = bound(u, p, w)
            u.print()
            if (u.bound > maxprofit):
                PQ.put((-u.bound, u))
            u = SSTNode(level, v.profit, v.weight)
            u.bound = bound(u, p, w)
            u.print()
            if (u.bound > maxprofit):
                PQ.put((-u.bound, u))
    return maxprofit

def bound(u, p, w):
    n = len(p) - 1
    if (u.weight >= W):
        return 0
    else:
        result = u.profit
        j = u.level + 1
        totweight = u.weight
        while (j <= n and totweight + w[j] <= W):
            totweight += w[j]
            result += p[j]
            j += 1
        k = j
        if (k <= n):
            result += (W - totweight) * p[k] / w[k]
        return result

n, W = map(int, input().split())
w = list(map(int, input().split()))
p = list(map(int, input().split()))

sorted_items = list(sorted(zip(w, p), key=lambda x: x[1] / x[0], reverse=True))
w, p = zip(*sorted_items)
w = [0] + list(w)
p = [0] + list(p)

print(knapsack4(p, w, W))
