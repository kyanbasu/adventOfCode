from ast import parse


def parse_input(input):
    section1 = []
    section2 = []
    is_section1 = True
    for line in input.split("\n"):
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
            # check before each number to if it is NOT in rules
            for j in range(i):
                if u[i] in rules and u[j] in rules[u[i]]:
                    is_correct_line = False
                    break

            # check after each number to if it is in rules
            for j in range(i+1, len(u)):
                if u[i] in rules and u[j] not in rules[u[i]]:
                    is_correct_line = False
                    break
            else:
                continue

            break
        if is_correct_line:
            ans += int(u[int(len(u)/2)])


    return ans


def part2(_rules, _updates):
    rules = {} # number rules

    def sort_rule(_r):
        _a = True
        if _r in rules:
            for _i in rules[_r]:
                if _r > _i:
                    _a = False
        return _a

    for r in _rules:
        if r[0] not in rules:
            rules[r[0]] = [r[1]]
        else:
            rules[r[0]].append(r[1])

    print(rules)

    ans = 0
    iter = 0
    for u in _updates:
        iter+=1
        is_correct_line = True

        u = u.split(',')

        for i in range(len(u)):
            # check before each number to if it is NOT in rules
            for j in range(i):
                if u[i] in rules and u[j] in rules[u[i]]:
                    is_correct_line = False
                    break

            # check after each number to if it is in rules
            for j in range(i+1, len(u)):
                if u[i] in rules and u[j] not in rules[u[i]]:
                    is_correct_line = False
                    break
            else:
                continue

            break

        if not is_correct_line:
            #sort array or sth
            print(u, iter, is_correct_line)
            ans += int(u[int(len(u) / 2)])


    return ans


if __name__ == "__main__":
    ex = open("example.txt").read()

    es1, es2 = parse_input(ex)
    """
    example1 = part1(es1, es2)
    assert example1 == 143, "example1 should be equal 143, but is " + str(example1)

    s1, s2 = parse_input(open("input.txt").read())

    p1 = part1(s1, s2)
    print(p1)"""

    example2 = part2(es1, es2)
    assert example2 == 123, "example2 should be equal 123, but is " + str(example2)