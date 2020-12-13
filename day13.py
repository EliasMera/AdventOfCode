def part1(d):
    x = int(d[0][0])
    ids = [ int(x) for x in d[1] if x != 'x' ] 
    d = { id:(id - (x % id)) for id in ids if (x := int(d[0][0]))}
    mini = min(d, key=d.get)
    return (d[mini]*mini)

d = [ x.split(',') for x in open('day13.txt').read().splitlines() ]
print(part1(d))