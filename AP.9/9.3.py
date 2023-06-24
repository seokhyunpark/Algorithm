from heapq import heappush, heappop

class Item:
    def __init__(self, weight, profit):
        self.weight = weight
        self.profit = profit
        self.profit_per_weight = profit / weight
        
def knapsack(n, W, w, p):
    heap = []
    for i in range(n):
        item = Item(w[i], p[i])
        heappush(heap, (-item.profit_per_weight, item))
    maxprofit = totweight = 0
    stolen = []
    while len(heap) > 0:
        item = heappop(heap)[1]
        if totweight + item.weight <= W:
            totweight += item.weight
            maxprofit += item.profit
            stolen.append([item.weight, item.profit])
        else:
            profit = (W - totweight) * item.profit_per_weight
            maxprofit += profit
            stolen.append([W - totweight, profit])
            break
    return maxprofit, stolen
        
n = int(input())
w = list(map(int, input().split()))
p = list(map(int, input().split()))
t = int(input())
for _ in range(t):
    W = int(input())
    maxprofit, stolen = knapsack(n, W, w, p)
    print(int(maxprofit))
    for item in stolen:
        print(item[0], item[1])
