import random
from matplotlib import pyplot as plt

trials = 10000
n = 200

results = [0.5 for i in range(trials)]

for i in range(trials):
    g, r = 1, 1
    for _ in range(n):
        next = random.randint(1,r+g)
        if next <= r: r += 1
        else: g += 1
    results[i] = r/(r+g)
    
plt.hist(results, bins = 80)
plt.show()
    