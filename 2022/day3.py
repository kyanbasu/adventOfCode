f = open("input-day3.txt").read().split("\n")

priorities = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
              'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']



def part1():
    sum_of_priorities = 0
    for line in f:
        a = line[0 : int(len(line)/2)]
        b = line[int(len(line)/2) : len(line)]
        a_ls = [x for x in a]
        total = []
        for b_char in b:
            if b_char in a_ls:
                total.append(b_char)

        sum_of_priorities += priorities.index(total[0])+1
    print("sum:", sum_of_priorities)


def part2():
    sum_of_priorities = 0
    recurrence = 0
    first_elf = second_elf = []
    for line in f:
        if recurrence == 0:
            first_elf = [x for x in line]
        elif recurrence == 1:
            second_elf = [x for x in line]
        elif recurrence == 2:
            recurrence = -1
            this = [x for x in line]
            for char in this:
                if char in second_elf and char in first_elf:
                    sum_of_priorities += priorities.index(char) + 1
                    break

        recurrence += 1
    print("sum:", sum_of_priorities)

part1()
part2()



