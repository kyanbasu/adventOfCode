f = open("day4.txt", "r").read().split("\n")

total = 0
for line in f:
    a,b = line.split(",")
    aa, ab = a.split("-")
    ba, bb = b.split("-")

    if aa <= ba and ab >= bb:
        total += 1

print("total", total)