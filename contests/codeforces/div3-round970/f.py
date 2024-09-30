mod = 1000000007
t = int(input())
for i in range(t):
    n = int(input())
    soma = 0
    v = list(map(int, input().split()))
    for x in v:
        soma += x
    soma = soma ** 2
    for x in v:
        soma -= x ** 2
    soma //= 2
    print(soma * pow(n * (n - 1) // 2, -1, mod) % mod)
