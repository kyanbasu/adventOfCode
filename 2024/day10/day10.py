import time

def part1(_in):
    ans = 0

    return ans

def part2(_in):
    ans = 0

    return ans

if __name__ == "__main__":
    _in = open("input.txt").read().split('\n')[0]
    ex = open("example.txt").read().split('\n')[0]

    e1 = part1(ex)
    assert e1 == 1, f"should be 1, but is {e1}"

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
