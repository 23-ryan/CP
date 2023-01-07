total = 0

n = 1337
m = 424242424242

with open("hello.txt", 'w') as f:
    for i in range(0, n):
        total = ((m*total)%998244353 + m)%998244353
        f.write(f"{total}\n")