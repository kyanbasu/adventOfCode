import time

def parse(_in):
    _in = _in.split('\n')
    if _in[-1] == '':
        _in.pop()

    start_positions = []
    mat = []
    for r in range(len(_in)):
        mat.append([])
        for c in range(len(_in[r])):
            mat[r].append(int(_in[r][c]))
            if int(_in[r][c]) == 0:
                start_positions.append((r, c))

    return mat, start_positions

def part1(_in):
    ans = 0

    mat, start_positions = _in

    print(mat)
    print(start_positions)

    return ans

def part2(_in):
    ans = 0

    return ans

if __name__ == "__main__":
    _in = parse( open("input.txt").read() )
    ex = parse( open("example.txt").read() )

    e1 = part1(ex)
    assert e1 == 36, f"should be 36, but is {e1}"

    start = time.time()
    p1 = part1(_in)
    print("part 1: ", p1)
    print("> exec time: ", int((time.time() - start)*100000)/100000.0, 's')

    # e2 = part2(ex)
    # assert e2 == 1, f"should be 1, but is {e2}"
    #
    # start = time.time()
    # p2 = part2(_in)
    # print("part 2: ", p2)
    # print("> exec time: ", int((time.time() - start)*100000)/100000.0, 's')
