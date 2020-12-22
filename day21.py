r = open('day21.txt').read()
r = r.replace('(','').replace(')','')
input = [x.split(' contains ') for x in r.splitlines()]
for x in input:
    x[0] = x[0].split(' ')
    x[1] = x[1].split(', ')

fv = {}
allM = {}
for ff in input:
    aller = ff[1]
    ings = set(ff[0])
    for ing in ings:
        if ing in fv:
            fv[ing] = fv[ing] + 1
        else:
            fv[ing] = 1
    for aa in aller:
        if aa in allM:
            allM[aa] = allM[aa] & ings
        else:
            allM[aa] = ings

ss = set()
for aa in allM:
    ss = ss | allM[aa]

ans = 0
for fr in fv:
    if fr not in ss:
        ans = ans + fv[fr]

print(ans)

found = 0
while found < len(allM):
    for aa in allM:
        if len(allM[aa]) == 1:
            for others in allM:
                if others != aa:
                    allM[others] = allM[others] - allM[aa]
            found = found + 1

ans2 = ''
for x in sorted(allM.items()):
    ans2 = ans2 + x[1].pop() + ','

print(ans2[:-1])