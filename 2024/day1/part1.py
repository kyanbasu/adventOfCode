f = open("input.txt")

a, b = [], []

for line in f.read().split("\n"):
    line = line.split("   ")
    a.append(int(line[0]))
    b.append(int(line[1]))

a.sort()
b.sort()

dist = 0

for i in range(len(a)):
    dist += abs(a[i] - b[i])

print(dist)