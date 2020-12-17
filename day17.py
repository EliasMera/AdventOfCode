import sys
from collections import defaultdict
from itertools import product

def solve(inp, dim):
    z = [0] * (dim - 2)
    coord = {*product((-1, 0, 1), repeat=dim)} - {(0, 0, *z)}
    cubes = {
        (row, col, *z)
        for row, line in enumerate(inp)
        for col, char in enumerate(line)
        if char == "#"
    }

    for _ in range(6):
        neighbors = defaultdict(int)
        for cube in cubes:
            for coordinate in coord:
                neighbor = tuple(sum(x) for x in zip(cube, coordinate))
                neighbors[neighbor] += 1

        cubes = {
            neighbor
            for neighbor, count in neighbors.items()
            if count == 3 or (count == 2 and neighbor in cubes)
        }

    return len(cubes)


inp = open("day17.txt").read().splitlines()
print(solve(inp, 3))
print(solve(inp, 4))