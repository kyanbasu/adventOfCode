f = open("input.txt")

safe_reports = 0

for line in f.read().split("\n"):
    increment = 0
    decrement = 0
    nums = list(map(int, line.split(" ")))
    is_safe = True
    bad_level_triggered = False
    increments = []
    for i in range(len(nums)-1):
        _incr = nums[i+1] - nums[i]

        if _incr > 0:
            increment += 1
        elif _incr < 0:
            decrement += 1

        if _incr == 0:
            if bad_level_triggered:
                is_safe = False
                break
            bad_level_triggered = True

        if _incr not in increments:
            increments.append(abs(_incr))

    if is_safe and min(increment, decrement) <= 1:
        increments.sort()

        for i in increments:
            if i > 3:
                is_safe = False
                break

        #print(line, increments, is_safe, bad_level_triggered)

        if is_safe:
            safe_reports += 1



print(safe_reports)



