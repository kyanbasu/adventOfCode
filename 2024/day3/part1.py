f = open("input.txt").read()

import re

multiplies = re.findall("mul\(\d+,\d+\)", f)

ans = 0

for m in multiplies:
    a,b = list(map(int, m[4:-1].split(',')))
    ans += a*b

print(ans)