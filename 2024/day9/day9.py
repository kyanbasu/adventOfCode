import time
from itertools import repeat


def part1(_in):

    ans = 0

    disk_map = []

    for index, c in enumerate(_in):
        if index % 2 == 0: # length of file
            disk_map += repeat(str(index//2), int(c))
        else: # length of free space
            disk_map += repeat('.', int(c))

    i = 0
    while i < len(disk_map):
        if disk_map[i] == '.':
            pop = disk_map.pop()
            while pop == '.':
                pop = disk_map.pop()
            if i >= len(disk_map):
                break
            disk_map[i] = pop

        ans += i * int(disk_map[i])

        i += 1


    return ans

def part2(_in):

    ans = 0

    data_blocks = [] # array of tuples (str, int) = (index, count), on positions 2n
    free_blocks = [] # array of free space count as integers, on positions 2n+1

    for index, c in enumerate(_in):
        if index % 2 == 0: # length of file
            data_blocks.append((str(index//2), int(c)))
        else: # length of free space
            free_blocks.append(int(c))

    print(data_blocks)
    print(free_blocks)

    disk_map = [data_blocks[0]]

    i = 1
    while True:
        if i > len(data_blocks):
            break

        space_needed = int(data_blocks[-i][0]) * data_blocks[-i][1]
        index_of_free_space = None

        for x in free_blocks:
            if x >= space_needed:
                index_of_free_space = x
                break



        i+=1

    print(disk_map)


    return ans

if __name__ == "__main__":
    _in = open("input.txt").read().split('\n')[0]
    ex = open("example.txt").read().split('\n')[0]

    # e1 = part1(ex)
    # assert e1 == 1928, f"should be 1928, but is {e1}"
    #
    # start = time.time()
    # p1 = part1(_in)
    # print("part 1: ", p1)
    # print("> exec time: ", int((time.time() - start)*100000)/100000.0, 's')

    e2 = part2(ex)
    assert e2 == 2858, f"should be 2858, but is {e2}"

    start = time.time()
    p2 = part2(_in)
    print("part 2: ", p2)
    print("> exec time: ", int((time.time() - start)*100000)/100000.0, 's')
