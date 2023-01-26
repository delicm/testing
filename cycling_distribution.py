import random

n = 20
iter = 100000
distribution = [0 for _ in range(n)]

for _ in range(iter):
    vis = [False]*n
    vis[0] = True
    cnt = 1
    curr = 0
    while cnt < n:
        curr += random.randint(-1,1)
        curr %= n
        if vis[curr]: continue
        cnt += 1
        vis[curr] = True
        if cnt == n: distribution[curr] += 1
        
for i in range(1,n): distribution[i] = distribution[i]/iter-1/(n-1)
print(distribution)
