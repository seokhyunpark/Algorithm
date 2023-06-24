func_call = 0

def fib(n):
    global func_call
    func_call += 1
    if n == 0 or n == 1:
        return n
    else:
        return fib(n-1) + fib(n-2)

print(fib(int(input())))
print(func_call)
