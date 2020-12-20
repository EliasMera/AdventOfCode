data = []
with open('day18.txt') as f:
    data = [line.strip() for line in f.readlines()]

def solve(ex):
    while len(ex) > 1:
        if ex[1] == ')':
            return ex[0:1] + ex[2:]
        a,op,b = ex[0:3]
        if a == '(':
            ex = solve(ex[1:])
        elif b == '(':
            ex = [a,op] + solve(ex[3:])
        elif op == '+':
            ex = [a+b] + ex[3:]
        elif op == '*':
            ex = [a*b] + ex[3:]
    return ex

def solve2(ex):
    while '(' in ex:
        cc = 1
        start = ex.index('(')
        end = start
        while cc:
            end += 1
            if ex[end] == ')':
                cc -=1
            elif ex[end] == '(':
                cc += 1
        v = solve2(ex[start+1:end])
        ex = ex[:start] + v + ex[end+1:]

    while '+' in ex:
        i = ex.index('+')
        v = ex[i-1] + ex[i+1]
        ex = ex[:i-1] + [v] + ex[i+2:]

    while '*' in ex:
        i = ex.index('*')
        v = ex[i-1] * ex[i+1]
        ex = ex[:i-1] + [v] + ex[i+2:]

    return ex

def format(s):
    return [int(x) if x.isnumeric() else x for x in list(s.strip().replace(' ', ''))]

def part1(d):
    total = 0
    for line in d:
        expr = format(line)
        answer = solve(expr)[0]
        total += answer
    print(total)

def part2(d):
    total = 0 
    for line in d:
        expr = format(line)
        answer = solve2(expr)[0]
        total += answer
    print(total)

part1(data)
part2(data)