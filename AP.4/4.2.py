def karatsuba(u, v, threshold):
    n = max(len(str(u)), len(str(v)))
    global cnt
    cnt += 1
    if u == 0 or v == 0:
        return 0
    elif n <= threshold:
        return u * v
    else:
        m = n // 2
        x, y = u // (10 ** m), u % (10 ** m)
        w, z = v // (10 ** m), v % (10 ** m)
        p1, p2 = karatsuba(x, w, threshold), karatsuba(x, z, threshold)
        p3, p4 = karatsuba(w, y, threshold), karatsuba(y, z, threshold)
        return p1 * (10 ** (2 * m)) + (p2 + p3) * (10 ** m) + p4

cnt = 0
threshold = int(input())
u = int(input())
v = int(input())
uv = karatsuba(u, v, threshold)
print(cnt)
print(uv)
