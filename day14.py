import re
import itertools

class Ferry:
    def __init__(self):
        self.memory = dict()
        self.bitmask = dict()

    def run(self, program):
        for line in program:
            if line[0] == 'mask':
                self.update_bitmask(line[1])
            else:
                address = int(re.findall(r'\d+', line[0])[0])
                val = int(line[1])
                self.save_to_memory(address, val)

    def save_to_memory(self, address, val):
        self.memory[address] = int(self.apply_bitmask(format(val, '036b')), 2)

    def update_bitmask(self, bitString):
        self.bitmask = dict()
        for i, bit in enumerate(bitString):
            if bit != 'X':
                self.bitmask[i] = bit

    def apply_bitmask(self, numBin, bitmask=None):
        if bitmask is None:
            bitmask = self.bitmask
        result = ''
        for i, bit in enumerate(numBin):
            if i in bitmask:
                result += bitmask[i]
            else:
                result += bit
        return result


class FerryV2(Ferry):
    def __init__(self):
        super().__init__()
        self.bitmasks = []

    def save_to_memory(self, address, val):
        for bitmask in self.bitmasks:
            tmp = int(self.apply_bitmask(format(address, '036b'), bitmask), 2)
            self.memory[tmp] = val

    def update_bitmask(self, bitString):
        self.bitmasks = []
        bitmask = dict()
        floatingBits = []
        for i, bit in enumerate(bitString):
            if bit == '1':
                bitmask[i] = bit
            elif bit == 'X':
                floatingBits.append(i)
        floatingVals = itertools.product([0, 1], repeat=len(floatingBits))
        for tup in floatingVals:
            bitmaskFloats = bitmask.copy()
            for i, k in enumerate(floatingBits):
                bitmaskFloats[k] = str(tup[i])
            self.bitmasks.append(bitmaskFloats)


def part1(data):
    docker = Ferry()
    docker.run(data)
    return sum(docker.memory.values())


def part2(data):
    docker = FerryV2()
    docker.run(data)
    return sum(docker.memory.values())


with open('day14.txt') as f:
    data = [line.split(' = ') for line in f.read().splitlines()]

print(part1(data))
print(part2(data))