import re
import sys

dirtyRules, tkt, near = open('day16.txt').read().strip().split("\n\n")
regexp = re.compile(r"([^:]+): (\d+)-(\d+) or (\d+)-(\d+)")
rules = []

for line in dirtyRules.splitlines():
    (field, lo1, hi1, lo2, hi2) = regexp.fullmatch(line).groups()
    rules.append((field, int(lo1), int(hi1), int(lo2), int(hi2)))

err = 0
n = len(rules)
cols = [set(range(n)) for _ in range(n)]

for ticket in near.splitlines()[1:]:
    valid = True
    tmp = []

    for num in map(int, ticket.split(",")):
        matchin = set(
            i
            for i, (_, lo1, hi1, lo2, hi2) in enumerate(rules)
            if lo1 <= num <= hi1 or lo2 <= num <= hi2
        )
        if len(matchin) == 0:
            err += num
            valid = False
        elif valid:
            tmp.append(matchin)

    if valid:
        for col, matchin in zip(cols, tmp):
            col &= matchin

print("Part 1")
print(err)

ans = 1
singles = set()
tkt = [int(num) for num in tkt.splitlines()[-1].split(",")]
while len(singles) != n:
    for i, col in enumerate(cols):
        if len(col) > 1:
            col -= singles
        elif len(col) == 1:
            singles |= col
            if rules[col.pop()][0].startswith("departure"):
                ans *= tkt[i]

print("Part 2")
print(ans)