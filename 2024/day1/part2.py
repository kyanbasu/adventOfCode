f = open("input.txt")

a = []

appearances = {}

for line in f.read().split("\n"):
    line = line.split("   ")
    a.append(int(line[0]))
    if line[1] in appearances:
        appearances[line[1]] += 1
    else:
        appearances[line[1]] = 1

ans = 0

for i in a:
    if str(i) in appearances:
        ans += i * appearances[str(i)]

print(ans)