import math

def readF(p="day20.txt"):
    grid = {}
    with open(p, "r") as infile:
        for rt in infile.read().split("\n\n"):
            name, *lines = rt.splitlines()
            num = int(name[5:-1])
            lines = [list(l) for l in lines]
            grid[num] = lines
        return grid

def getbdrs(t):
    return (t[0], [l[-1] for l in t], t[-1], [l[0] for l in t])

def getFlips(t):
    return [t, t[::-1], [l[::-1] for l in t], [l[::-1] for l in t][::-1]]

def getRotations(t):
    rots = [t]
    ls = t
    for _ in range(3):
        t = [l[:] for l in t]
        for x in range(len(t)):
            for y in range(len(t[x])):
                t[x][y] = ls[len(t[x])-y-1][x]
        ls = t
        rots.append(t)
    return rots

def getTransforms(t):
    poss = []
    for flip in getFlips(t):
        poss.extend(getRotations(flip))
    ans = []
    for pos in poss:
        if pos not in ans:
            ans.append(pos)
    return ans

def rect(td, tmp, dims, x=0, y=0, seen=set()):
    if y == dims:
        return td
    newX = x + 1
    newY = y
    if newX == dims:
        newX = 0
        newY += 1
    for id, grid in tmp.items():
        if id in seen:
            continue
        seen.add(id)
        for nID, bdr in grid.items():
            top, _, _, left = bdr

            if x > 0:
                neID, neT = td[x-1][y]
                _, neR, _, _ = tmp[neID][neT]
                if neR != left:
                    continue
            if y > 0:
                neID, neT = td[x][y-1]
                _, _, neB, _ = tmp[neID][neT]
                if neB != top:
                    continue
            td[x][y] = (id, nID)
            ans = rect(td, tmp, dims,
                          x=newX, y=newY, seen=seen)
            if ans is not None:
                return ans
        seen.remove(id)
    td[x][y] = None
    return None

def solve(grid):
    tmp = {id: getTransforms(t) for id, t in grid.items()}
    tO = {}
    for id, grid in tmp.items():
        for idx, t in enumerate(grid):
            if id not in tO.keys():
                tO[id] = {}
            tO[id][idx] = getbdrs(t)
    dims = math.isqrt(len(tmp))
    td = [[None] * dims for _ in range(dims)]
    return tmp, rect(td, tO, dims)

def part1(td):
    return td[0][0][0] * td[0][-1][0] * td[-1][0][0] * td[-1][-1][0]

def removeGuides(tmp, td):
    out = []
    for row in td:
        grid = []
        for num, nID in row:
            t = tmp[num][nID]
            grid.append([l[1:-1] for l in t[1:-1]])
        for y in range(len(grid[0][0])):
            newR = []
            for id in range(len(grid)):
                newR.extend(grid[id][x][y] for x in range(len(grid[id])))
            out.append(newR)
    return out

MONSTER = '''                  # 
#    ##    ##    ###
 #  #  #  #  #  #   '''

def parseMonster():
    mnstL = []
    maxX, maxY = 0, 0
    for y2, line in enumerate(MONSTER.splitlines()):
        for x2, char in enumerate(line):
            if char == "#":
                mnstL.append((x2, y2))
                maxX = max(x2, maxX)
                maxY = max(y2, maxY)
    return mnstL, maxX, maxY

def checkMonsters(grid):
    mnstL, maxX, maxY = parseMonster()
    monS = set()
    for y in range(len(grid)):
        if y + maxY >= len(grid):
            break
        for x in range(len(grid[y])):
            if x + maxX >= len(grid[y]):
                break
            isMonster = True
            for xOff, yOff in mnstL:
                if grid[y+yOff][x+xOff] != "#":
                    isMonster = False
                    break
            if isMonster:
                for dx, dy in mnstL:
                    monS.add((x+dx, y+dy))
    if len(monS) == 0:
        return None
    allF = set()
    for y, row in enumerate(grid):
        for x, char in enumerate(row):
            if char == '#':
                allF.add((x, y))
    return len(allF - monS)

def part2(tmp, td):
    grid = removeGuides(tmp, td)
    gridOpts = getTransforms(grid)
    for opt in gridOpts:
        ans = checkMonsters(opt)
        if ans is not None:
            return ans

grid = readF()
tmp, td = solve(grid)
print(part1(td))
print(part2(tmp, td))