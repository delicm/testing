import math
from matplotlib import pyplot as plt

def b3(k):
    sspace = 10**k
    total = 0
    for dig in range(3*k):
        num = (sspace// (3**dig))%3
        percentage = (3**dig)*num
        total += percentage * dig
    return (total/sspace)/k

def b3_lower(k):
    sspace = 10**k
    total = 0
    deg = 0
    for dig in range(2*k, 3*k):
        if 3**dig < sspace and 3**(dig+1) > sspace:
            deg = dig
    
    num = sspace//(3**deg)
    total += num*(3**deg)*deg

    return (total/sspace)/k

n = 100

x = [i for i in range(1, n)]
y = [b3(i) for i in range(1, n)]
z = [b3_lower(i) for i in range(1, n)]

cup = [math.log(10, 3) for i in range(1, n)]
cdown = [math.log(10, 3)/9 for i in range(1, n)]

plt.plot(x, y)
plt.plot(x,z)
plt.plot(x, cup)
plt.plot(x, cdown)
plt.show()
        