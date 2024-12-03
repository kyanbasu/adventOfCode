f = open("input.txt").read()

import re

multiplies = re.findall("mul\(\d+,\d+\)|do\(\)|don't\(\)", f)

ans = 0
do = True

for m in multiplies:
    if m == "do()":
        do = True
    elif m == "don't()":
        do = False
    elif do:
        a,b = list(map(int, m[4:-1].split(',')))
        ans += a*b

print(ans)