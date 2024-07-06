n, m = input().split(' ')
n = int(n)
m = int(m)

f = [[0 for i in range(57)] for j in range(57)]
f[1][1] = 1

for i in range(1, n + 1):
    for j in range(1, i + 1):
        if i == 1 & j == 1:
            continue
        f[i][j] = f[i - 1][j - 1] + j * f[i - 1][j]

print(f[n][m])
