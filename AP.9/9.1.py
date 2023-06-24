def schedule(deadline):
    n - len(deadline) - 1
    J = [1]
    for i in range(2, n + 1):
        K = insert(J, i, deadline)
        if (feasible(K, deadline)):
            J = K[:]
    return J

def feasible(K, deadline):
    for i in range(1, len(K) + 1):
        if (i > deadline[K[i - 1]]):
            return False
    return True

def insert(J, i, deadline):
    K = J[:]
    for j in range(len(J), 0, -1):
        if (deadline[i] >= deadline[K[j - 1]]):
            j += 1
            break
    K.insert(j - 1, i)
    return K

n = int(input())
deadline = list(map(int, input().split()))
deadline.insert(0, 0)
profit = list(map(int, input().split()))
profit.insert(0, 0)

J = schedule(deadline)
max_profit = 0
for j in J:
    max_profit += profit[j]
print(max_profit)
for j in range(len(J) - 1):
    print(profit[J[j]], end=' ')
print(profit[J[j + 1]])
