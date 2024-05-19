stacks = {"1": ["B", "W", "N"],
          "2": ["L", "Z", "S", "P", "T", "D", "M", "B"],
          "3": ["Q", "H", "Z", "W", "R"],
          "4": ["W", "D", "V", "J", "Z", "R"],
          "5": ["S", "H", "M", "B"],
          "6": ["L", "G", "N", "J", "H", "V", "P", "B"],
          "7": ["J", "Q", "Z", "F", "H", "D", "L", "S"],
          "8": ["W", "S", "F", "J", "G", "Q", "B"],
          "9": ["Z", "W", "M", "S", "C", "D", "J"]}

f = open("day5-input.txt").read().split("splitthis")[1].split("\n")

index = 0
for line in f:
    if len(line) > 5:
        index += 1
        a = b = c = 0
        a = int(line[4:7])
        b = int(line[12:14])
        c = int(line[17:len(line)])
        # move a from b to c
        print(index)
        print("then", stacks[str(b)], a)
        elem = stacks[str(b)][-a:]
        #elem.reverse()   #uncomment for part 1
        del stacks[str(b)][-a:]
        stacks[str(c)] += elem

#part 1 MQSHJMWNH
#part 2 LLWJRBHVZ
for i in stacks:
    print(stacks[i][-1], end="")
