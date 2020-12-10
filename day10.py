with open('day10.txt') as f:
    arr = list(sorted(int(line) for line in f))

dlt = [0]*4
V = 0
for it in arr:
    dlt[it - V] += 1
    V = it

print(dlt[1] * dlt[3])

dp = [0] * (arr[-1] + 1)
dp[0] = 1
for it in arr:
    dp[it] = dp[it - 3] + dp[it - 2] + dp[it - 1]

print(dp[-1])