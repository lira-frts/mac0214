pd = [0] * 501; pd[0] = 1

def fun(qtd, lados):
    global pd
    for j in range(qtd):
        pd2 = [0] * 501
        for k in range(1, lados+1):
            for l in range(0, 501-k):
                pd2[l+k] += pd[l];
        pd = pd2[:]

t, c, o, d, i = map(int, input().split())
fun(t, 4)
fun(c, 6)
fun(o, 8)
fun(d, 12)
fun(i, 20)

freq = []
for j in range(1, 501):
    if(pd[j] != 0): freq.append((pd[j], j))
freq.sort(reverse = 1)
for a, b in freq:
    print(b, end = ' ')
print()
