import itertools
from multiprocessing import Pool


def part1(_in):
    ans = 0
    operators = ['+', '*']

    for l in _in:
        l = l.split(': ')
        check = int(l[0])
        nums = list(map(int, l[1].split(' ')))

        combs = itertools.product(operators, repeat=len(nums)-1)

        for c in combs:
            calc = nums[0]
            for i, op in enumerate(c):
                calc = operation(calc, nums[i + 1], op)
            if check == calc:
                ans += calc
                break

    return ans

def part2(_in):
    with Pool() as pool:
        results = pool.map(calc_line2, _in)

    return sum(results)

def calc_line2(l):
    operators = ['+', '*', '||']
    l = l.split(': ')
    check = int(l[0])
    nums = list(map(int, l[1].split(' ')))

    combs = itertools.product(operators, repeat=len(nums) - 1)

    for c in combs:
        calc = nums[0]
        for i, op in enumerate(c):
            calc = operation(calc, nums[i + 1], op)
            if calc > check:  # speeds up by about 5%
                break
        if check == calc:
            return calc

    return 0

def operation(a, b, oper):
    match oper:
        case '*':
            return a*b
        case '+':
            return a+b
        case '||':
            return int(f"{a}{b}")
    return 0

import time

if __name__ == "__main__":
    _in = open("input.txt").read().split('\n')
    if _in[-1] == '':
        _in.pop()
    ex = open("example.txt").read().split('\n')
    if ex[-1] == '':
        ex.pop()

    e1 = part1(ex)
    assert e1 == 3749, "should be 3749, but is " + str(e1)

    start = time.time()
    p1 = part1(_in)
    print("part 1: ", p1)
    print("> exec time: ", int((time.time() - start)*1000)/1000.0, 's')

    e2 = part2(ex)
    assert e2 == 11387

    start = time.time()
    p2 = part2(_in)
    print("part 2: ", p2)
    print("> exec time: ", int((time.time() - start)*1000)/1000.0, 's')
