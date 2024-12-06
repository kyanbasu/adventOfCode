import re


# optional, for visualization
from time import sleep
import os


def part1(mat):
    if mat[-1] == '':
        mat.pop()


    guard_pos = ()
    guard_direction = 0
    directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    guard_icons = ['^', '>', 'v', '<'] # also for visualization

    # get guard position
    for y in range(len(mat)):
        match = next( re.finditer(r'\^', mat[y]), None )
        if match is not None:
            guard_pos = (y, match.span()[0])
            lst = list(mat[y])
            lst[guard_pos[1]] = '.'
            mat[y] = ''.join(lst)

    tracking_map = [['.' for _ in range(len(mat[0]))] for _ in range(len(mat))]

    while True:

        pos = guard_pos
        dr = directions[guard_direction]

        if pos[0] + dr[0] < 0 or pos[0] + dr[0] >= len(mat) or pos[1] + dr[1] < 0 or pos[1] + dr[1] >= len(mat[0]):
            break

        if mat[pos[0] + dr[0]][pos[1] + dr[1]] == '#':
            guard_direction += 1
            if guard_direction > 3:
                guard_direction = 0
            dr = directions[guard_direction]

        tracking_map[pos[0]][pos[1]] = "#"

        guard_pos = (guard_pos[0] + dr[0], guard_pos[1] + dr[1])
        pos = guard_pos

        tracking_map[pos[0]][pos[1]] = "#"

        """os.system('cls')
        #prints mat state
        for y in range(len(mat)):
            for x in range(len(mat[y])):
                if (y, x) != guard_pos:
                    print(mat[y][x], end='')
                else:
                    print(guard_icons[guard_direction], end='')

            print('')

        sleep(.01)"""

    places = 0

    for y in range(len(tracking_map)):
        for x in range(len(tracking_map[y])):
            if tracking_map[y][x] == '#':
                places += 1

    return places

def part2(mat):
    if mat[-1] == '':
        mat.pop()


    guard_pos = ()
    guard_direction = 0
    directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    guard_icons = ['^', '>', 'v', '<'] # also for visualization

    # get guard position
    for y in range(len(mat)):
        match = next( re.finditer(r'\^', mat[y]), None )
        if match is not None:
            guard_pos = (y, match.span()[0])
            lst = list(mat[y])
            lst[guard_pos[1]] = '.'
            mat[y] = ''.join(lst)

    last_redirects = []

    ans = 0

    while True:

        pos = guard_pos
        dr = directions[guard_direction]

        if pos[0] + dr[0] < 0 or pos[0] + dr[0] >= len(mat) or pos[1] + dr[1] < 0 or pos[1] + dr[1] >= len(mat[0]):
            break

        if mat[pos[0] + dr[0]][pos[1] + dr[1]] == '#':
            # redirects for part 2
            if len(last_redirects) > 2:
                match guard_direction:
                    case 0: #going up
                        if last_redirects[0][0] > pos[0]:
                            ans += 1
                    case 1: #going right
                        if last_redirects[0][1] < pos[1]:
                            ans += 1
                    case 2:  # going up
                        if last_redirects[0][0] < pos[0]:
                            ans += 1
                    case 3: #going left
                        if last_redirects[0][1] > pos[1]:
                            ans += 1
                    case _:
                        pass
                last_redirects.pop(0)
            last_redirects.append(pos)

            # rotate guard
            guard_direction += 1
            if guard_direction > 3:
                guard_direction = 0
            dr = directions[guard_direction]


        guard_pos = (guard_pos[0] + dr[0], guard_pos[1] + dr[1])

        os.system('cls')
        #prints mat state
        for y in range(len(mat)):
            for x in range(len(mat[y])):
                if (y, x) != guard_pos:
                    print(mat[y][x], end='')
                else:
                    print(guard_icons[guard_direction], end='')

            print('\t', end='')

            for x in range(len(mat[y])):
                if (y, x) in last_redirects:
                    print('#', end='')
                else:
                    print('.', end='')

            print('')

        print(ans)

        sleep(.5)

    return ans

if __name__ == "__main__":
    e = open("example.txt").read().split('\n')
    #_in = open("input.txt").read().split('\n')

    """e1 = part1(e)
    assert e1 == 41

    p1 = part1(_in)
    print("distinct positions on map: " + str(p1))"""

    e2 = part2(e)
    assert e2 == 6