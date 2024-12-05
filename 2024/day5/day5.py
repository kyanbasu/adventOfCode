from functools import cmp_to_key


def parse_input(_in):
    section1 = []
    section2 = []
    is_section1 = True
    for line in _in.split("\n"):
        if line == '':
            if is_section1:
                is_section1 = False
                continue
            else:
                break

        if is_section1:
            section1.append(line.split("|"))
        else:
            section2.append(line)

    return section1, section2


def part1(_rules, _updates):
    rules = {} # number rules
    for r in _rules:
        if r[0] not in rules:
            rules[r[0]] = [r[1]]
        else:
            rules[r[0]].append(r[1])

    ans = 0
    for u in _updates:
        is_correct_line = True
        u = u.split(',')

        for i in range(len(u)):
            for j in range(len(u)):
                if u[i] in rules and (
                        (u[j] in rules[u[i]] and j<i)
                        or
                        (u[j] not in rules[u[i]] and j>i)
                ):
                    is_correct_line = False
                    break
            else:
                continue

            break
        if is_correct_line:
            ans += int(u[int(len(u)/2)])

    return ans


def part2(_in):
    def sorted_by_rules(a, b):
        if f"{b}|{a}" in rules:
            return 1
        else:
            return -1

    rules, updates = _in.split("\n\n")

    updates = updates.split('\n')

    ans = 0
    for u in updates:
        u = u.split(',')

        sorted_u = sorted(u, key=cmp_to_key(sorted_by_rules))

        if sorted_u != u:
            ans += int(sorted_u[int(len(sorted_u) / 2)])

    return ans


if __name__ == "__main__":
    ex = open("example.txt").read()
    _in = open("input.txt").read()

    # Part 1

    es1, es2 = parse_input(ex)

    example1 = part1(es1, es2)
    assert example1 == 143, "example1 should be equal 143, but is " + str(example1)

    s1, s2 = parse_input(_in)

    p1 = part1(s1, s2)
    print("part 1: ", p1)

    # Part 2

    example2 = part2(ex)
    assert example2 == 123, "example2 should be equal 123, but is " + str(example2)

    p2 = part2(_in)
    print("part 2: ", p2)
