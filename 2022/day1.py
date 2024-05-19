f = open("./input-day1.txt", "r").read();
list = f.split("\n")
third_fattest_elf = second_fattest_elf = fattest_elf = curr = 0

for i in list:
    if i != "":
        curr += int(i)
    else:
        if curr > fattest_elf:
            third_fattest_elf = second_fattest_elf
            second_fattest_elf = fattest_elf
            fattest_elf = curr
        curr = 0

print(fattest_elf, second_fattest_elf, third_fattest_elf)
print(fattest_elf + second_fattest_elf + third_fattest_elf)