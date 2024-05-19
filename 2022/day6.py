f = open("day6-input.txt").read()

i = 0
repeat = True
while repeat:
    a = f[i:i+14] # i+4 for start of packet
    if a == "":
        repeat = False
        break
    curr_chars = []
    done = True
    for char in a:
        if char not in curr_chars:
            curr_chars.append(char)
        else:
            done = False
            break
    if done == True:
        print('start of message answer', i+14) # i+4 for start of packet
        break

    i+=1