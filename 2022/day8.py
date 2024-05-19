def main():
    f = open("day8-input.txt").read().splitlines()
    
    indexes_checked = []
    total = 0
    i = 0
    for line in f:
        for char in range(len(str(line))):
            index = i*99 + char
            #print(str(index) + "  " + line[char])
            iter2_index = 0
            cancel = False
            for c in line:
                if (iter2_index == char or iter2_index == 98) and not cancel:
                    indexes_checked.append(index)
                    break
                else:
                    cancel = False

                if line[iter2_index] >= line[char]:
                    cancel = True

                iter2_index += 1
        i += 1

    print("indexes checked step 1: ", len(indexes_checked), "\n", indexes_checked)

    f = rotate90(f)

    i = 0
    for line in f:
        for char in range(len(str(line))):
            index = char * 99 + i
            # print(str(index) + "  " + line[char])
            iter2_index = 0
            cancel = False
            for c in line:
                if (iter2_index == char or iter2_index == 98) and not cancel and index not in indexes_checked:
                    indexes_checked.append(index)
                    break
                else:
                    cancel = False

                if line[iter2_index] >= line[char]:
                    cancel = True

                iter2_index += 1
        i += 1

    print("indexes checked step 2 (final): ", len(indexes_checked), "\n", indexes_checked)

def rotate90(arr):
    output = []
    temp = ''
    for i in range(len(arr[0])):
        for lines in range(len(arr)):
            temp += arr[lines][i]
        output.append(temp)
        temp = ''
    return output

#main()

# rly idk
#### https://www.reddit.com/r/adventofcode/comments/zfpnka/comment/izex6p5/?utm_source=share&utm_medium=web2x&context=3

data = open("day8-input.txt").read().strip()
map = [[int(c) for c in r] for r in data.split("\n")]
p1, p2 = set(), set()
for r in range(1, len(map) - 1):
    for c in range(1, len(map[0]) - 1):
        seen = 1
        for r_move, c_move in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            r1, c1 = r, c
            neighbors = []
            while c1 + c_move >= 0 and c1 + c_move < len(map[0]) and r1 + r_move >= 0 and r1 + r_move < len(map):
                r1 += r_move
                c1 += c_move
                neighbors.append(map[r1][c1])
            if map[r][c] > max(neighbors):
                p1.add((r, c))
                seen *= len(neighbors)
            else:
                seen *= [i+1 for i, n in enumerate(neighbors) if n >= map[r][c]][0]
            p2.add(seen)
print(f"Part 1: {len(p1) + (4 * (len(map) - 1))}")
print(f"Part 2: {max(p2)}")
