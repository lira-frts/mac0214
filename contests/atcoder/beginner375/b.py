n = int(input())
custo = 0
x1, y1 = 0, 0
for _ in range(n):
    x2, y2 = map(int, input().split())
    custo += ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5
    x1, y1 = x2, y2
x2, y2 = 0, 0
custo += ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5
print(custo)
