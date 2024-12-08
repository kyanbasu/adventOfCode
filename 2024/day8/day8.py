import itertools
import time

def part1(lines):

    rows = len(lines)
    cols = len(lines[0])

    antennas = {}
    antinodes = set()

    # calculates and creates antinodes
    def calc_antinodes(an):
        # an is tuple of two tuples
        # an = ((y1,x1), (y2,x2))

        c = tuple(map(lambda i, j: i - j + i, an[0], an[1]))
        d = tuple(map(lambda i, j: j + j - i, an[0], an[1]))

        add_antinode(c)
        add_antinode(d)

    def add_antinode(ant):
        if 0 <= ant[0] < rows and 0 <= ant[1] < cols:
            antinodes.add(ant)


    for l in range(len(lines)):
        for c in range(len(lines[l])):
            if lines[l][c] != '.':
                if lines[l][c] not in antennas:
                    antennas[lines[l][c]] = [(l, c)]
                else:
                    antennas[lines[l][c]].append((l, c))

    for a, loc in antennas.items():
        combs = list(itertools.combinations(loc, r=2))
        for comb in combs:
            calc_antinodes(comb)

    ### for display
    # prt = ""
    # for y in range(len(lines)):
    #     for x in range(len(lines[y])):
    #         if lines[y][x] != '.':
    #             prt += lines[y][x]
    #         elif (y,x) in antinodes:
    #             prt += '#'
    #         else:
    #             prt += '.'
    #     prt += '\n'
    #
    # print(prt)


    return len(antinodes)


def part2(lines):

    rows = len(lines)
    cols = len(lines[0])

    antennas = {}
    antinodes = set()

    # calculates and creates antinodes
    def calc_antinodes(an):
        # an is tuple of two tuples
        # an = ((y1,x1), (y2,x2))

        dist = tuple(map(lambda i, j: j - i, an[0], an[1]))

        ant = an[0]
        while add_antinode(ant):
            ant = (ant[0] - dist[0], ant[1] - dist[1])

        ant = an[0]
        while add_antinode(ant):
            ant = (ant[0] + dist[0], ant[1] + dist[1])

    # returns boolean if successfully added antinode
    def add_antinode(ant):
        if 0 <= ant[0] < rows and 0 <= ant[1] < cols:
            antinodes.add(ant)
            return True
        return False


    for l in range(len(lines)):
        for c in range(len(lines[l])):
            if lines[l][c] != '.':
                if lines[l][c] not in antennas:
                    antennas[lines[l][c]] = [(l, c)]
                else:
                    antennas[lines[l][c]].append((l, c))

    for a, loc in antennas.items():
        combs = list(itertools.combinations(loc, r=2))
        for comb in combs:
            calc_antinodes(comb)

    ### for display
    # prt = ""
    # for y in range(len(lines)):
    #     for x in range(len(lines[y])):
    #         if lines[y][x] != '.':
    #             prt += lines[y][x]
    #         elif (y,x) in antinodes:
    #             prt += '#'
    #         else:
    #             prt += '.'
    #     prt += '\n'
    #
    # print(prt)


    return len(antinodes)


if __name__ == "__main__":
    _in = open("input.txt").read().split('\n')
    if _in[-1] == '':
        _in.pop()
    ex = open("example.txt").read().split('\n')
    if ex[-1] == '':
        ex.pop()

    e1 = part1(ex)
    assert e1 == 14, f"should be 14, but is {e1}"

    start = time.time()
    p1 = part1(_in)
    print("part 1: ", p1)
    print("> exec time: ", int((time.time() - start)*100000)/100000.0, 's')

    e2 = part2(ex)
    assert e2 == 34, f"should be 34, but is {e2}"

    start = time.time()
    p2 = part2(_in)
    print("part 2: ", p2)
    print("> exec time: ", int((time.time() - start)*100000)/100000.0, 's')
