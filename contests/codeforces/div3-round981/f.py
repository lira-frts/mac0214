def solve():
    MOD = int(1e9+7)
    n, k = map(int, input().split())
    x0 = 0; x1 = 1; ind = 1
    while(x1 % k != 0):
        x0, x1 = x1, x0
        x1 += x0
        x1 %= k
        ind += 1
    print((ind * n) % MOD)
 
t = int(input())
while(t):
    solve()
    t -= 1
