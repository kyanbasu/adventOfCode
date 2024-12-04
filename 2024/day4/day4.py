import re

def part1(lines):
    ans = 0
    strf = "XMAS" #string to find

    #works because len of rows == cols
    transposed_lines = []
    for i in range(len(lines)):
        transposed_lines.append(''.join([lines[j][i] for j in range(len(lines))]))

    diagonal_lines = []
    # diagonal to top right
    # first half
    for i in range(len(lines) - len(strf) + 1):
        i += len(strf)-1
        diagonal_lines.append(''.join([lines[i-j][j] for j in range(i+1)]))
    # second half
    for i in range(len(lines) - len(strf)):
        i += 1
        diagonal_lines.append(''.join([lines[len(lines)-j-1][i+j] for j in range(len(lines)-i)]))

    # diagonal to bottom right
    # first half
    for i in range(len(lines) - len(strf) + 1):
        i += len(strf) - 1
        diagonal_lines.append(''.join([lines[len(lines)-(i-j)-1][j] for j in range(i+1)]))
    # second half
    for i in range(len(lines) - len(strf)):
        i += 1
        diagonal_lines.append(''.join([lines[j][i+j] for j in range(len(lines)-i)]))

    all_lines = lines + transposed_lines + diagonal_lines

    for line in all_lines:
        ans += len(re.findall(strf, line))
        ans += len(re.findall(strf, line[::-1]))


    return ans

def part2(lines):
    matches = [
        [
            ['M', '', 'S'],
            ['', 'A', ''],
            ['M', '', 'S']
        ],
        [
            ['M', '', 'M'],
            ['', 'A', ''],
            ['S', '', 'S']
        ],
        [
            ['S', '', 'M'],
            ['', 'A', ''],
            ['S', '', 'M']
        ],
        [
            ['S', '', 'S'],
            ['', 'A', ''],
            ['M', '', 'M']
        ],
    ]

    ans = 0

    for row in range(len(lines)-2):
        for col in range(len(lines[row])-2):
            check = [
                [lines[row][col], '', lines[row+2][col]],
                ['', lines[row+1][col+1], ''],
                [lines[row][col+2], '', lines[row+2][col+2]]
            ]
            if check in matches:
                ans += 1

    return ans


import time
if __name__ == "__main__":
    example = open("example.txt").read().split("\n")
    ex_p1 = part1(example)
    assert ex_p1 == 18, "Example part 1 failed, should be equal 18, but is " + str(ex_p1)

    start = time.time()
    p1 = part1(open("input.txt").read().split("\n"))
    end = time.time()
    print("part 1 time: ", end - start)
    print("part 1 answer: ", p1)

    print("===========")

    ex_p2 = part2(example)
    assert ex_p2 == 9, "Example part 1 failed, should be equal 9, but is " + str(ex_p2)

    start = time.time()
    p2 = part2(open("input.txt").read().split("\n"))
    end = time.time()
    print("part 2 time: ", end - start)
    print("part 2 answer: ", p2)