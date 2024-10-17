mod = int(1e9+7)
t = int(input())
for _ in range(t):
    l, r, k = map(int, input().split())
    dmax = (9//k+1)
    print((pow(dmax, r, mod) - pow(dmax, l, mod)) % mod)
