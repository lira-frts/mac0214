import math
t = int(input())
for i in range(t):
    x, y, k = map(int, input().split())
    if(math.ceil(x / k) > math.ceil(y / k)): print(2 * math.ceil(x / k) - 1)
    else: print(2 * math.ceil(y / k))
