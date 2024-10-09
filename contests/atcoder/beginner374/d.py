import itertools

n, s, t = map(int, input().split())
pontos = []
for i in range(n):
    a, b, c, d = map(int, input().split())
    pontos.append([[a, b], [c, d]])

# gera a ordem que vai imprimir
perms = list(itertools.permutations(pontos))

minimo = int(1e12)

for perm in perms:
    for i in range(1 << n):
        total = 0
        atual = [0, 0]
        for j in range(n):
            if(i >> j & 1):
                total += (((atual[0] - perm[j][0][0]) ** 2 + (atual[1] - perm[j][0][1]) ** 2) ** 0.5) / s
                total += (((perm[j][0][0] - perm[j][1][0]) ** 2 + (perm[j][0][1] - perm[j][1][1]) ** 2) ** 0.5) / t
                atual = [perm[j][1][0], perm[j][1][1]]
            else:
                total += (((atual[0] - perm[j][1][0]) ** 2 + (atual[1] - perm[j][1][1]) ** 2) ** 0.5) / s
                total += (((perm[j][1][0] - perm[j][0][0]) ** 2 + (perm[j][1][1] - perm[j][0][1]) ** 2) ** 0.5) / t
                atual = [perm[j][0][0], perm[j][0][1]]
        minimo = min(minimo, total) 
print(minimo)
